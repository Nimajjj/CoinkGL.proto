#include <iostream>
#include <stdio.h>
#include <time.h>

#include "coink_gl.h"


const Size SCR_SIZE = {1920, 1080};
const std::string SCR_TITLE = "CoinkGL.engine [prototype] 0.0.2";


int main() {
  Utils::DisableLog();
  CoinkGL::Init(SCR_SIZE, SCR_TITLE);

  // new triangles with random color every 32x32 pixels
  for (int i = 0; i < SCR_SIZE.x; i += 32) {
    for (int j = 0; j < SCR_SIZE.y; j += 32) {
      Renderer::NewTriangle(
        Point(i, j),
        Point(i + 32, j),
        Point(i + 16, j + 32),
        Color(rand() % 255, rand() % 255, rand() % 255)
      );
    }
  }

  Renderer::Update();

  while (CoinkGL::ShouldNotClose()) {
    CoinkGL::BeginLoop();

    Renderer::Render();

    CoinkGL::EndLoop();
  }

  CoinkGL::Terminate();
  return 0;
}
