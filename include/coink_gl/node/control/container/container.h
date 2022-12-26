//
// Created by Benjamin on 19/12/2022.
//

#pragma once

#include "node/control/control.h"

class Container :
  public Control
{
  public:
  // main
  ~Container() { Free(); };

 protected:
  // properties

  // main
  Container() :
    Control(NODE_CONTAINER, "Container")
  {};

  Container(const NODE_TYPE &t, const std::string &n) :
    Control(t, n)
  {};
};