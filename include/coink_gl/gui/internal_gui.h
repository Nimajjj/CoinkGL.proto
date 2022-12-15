//
// Created by Benjamin on 14/12/2022.
//

#pragma once

#include "renderer/internal_renderer.h"

class InternalGui {
 public:
  InternalGui(const Size& scr_size);
  ~InternalGui() = default;

 private:
  Size screen_size;

  std::unique_ptr<InternalRenderer> internal_renderer;

};


