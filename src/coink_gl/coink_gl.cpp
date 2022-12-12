//
// Created by Benjamin on 10/12/2022.
//
#include "coink_gl.h"

namespace CoinkGL {

// STATIC DECLARATION ----------
static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
static int InitGlfw(const std::string& p_title);
static int InitGlad();


// VARIABLES ----------
GLFWwindow* window = nullptr;
Size screen_size = Size();


// MAIN ----------
void Init(const Size& scr_size, const std::string& title) {
  Utils::Log(Utils::INFO, "Initalizing CoinkGL ...");

  screen_size = scr_size;

  if (InitGlfw(title) != 0) return;
  if (InitGlad() != 0) return;

  Shader::SetShadersDirectory("D:/development/prototypes/CoinkGL.engine.2/ressource/shader/");

  Renderer::Init(screen_size);

  Utils::Log(Utils::INFO, "CoinkGL initialisation OK");
}

void Terminate() {
  Utils::Log(Utils::INFO, "Closing CoinkGL ...");

  Renderer::Close();
  glfwTerminate();

  Utils::Log(Utils::INFO, "Closing CoinkGL OK");
}


// LOOP ----------
bool ShouldNotClose() {
  return !glfwWindowShouldClose(window);
}

void BeginLoop() {
  glClearColor(0.157, 0.157, 0.157, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void EndLoop() {
  // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
  glfwSwapBuffers(window);
  glfwPollEvents();
}


// STATIC ----------
// glfw: whenever the window size changed (by OS or user resize) this callback function executes
static void FramebufferSizeCallback(GLFWwindow* w, int width, int height) {
  // make sure the viewport matches the new window dimensions; note that width and
  // height will be significantly larger than specified on retina displays.
  glViewport(0, 0, width, height);
  screen_size = Size(width, height);
}

static int InitGlfw(const std::string& p_title) {
  // glfw: initialize and configure
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // glfw window creation
  window = glfwCreateWindow(screen_size.x, screen_size.y, p_title.c_str(),
                            NULL, NULL);
  if (window == NULL) {
    Utils::Log(Utils::FATAL, "GLFW failed to initialize window");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

  Utils::Log(Utils::INFO, "GLFW window initialization OK");
  return 0;
}

static int InitGlad() {
  // glad: load all OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    Utils::Log(Utils::FATAL, "GLAD failed to initialize");
    return -1;
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Utils::Log(Utils::INFO, "GLAD initialization OK");
  return 0;
}

void DebugQuitOnFirstLoop() {
  glfwSetWindowShouldClose(window, true);
}

}