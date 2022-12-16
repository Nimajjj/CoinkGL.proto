//
// Created by Benjamin on 16/12/2022.
//

#include "coink_gl/node/control/Label/label.h"

Label::Label() :
  Control(NODE_LABEL, "Label"),
  text(""),
  h_alignment(TEXT_ALIGN_LEFT),
  v_alignment(TEXT_ALIGN_TOP)
{}

Label::Label(const std::string& t) :
  Control(NODE_LABEL, "Label"),
  text(t),
  h_alignment(TEXT_ALIGN_LEFT),
  v_alignment(TEXT_ALIGN_TOP)
{}

Label::Label(const NODE_TYPE& t, const std::string& n) :
  Control(t, n),
  text(""),
  h_alignment(TEXT_ALIGN_LEFT),
  v_alignment(TEXT_ALIGN_TOP)
{}