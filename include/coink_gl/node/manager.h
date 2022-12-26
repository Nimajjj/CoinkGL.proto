//
//  Created by Benjamin 22/12/2022
//
#pragma once

#include <memory>
#include <vector>

#include "type/type.h"

#include "node/node.h"
#include "node/control/control.h"
#include "node/control/label/label.h"
#include "node/control/tab_bar/tab_bar.h"
#include "node/control/text_edit/text_edit.h"
#include "node/control/button/button.h"
#include "node/control/button/menu_button/menu_button.h"
#include "node/control/button/check_button/check_button.h"
#include "node/control/button/option_button/option_button.h"
#include "node/control/container/container.h"
#include "node/control/container/v_box_container/v_box_container.h"
#include "node/control/container/h_box_container/h_box_container.h"
#include "node/control/panel/panel.h"
#include "node/control/panel/color_panel/color_panel.h"


using NodePtr = std::shared_ptr<Node>;
using ControlPtr = std::shared_ptr<Control>;
using LabelPtr = std::shared_ptr<Label>;
using TabBarPtr = std::shared_ptr<TabBar>;
using TextEditPtr = std::shared_ptr<TextEdit>;
using ButtonPtr = std::shared_ptr<Button>;
using MenuButtonPtr = std::shared_ptr<ButtonPtr>;
using CheckButtonPtr = std::shared_ptr<CheckButton>;
using OptionButtonPtr = std::shared_ptr<OptionButton>;
using ContainerPtr = std::shared_ptr<Container>;
using VBoxContainerPtr = std::shared_ptr<VBoxContainer>;
using HBoxContainerPtr = std::shared_ptr<HBoxContainer>;
using PanelPtr = std::shared_ptr<Panel>;
using ColorPanelPtr = std::shared_ptr<ColorPanel>;


namespace CoinkGL {

namespace {
  void LinkNodes(const NodePtr& parent, const NodePtr& child) {
    child->SetParent(parent);
    parent->AddChild(child);
  }
}

// scene management
size_t LoadScene(const NodePtr& node);
size_t PreloadScene(const NodePtr& node);
void UnloadScene(const size_t& scene);


// nodes constructor
template <typename T>
[[nodiscard]]
std::shared_ptr<T> NewNode(const NodePtr& parent) {
  if (!std::is_base_of<Node, T>::value) {
    Utils::ErrorLog("Cannot create node with the given type");
    return nullptr;
  }

  auto node = std::make_shared<T>();

  if (parent != nullptr)
    LinkNodes(parent, node);

  return node;
}

// nodes management
void QueueFree(const NodePtr& node);

// getters
const NodePtr& GetCurrentScene();


}
