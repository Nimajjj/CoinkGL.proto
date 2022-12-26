//
// Created by Benjamin on 16/12/2022.
//

#include "coink_gl/node/control/button/button.h"


Button::Button() :
  Control(NODE_BUTTON, "button"),
  text(""),
  alignment(TEXT_ALIGN_LEFT),
  disabled(false),
  toggle_mode(false),
  pressed(false),
  action_mode(BUTTON_RELEASED),
  action(nullptr)
{}

Button::Button(const NODE_TYPE &t, const std::string &n) :
  Control(t, n),
  text(""),
  alignment(TEXT_ALIGN_LEFT),
  disabled(false),
  toggle_mode(false),
  pressed(false),
  action_mode(BUTTON_RELEASED),
  action(nullptr)
{}