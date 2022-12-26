//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/button/button.h"

class CheckButton :
  public Button
{
 public:
  // main
  CheckButton() :
    Button(NODE_CHECK_BUTTON, "check_button"),
    checked(false),
    alignment(TEXT_ALIGN_RIGHT)
  {}
  ~CheckButton() { Free(); };

  // getters
  const bool& IsChecked() const { return checked; }
  const TEXT_ALIGNMENT& GetAlignment() const { return alignment; }

  // setters
  void SetChecked(const bool& c) { checked = c; }
  void Toggle() { checked = !checked; }
  void SetAlignment(const TEXT_ALIGNMENT& a) { alignment = a; }

 protected:
  // properties
  bool checked;
  TEXT_ALIGNMENT alignment;

  // main
  CheckButton(const NODE_TYPE &t, const std::string &n) :
    Button(t, n),
    checked(false),
    alignment(TEXT_ALIGN_RIGHT)
  {}
};