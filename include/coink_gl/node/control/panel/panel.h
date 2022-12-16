//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/control.h"

// Panel class can't be instantiated
// see ColorPanel and / or TexturePanel for panels usage
class Panel :
  public Control
{
 protected:
  // main
  Panel();
  Panel(const NODE_TYPE& t, const std::string& n);
  ~Panel() { Free(); }
};
