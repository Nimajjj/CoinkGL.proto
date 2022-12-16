//
// Created by Benjamin on 16/12/2022.
//

#include "coink_gl/node/control/text_edit/text_edit.h"

TextEdit::TextEdit() :
  Control(NODE_TEXT_EDIT, "text_edit"),
  text(""),
  place_holder(""),
  editable(true)
{}

TextEdit::TextEdit(const NODE_TYPE& t, const std::string& n) :
  Control(t, n),
  text(""),
  place_holder(""),
  editable(true)
{}