//
// Created by Benjamin on 14/12/2022.
//

#include "coink_gl/gui/internal_gui.h"

InternalGui::InternalGui(const Size& scr_size) :
  screen_size(scr_size),
  internal_renderer(std::make_unique<InternalRenderer>(scr_size))
{}

