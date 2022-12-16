//
// Created by Benjamin on 16/12/2022.
//

#include "coink_gl/node/control/panel/panel.h"

Panel::Panel() :
  Control(NODE_PANEL, "panel")
{}

Panel::Panel(const NODE_TYPE& t, const std::string& n) :
  Control(t, n)
{}