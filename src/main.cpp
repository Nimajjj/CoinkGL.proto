#include <iostream>
#include <stdio.h>
#include <time.h>

#include "coink_gl.h"


const Size SCR_SIZE = {1920, 1080};
const std::string SCR_TITLE = "CoinkGL.engine [prototype] 0.0.2";


int main() {
  CoinkGL::Init(SCR_SIZE, SCR_TITLE);

  while (CoinkGL::ShouldNotClose()) {
    CoinkGL::BeginLoop();

    CoinkGL::EndLoop();
  }

  CoinkGL::Terminate();
  return 0;
}
