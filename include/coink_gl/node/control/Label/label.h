//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/control.h"

class Label :
  public Control
{
 public:
  // main
  Label();
  Label(const std::string& t);
  Label(const NODE_TYPE& t, const std::string& n);
  ~Label() { Free(); }

  // getters
  const std::string& GetText() const { return text; }
  const TEXT_ALIGNMENT& GetHAlignment() const { return h_alignment; }
  const TEXT_ALIGNMENT& GetVAlignment() const { return v_alignment; }

  // setters
  void SetText(const std::string& t) { text = t; }
  void SetHAlignment(const TEXT_ALIGNMENT& a) { h_alignment = a; }
  void SetVAlignment(const TEXT_ALIGNMENT& a) { v_alignment = a; }


 protected:
  // properties
  std::string text;
  TEXT_ALIGNMENT h_alignment;
  TEXT_ALIGNMENT v_alignment;

};
