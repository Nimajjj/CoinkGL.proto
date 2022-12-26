#include "coink_gl.h"
#include "coink_gl/node/manager.h"
#include "utils/utils.h"


const Size SCR_SIZE = {1920, 1080};
const std::string SCR_TITLE = "CoinkGL.engine [prototype]";


int main() {
  Utils::EnableDebugLog();
  CoinkGL::Init(SCR_SIZE, SCR_TITLE);

  auto n1 = CoinkGL::NewNode<Node>(nullptr);
  auto n2 = CoinkGL::NewNode<Label>(n1);
  
  n1->SetSize({400, 400});
  n1->SetPosition({300,300});

  n2->SetSize({100, 100});
  n2->SetPosition({700,700});


  CoinkGL::LoadScene(n1);

  while (CoinkGL::ShouldNotClose()) {

  }

  CoinkGL::Terminate();
  return 0;
}
