//
// Created by Benjamin on 11/12/2022.
//
#pragma once

#include <vector>

#include "glad/glad.h"

#include "type/type.h"
#include "shape/shape.h"


class Order {
 public:
  Order(const SHAPE_TYPE& vID, const uint& beg, const uint& en);
  ~Order() = default;


  // setters
  void SetDrawType(const GLenum& draw_type) {type = draw_type;}
  void AddShape(const ShapePtr& shape) {shape_list.push_back(shape);}
  bool RemoveShape(const ShapePtr& shape);
  void MoveVerticesRange(const uint& beg, const uint& en) { MoveBegin(beg); MoveEnd(en);}
  void MoveVerticesRange(const uint& val) {MoveVerticesRange(val, val);}
  void MoveBegin(const uint& beg);
  void MoveEnd(const uint& en);


  // getters
  const std::vector<ShapePtr>& GetShapeList() const {return shape_list;}
  const GLenum& GetDrawType() const {return type;}
  const int& GetBegin() const {return begin;}
  const int& GetEnd() const {return end;}

  bool Contain(const ShapePtr& shape) const {
    return std::find(shape_list.begin(), shape_list.end(), shape) != shape_list.end();
  }

  bool IsEmpty() const {return shape_list.empty();}


 private:
  std::vector<ShapePtr> shape_list;
  GLenum type;
  int begin;
  int end;
};

using OrderPtr = std::shared_ptr<Order>;