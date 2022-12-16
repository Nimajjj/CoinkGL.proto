//
// Created by Benjamin on 16/12/2022.
//

#include "coink_gl/node/control/control.h"

Control::Control() :
  Node(NODE_CONTROLE, "Control"),
  p_theme(std::make_shared<Theme>("default"))
{}

Control::Control(const NODE_TYPE& t, const std::string& n) :
  Node(t, n),
  p_theme(std::make_shared<Theme>("default"))
{}