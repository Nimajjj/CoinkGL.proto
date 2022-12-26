//
// Created by Benjamin on 16/12/2022.
//

#include "node/control/button/option_button/option_button.h"

OptionButton::OptionButton() :
  Button(NODE_OPTION_BUTTON, "option_button"),
  options(),
  selected_option(-1)
{}

OptionButton::OptionButton(const NODE_TYPE &t, const std::string &n) :
  Button(t, n),
  options(),
  selected_option(-1)
{}