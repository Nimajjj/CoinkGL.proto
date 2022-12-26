//
// Created by Benjamin on 10/12/2022.
//
#include "coink_gl.h"
#include "node/internal_node_renderer.h"

namespace CoinkGL {

// STATIC DECLARATION ----------
static void FramebufferSizeCallback(GLFWwindow* window, int width, int height);
static int InitGlfw(const std::string& p_title);
static int InitGlad();

static Color CLEAR_COLOR_NORMALISED = COLOR_CLEAR.Normalized();


// VARIABLES ----------
GLFWwindow* window = nullptr;
Size screen_size = Size();


// MAIN ----------
void Init(const Size& scr_size, const std::string& title) {
  Utils::Log(INFO, "Initalizing CoinkGL ...");

  screen_size = scr_size;

  if (InitGlfw(title) != 0) return;
  if (InitGlad() != 0) return;

  Shader::SetShadersDirectory("D:/development/prototypes/CoinkGL.engine.2/ressource/shader/");

  InternalNodeRenderer::Init(screen_size);

  Utils::Log(INFO, "CoinkGL initialisation OK");
}

void Terminate() {
  Utils::Log(INFO, "Closing CoinkGL ...");

  glfwTerminate();

  Utils::Log(INFO, "Closing CoinkGL OK");
}


// LOOP ----------
bool ShouldNotClose() {
  // loop action
  InternalNodeRenderer::RenderCurrentScene();

  // end loop
  glfwSwapBuffers(window);
  glfwPollEvents();

  // begin loop
  glClearColor(
    CLEAR_COLOR_NORMALISED.r,
    CLEAR_COLOR_NORMALISED.g,
    CLEAR_COLOR_NORMALISED.b,
    1.0
    );
  glClear(GL_COLOR_BUFFER_BIT);

  return !glfwWindowShouldClose(window);
}

void BeginLoop() {
  glClearColor(
    CLEAR_COLOR_NORMALISED.r,
    CLEAR_COLOR_NORMALISED.g,
    CLEAR_COLOR_NORMALISED.b,
    1.0
    );
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
    Utils::Log(FATAL, "GLFW failed to initialize window");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

  Utils::Log(INFO, "GLFW window initialization OK");
  return 0;
}

static int InitGlad() {
  // glad: load all OpenGL function pointers
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    Utils::Log(FATAL, "GLAD failed to initialize");
    return -1;
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Utils::Log(INFO, "GLAD initialization OK");
  return 0;
}

void DebugQuitOnFirstLoop() {
  glfwSetWindowShouldClose(window, true);
}

}
