//
// Created by Benjamin on 13/12/2022.
//

#pragma once

#include "shape/shape.h"

class Triangle : public Shape {
 public:
  Vec2 aPos;
  Vec2 bPos;
  Vec2 cPos;

  Triangle() :
    Shape(SHAPE_TRIANGLE),
    aPos(Vec2()),
    bPos(Vec2()),
    cPos(Vec2())
  {
    SetVertexCount(3);
  }

  Triangle(Vec2 a, Vec2 b, Vec2 c) :
    Shape(SHAPE_TRIANGLE),
    aPos(a),
    bPos(b),
    cPos(c)
  {
    SetVertexCount(3);
  }

  Triangle(Vec2 a, Vec2 b, Vec2 c, const Color& col) :
    Shape(SHAPE_TRIANGLE),
    aPos(a),
    bPos(b),
    cPos(c)
  {
    SetVertexCount(3);
    SetColor(col);
  }

  ~Triangle() = default;

  void Info() override {
    std::cout << "type : SHAPE_TRIANGLE\n";
    std::cout << "aPos : (" << aPos.x << ", " << aPos.y << ")\n" <<
              "bPos : (" << bPos.x << ", " << bPos.y << ")\n" <<
              "cPos : (" << cPos.x << ", " << cPos.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};

