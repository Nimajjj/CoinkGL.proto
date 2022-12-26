//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/button/button.h"

class MenuButton :
  public Button
{
 public:
  // main
  MenuButton() :
    Button(NODE_MENU_BUTTON, "menu_button"),
    items(),
    alignment(TEXT_ALIGN_CENTER)
  {}

  ~MenuButton() { Free(); };

  // getters
  const std::vector<ButtonPtr>& GetItems() const { return items; }
  const TEXT_ALIGNMENT& GetAlignment() const { return alignment; }

  // setters
  void SetItems(const std::vector<ButtonPtr>& i) { items = i; }
  void SetAlignment(const TEXT_ALIGNMENT& a) { alignment = a; }


 protected:
  // properties
  std::vector<ButtonPtr> items;
  TEXT_ALIGNMENT alignment;

  // main
  MenuButton(const NODE_TYPE& t, const std::string& n) :
    Button(t, n),
    items(),
    alignment(TEXT_ALIGN_CENTER)
  {}

};