#include <engine/game.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0, 0, width, height);
}

void Game::Init(GLFWwindow *win){
    G_SINGLETON_gl = new SINGLETON_GL();
    G_SINGLETON_gl->set(win);

    Shader* shd = new Shader(vertexShaderSrc, fragmentShaderSrc);
    
    G_SINGLETON_system = new System();
    G_SINGLETON_system->set_shader(shd);
    G_SINGLETON_system->change_screen(WORLD, "MAIN");
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

    // PROJECTION MATRIX CAMERA
    float left = -10.0f;
    float right = 10.0f;
    float bottom = -10.0f;
    float top = 10.0f;
    float nearZ = -1.0f;
    float farZ = 1.0f;

    float projection[16] = {
        2.0f / (right - left), 0, 0, 0,
        0, 2.0f / (top - bottom), 0, 0,
        0, 0, -2.0f / (farZ - nearZ), 0,
        -(right + left) / (right - left),
        -(top + bottom) / (top - bottom),
        -(farZ + nearZ) / (farZ - nearZ),
        1.0f
    };

    this->Init(window);

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