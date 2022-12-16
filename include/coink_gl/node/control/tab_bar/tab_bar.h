//
// Created by Benjamin on 16/12/2022.
//

#pragma once

#include "node/control/control.h"

class TabBar :
  public Control
{
  public:
    // main
    TabBar();
    ~TabBar() { Free(); }

    // getters
    const std::string& GetTitle() const { return title; }

    // setters
    void SetTitle(const std::string& t) { title = t; }

  protected:
    // properties
    std::string title;
};