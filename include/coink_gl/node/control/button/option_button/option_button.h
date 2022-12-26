//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/button/button.h"

// TODO:
// - replace uint with Item class (with value and text)

class OptionButton :
  public Button
{
  public:
  // main
  OptionButton();
  ~OptionButton() { Free(); };

  // getters
  const std::vector<uint>& GetOptions() const { return options; }
  const uint& GetSelectedOption() const { return options[selected_option]; }
  const int& GetSelectedOptionIndex() const { return selected_option; }

  // setters
  void SetOptions(const std::vector<uint>& o) { options = o; }
  void SetSelectedOptionIndex(const int& i) {
    if (i >= -1 && i < options.size())
      selected_option = i;
  }

  protected:
  // properties
  std::vector<uint> options;
  int selected_option;

  // main
  OptionButton(const NODE_TYPE& t, const std::string& n);
};