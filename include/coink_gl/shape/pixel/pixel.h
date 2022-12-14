//
// Created by Benjamin on 13/12/2022.
//
#pragma once

#include "coink_gl/shape/rect/rect.h"
#include "type/type.h"
#include "glad/glad.h"
#include <iostream>

class Pixel : public Rect {
 public:
  Pixel() :
    Rect(Vec2(), Vec2(1,1))
  {
    this->type = SHAPE_PIXEL;
  SetVertexCount(1);
  }

  Pixel(const Vec2& pos) :
    Rect(pos, Vec2(1,1))
  {
    this->type = SHAPE_PIXEL;
    SetVertexCount(1);
  }

  Pixel(const Vec2& pos, const Color& col) :
    Rect(pos, Vec2(1,1), col)
  {
    this->type = SHAPE_PIXEL;
    SetVertexCount(1);
  }

  ~Pixel() = default;

  void Info() override {
    std::cout << "type : SHAPE_PIXEL\n";
    std::cout << "position : (" << position.x << ", " << position.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};

