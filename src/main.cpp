#include <iostream>
#include <stdio.h>
#include <time.h>

#include "coink_gl.h"

#include "node/node.h"
#include "theme/theme.h"


const Size SCR_SIZE = {1920, 1080};
const std::string SCR_TITLE = "CoinkGL.engine [prototype] 0.0.2";


int main() {
  CoinkGL::Init(SCR_SIZE, SCR_TITLE);

  Theme theme = Theme::New("default");

  NodePtr root = std::make_shared<Node>();
  root->SetName("root");

  NodePtr child = std::make_shared<Node>();
  child->SetName("child 1");
  root->AddChild(child);
  child->SetParent(root);

  NodePtr child2 = std::make_shared<Node>();
  child2->SetName("child 2");
  root->AddChild(child2);
  child2->SetParent(root);

  NodePtr child3 = std::make_shared<Node>();
  child3->SetName("child 3");
  root->AddChild(child3);
  child3->SetParent(root);

  root->DebugInfo(2);

  while (CoinkGL::ShouldNotClose()) {
    CoinkGL::BeginLoop();

    CoinkGL::EndLoop();
  }

  CoinkGL::Terminate();
  return 0;
}
