//
// Created by Benjamin on 11/12/2022.
//
#pragma once

struct Vec3 {
  double x, y, z;

  Vec3() : x(0.0), y(0.0), z(0.0) {};
  Vec3(const double& x, const double& y, const double& z) : x(x), y(y), z(z) {}
};
