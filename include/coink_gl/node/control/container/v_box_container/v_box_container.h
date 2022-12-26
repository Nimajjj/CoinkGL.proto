//
// Created by Benjamin on 19/12/2022.
//

#pragma once

#include "node/control/container/container.h"

class VBoxContainer :
  public Container
{
 public:
  // main
  VBoxContainer() :
    Container(NODE_HBOX_CONTAINER, "VBoxContainer"),
    alignment(BCE_ALIGN_BEGIN),
    spacing(0)
  {};

  ~VBoxContainer() { Free(); };

  // getters
  const BCE_ALIGNMENT &GetAlignment() const { return alignment; }
  const uint &GetSpacing() const { return spacing; }

  // setters
  void SetAlignment(const BCE_ALIGNMENT &a) { alignment = a; }
  void SetSpacing(const uint &s) { spacing = s; }


 protected:
  // properties
  BCE_ALIGNMENT alignment;
  uint spacing;

  // main
  VBoxContainer(const NODE_TYPE &t, const std::string &n) :
    Container(t, n),
    alignment(BCE_ALIGN_BEGIN),
    spacing(0)
  {};
};