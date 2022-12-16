//
// Created by Benjamin on 16/12/2022.
//

#include "theme/theme.h"

Theme::Theme(const std::string& name) :
  ID(Duck::New()),
  theme_name(name),
  font_size(16),
  font_size_h1(24),
  font_size_h2(20),
  text_color(Color(0xfb, 0xfb, 0xfb)),
  highlight_color(Color(0xfa, 0xbd, 0x2d)),
  bg_color_1(Color(0x32, 0x02, 0x2f)),
  bg_color_2(Color(0x28, 0x28, 0x28)),
  border_color_1(Color(0xa8, 0x99, 0x84)),
  border_color_2(Color(0x92, 0x83, 0x74))
{}

