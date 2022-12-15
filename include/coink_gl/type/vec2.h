//
// Created by Benjamin on 10/12/2022.
//
#pragma once

#include <iostream>

struct Vec2 {
  double x, y;

  Vec2() : x(0.0), y(0.0) {};
  Vec2(const double& x, const double& y) : x(x), y(y) {}

  friend std::ostream& operator<<(std::ostream& os, const Vec2& vec) {
    os << "Vec2(" << vec.x << ", " << vec.y << ")";
    return os;
  }
};
