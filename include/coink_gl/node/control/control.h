//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/node.h"
#include "theme/theme.h"

class Control :
  public Node {
 public:
  // main
  Control();

  ~Control() { Free(); }

  // getters
  const ThemePtr &GetTheme() const { return p_theme; }

  // setters
  void SetTheme(const ThemePtr &t) { p_theme = t; }

 protected:
  // properties
  ThemePtr p_theme;

  // main
  Control(const NODE_TYPE &t, const std::string &n);
};
