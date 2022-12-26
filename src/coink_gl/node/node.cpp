//
// Created by Benjamin on 15/12/2022.
//

#include "node/node.h"

// main
Node::Node() :
  ID(Duck::New()),
  node_type(NODE_NODE),
  node_name("Node_" + std::to_string(ID)),
  need_update(true),
  position(Point(0,0)),
  size(Size(0,0)),
  rotation(0),
  scale(Size(1,1)),
  visible(true),
  modulate(COLOR_WHITE),
  self_modulate(COLOR_WHITE),
  parent(nullptr)
{}

Node::Node(const NODE_TYPE& t, const std::string& n) :
  ID(Duck::New()),
  node_type(t),
  node_name(n + "_" + std::to_string(ID)),
  need_update(true),
  position(Point(0,0)),
  size(Size(0,0)),
  rotation(0),
  scale(Size(1,1)),
  visible(true),
  modulate(COLOR_WHITE),
  self_modulate(COLOR_WHITE),
  parent(nullptr)
{}

void
Node::Free() {
  if (parent != nullptr)
    parent->RemoveChild(ThisPtr());

  FreeChildren();
}

void
Node::FreeChildren() {
  for (auto& child : children) {
    child->Free();
  }
}

// setters: family
void
Node::SetParent(NodePtr p_parent) {
  if (parent != nullptr)
    parent->RemoveChild(ThisPtr());

  parent = p_parent;
}

void
Node::RemoveParent() {
  if (parent != nullptr)
    parent->RemoveChild(ThisPtr());

  parent = nullptr;
}

void
Node::AddChild(NodePtr p_child) {
  if (std::count(children.begin(), children.end(), p_child)) {
    Utils::Log(
        WARN,
        "Node [" + std::to_string(ID) + "] already has child with ID: [" + std::to_string(p_child->ID) + "]"
      );
    return;
  }

  children.push_back(p_child);
}

void
Node::RemoveChild(NodePtr p_child) {
  if (!std::count(children.begin(), children.end(), p_child)) {
    Utils::Log(
        WARN,
        "Node [" + std::to_string(ID) + "] does not have child with ID: [" + std::to_string(p_child->ID) + "]"
      );
    return;
  }

  children.erase(std::remove(children.begin(), children.end(), p_child), children.end());
}


void Node::DebugInfo(const int& level) const {
  std::cout << "Node ID[" << ID << "]:\n"
            << "  Name: " << node_name << "\n"
            << "  Type: " << node_type << "\n"
            << "  Position: " << position << "\n"
            << "  Visible: " << visible << "\n";

  if (parent != nullptr)
    std::cout << "  Parent: " << parent->node_name << " [" << parent->ID << "]\n";

  std::cout << "  Children count: " << children.size() << "\n";

  if (level >= 1) {
    std::cout << "  Size: " << size << "\n"
              << "  Rotation: " << rotation << "\n"
              << "  Scale: " << scale << "\n"
              << "  Modulate: " << modulate << "\n"
              << "  Self Modulate: " << self_modulate << "\n";
  }

  if (level >= 2) {
    if (children.size() == 0)
      return;

    std::cout << "  Children: \n";

    uint count = 1;
    for (const auto& child : children) {
      std::cout << "Child " << count++ << " ///////////////\n";
      child->DebugInfo(1);
    }
  }
}
