//
// Created by Benjamin on 12/12/2022.
//
#include "renderer/order/order.h"

Order::Order(const SHAPE_TYPE& vID, const uint& beg, const uint& en) :
  shape_list(std::vector<ShapePtr>()),
  type(vID),
  begin(beg),
  end(en)
{}


// setters
bool
Order::RemoveShape(const ShapePtr& shape) {
  auto it = std::find(shape_list.begin(), shape_list.end(), shape);
  if (it != shape_list.end()) {
    shape_list.erase(it);
    return true;
  }
  return false;
}

void
Order::MoveBegin(const uint& beg) {
  begin += beg;
  if (begin < 0)
    begin = 0;
}

void
Order::MoveEnd(const uint& en) {
  end += en;
  if (end < 0)
    end = 0;
}
