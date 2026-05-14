#include <engine/game.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void Game::Init(GLFWwindow *win){
    G_SINGLETON_gl = new SINGLETON_GL();
    G_SINGLETON_gl->set(win);
   
    RTW = new RT_World();
    RTW->Init(MAIN);
   
    RT_Gui* RTG = new RT_Gui();
    
    this->set_type(WORLD);
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

    window = glfwCreateWindow(800, 600, "Misowa", NULL, NULL);
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

    while (!glfwWindowShouldClose(window)){
        G_SINGLETON_gl->set(window);
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT);

        // just need to share everythin we need
        
        if(this->get_type() == WORLD){
            RTW->Start();
        }else{
            // RTG->Start();
        }

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}

enum GameType Game::get_type(){
    return this->type;
}

void Game::set_type(enum GameType value){
    this->type = value;
}