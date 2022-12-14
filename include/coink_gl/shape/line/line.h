//
// Created by Benjamin on 13/12/2022.
//

#pragma once

#include "coink_gl/shape/shape.h"

class Line : public Shape {
 public:
  Vec2 pos1;
  Vec2 pos2;
  uint line_width;

  Line() :
    Shape(SHAPE_LINE),
    pos1(Vec2()),
    pos2(Vec2()),
    line_width(1)
  {
    SetVertexCount(2);
  }

  Line(const Vec2& pos1, const Vec2& pos2, const uint& w = 1) :
    Shape(SHAPE_LINE),
    pos1(pos1),
    pos2(pos2),
    line_width(w)
  {
    SetVertexCount(2);
  }

  Line(const Vec2& pos1, const Vec2& pos2, const Color& col, const uint& w = 1) :
    Shape(SHAPE_LINE, col),
    pos1(pos1),
    pos2(pos2),
    line_width(w)
  {
    SetVertexCount(2);
  }

  ~Line() = default;

  void Info() override {
    std::cout << "type : SHAPE_LINE\n";
    std::cout << "position 1 : (" << pos1.x << ", " << pos1.y << ")\n" <<
              "position 2 : (" << pos2.x << ", " << pos2.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};

