//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include <functional>

#include "node/control/control.h"

class Button:
    public Control
{
 public:
  // main
  Button();
  ~Button() { Free(); };

  void Action() {
    if (action)
      action();
  }

  // getters
  const std::string& GetText() const { return text; }
  const TEXT_ALIGNMENT& GetAlignment() const { return alignment; }
  const bool& IsDisabled() const { return disabled; }
  const bool& IsToggleMode() const { return toggle_mode; }
  const bool& IsPressed() const { return pressed; }
  const BUTTON_ACTION_MODE& GetActionMode() const { return action_mode; }

  // setters
  void SetText(const std::string& t) { text = t; }
  void SetAlignment(const TEXT_ALIGNMENT& a) { alignment = a; }
  void SetDisabled(const bool& d) { disabled = d; }
  void SetToggleMode(const bool& t) { toggle_mode = t; }
  void SetPressed(const bool& p) { pressed = p; }
  void SetActionMode(const BUTTON_ACTION_MODE& a) { action_mode = a; }
  void SetAction(const std::function<void()>& a) { action = a; }

 protected:
  // properties
  std::string text;
  TEXT_ALIGNMENT alignment;
  bool disabled;
  bool toggle_mode;
  bool pressed;
  BUTTON_ACTION_MODE action_mode;
  std::function<void()> action;

  // main
  Button(const NODE_TYPE& t, const std::string& n);

};
