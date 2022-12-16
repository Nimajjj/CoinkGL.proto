#include <iostream>
#include <stdio.h>
#include <time.h>

#include "coink_gl.h"

#include "node/control/label/label.h"
#include "theme/theme.h"


const Size SCR_SIZE = {1920, 1080};
const std::string SCR_TITLE = "CoinkGL.engine [prototype] 0.0.2";


int main() {
  CoinkGL::Init(SCR_SIZE, SCR_TITLE);

  auto root = std::make_shared<Node>();

  auto control = std::make_shared<Control>();

  auto label = std::make_shared<Label>("Hello World!");
  label->SetPosition(Point(SCR_SIZE.x / 2, SCR_SIZE.y / 2));

  control->AddChild(label);
  root->AddChild(control);
  label->SetParent(control);
  control->SetParent(root);

  root->DebugInfo();
  control->DebugInfo();
  label->DebugInfo();


  while (CoinkGL::ShouldNotClose()) {
    CoinkGL::BeginLoop();

    CoinkGL::EndLoop();
  }

  CoinkGL::Terminate();
  return 0;
}
