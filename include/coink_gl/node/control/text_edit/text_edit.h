//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/control.h"

class TextEdit :
  public Control {
 public:
  // main
  TextEdit();

  ~TextEdit() { Free(); }

  // getters
  const std::string &GetText() const { return text; }

  // setters
  void SetText(const std::string &t) { text = t; }

 protected:
  // properties
  std::string text;
  std::string place_holder;
  bool editable;

  // main
  TextEdit(const NODE_TYPE &t, const std::string &n);

};
