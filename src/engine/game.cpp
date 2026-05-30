#include <engine/game.h>
#include <namespace/file.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}

void Game::Init(GLFWwindow *win){
    G_SINGLETON_gl = new SINGLETON_GL();
    G_SINGLETON_gl->set(win);

    G_SINGLETON_action = new SINGLETON_action();

    Shader* shd = new Shader(vertexShaderSrc, fragmentShaderSrc);
    
    shd->use();

    G_SINGLETON_system = new System();
    G_SINGLETON_system->set_shader(shd);
    G_SINGLETON_system->change_screen(WORLD, "MAIN");

    G_SINGLETON_player = new SINGLETON_player();

    G_SINGLETON_cache = new SINGLETON_cache();
}

void Game::Start(){
    if (!glfwInit()){
        std::cout << "GLFW init failed\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;

    window = glfwCreateWindow(APP_WIDTH, APP_HEITGH, APP_NAME, NULL, NULL);
    if (!window)
    {
        std::cout << "FAILED CREATE WINDOW\n";
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to init GLAD\n";
        return;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    std::cout << "OpenGL Init Success!\n";
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << "\n";
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << "\n";
    std::cout << "Version: " << glGetString(GL_VERSION) << "\n";

    this->Init(window);

    std::vector<std::pair<std::string, std::variant<int, float, std::string>>> gtk = file::read_whole_file("player.json");
    // for(int i = 0;i < gtk.size();i++){
    //     std::cout << "YAP : " << gtk[i].first << std::endl;
    // }

    while (!glfwWindowShouldClose(window)){        
        G_SINGLETON_gl->set(window);
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        
        if(*G_SINGLETON_system->get_render_type() == WORLD){
            RTW->Start();
        }else{
            // RTG->Start();
        }

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}