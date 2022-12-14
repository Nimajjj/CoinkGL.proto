//
// Created by Benjamin on 13/12/2022.
//

#pragma once

#include "type/type.h"
#include "coink_gl/shape/shape.h"
#include "glad/glad.h"
#include <iostream>

class Rect : public Shape {
 public:
  Vec2 position;
  Vec2 size;

  Rect() :
    Shape(SHAPE_RECT),
    position(Vec2()),
    size(Vec2())
  {
    SetVertexCount(8);
  }

  Rect(const Vec2& pos, const Vec2& sz) :
    Shape(SHAPE_RECT),
    position(pos),
    size(sz)
  {
    SetVertexCount(8);
  }

  Rect(const Vec2& pos, const Vec2& sz, const Color& col) :
    Shape(SHAPE_RECT, col),
    position(pos),
    size(sz)
  {
    SetVertexCount(8);
  }

  ~Rect() = default;

  void Info() override {
    std::cout << "type : SHAPE_RECT\n";
    std::cout << "position : (" << position.x << ", " << position.y << ")\n" <<
              "size : (" << size.x << ", " << size.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};
