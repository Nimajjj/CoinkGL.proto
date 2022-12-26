//
// Created by Benjamin on 15/12/2022.
//

#pragma once

#include <memory>
#include <string>
#include <vector>

#include "type/duck.h"
#include "type/type.h"
#include "utils/utils.h"


class Node :
  public std::enable_shared_from_this<Node> {
 public:
  using NodePtr = std::shared_ptr<Node>;

  // properties
  const DUCK ID;
  const NODE_TYPE node_type;

  // main
  Node();

  ~Node() { Free(); }


  // setters
  // properties
  void SetName(const std::string &name) { node_name = name; }

  void SetNeedUpdate(const bool &update = true) { need_update = update; }

  void SetPosition(const Point &pos) { position = pos; SetNeedUpdate(); }

  void SetSize(const Size &sz) { size = sz;  SetNeedUpdate(); }

  void SetRotation(const float &rot) { rotation = rot; SetNeedUpdate(); }

  void SetScale(const float &scl) { scale = Size(scl, scl); SetNeedUpdate(); }

  void SetVisible(const bool &vis) { visible = vis; SetNeedUpdate(); }

  void SetModulate(const Color &col) { modulate = col; SetNeedUpdate(); }

  void SetSelfModulate(const Color &col) { self_modulate = col; SetNeedUpdate(); }

  // family
  void SetParent(NodePtr p_parent);

  void RemoveParent();

  void AddChild(NodePtr p_child);

  void RemoveChild(NodePtr p_child);


  // getters
  // properties
  const DUCK &GetID() const { return ID; }

  const std::string &GetName() const { return node_name; }

  const bool &NeedUpdate() const { return need_update; }

  const Point &GetPosition() const { return position; }

  const Size &GetSize() const { return size; }

  const float &GetRotation() const { return rotation; }

  const Size &GetScale() const { return scale; }

  const bool &GetVisible() const { return visible; }

  const Color &GetModulate() const { return modulate; }

  const Color &GetSelfModulate() const { return self_modulate; }

  // family
  const NodePtr &GetParent() const { return parent; }

  const std::vector<NodePtr> &GetChildren() const { return children; }


  // actions


  // debug
  void DebugInfo(const int &level = 0) const;


 protected:
  // properties
  std::string node_name;
  bool need_update;
  Point position;
  Size size;
  float rotation;
  Size scale;
  bool visible;
  Color modulate;
  Color self_modulate;

  // family
  NodePtr parent;
  std::vector<NodePtr> children;


  // main
  Node(const NODE_TYPE &t, const std::string &n);

  void Free();

  void FreeChildren();

  NodePtr ThisPtr() { return shared_from_this(); }
};

using NodePtr = std::shared_ptr<Node>;


