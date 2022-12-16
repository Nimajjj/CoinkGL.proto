//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/panel/panel.h"


class ColorPanel :
  public Panel
{
  public:
  // main
  ColorPanel();
  ~ColorPanel() { Control::Free(); }

    // getters
    const Color& GetColor() const { return color; }

    // setters
    void SetColor(const Color& c) { color = c; }

  protected:
    // properties
    Color color;
};
