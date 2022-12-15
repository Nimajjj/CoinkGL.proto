//
// Created by Benjamin on 10/12/2022.
//
#pragma once

struct Color {
  double r, g, b, a;

  Color() : r(0.0), g(0.0), b(0.0), a(0xFF) {};
  Color(const double& p_r, const double& p_g, const double& p_b, const double& p_a = 0xFF) : r(p_r), g(p_g), b(p_b), a(p_a) {}

  friend std::ostream& operator<<(std::ostream& os, const Color& col) {
    os << "Color(" << col.r << ", " << col.g << ", " << col.b << ", " << col.a << ")";
    return os;
  }
};


const Color COLOR_WHITE = Color(0xFF, 0xFF, 0xFF);
const Color COLOR_BLACK = Color(0x00, 0x00, 0x00);
const Color COLOR_RED = Color(0xFF, 0x00, 0x00);
const Color COLOR_GREEN = Color(0x00, 0xFF, 0x00);
const Color COLOR_BLUE = Color(0x00, 0x00, 0xFF);
const Color COLOR_YELLOW = Color(0xFF, 0xFF, 0x00);
const Color COLOR_MAGENTA = Color(0xFF, 0x00, 0xFF);
const Color COLOR_CYAN = Color(0x00, 0xFF, 0xFF);


