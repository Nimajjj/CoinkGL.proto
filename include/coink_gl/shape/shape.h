//
// Created by Benjamin on 11/12/2022.
//

#pragma once

#include <iostream>
#include <memory>

#include <glad/glad.h>

#include "type/type.h"


class Shape {
 public:
  Shape();
  Shape(const SHAPE_TYPE& t);
  Shape(const SHAPE_TYPE& t, const Color& col);

  virtual ~Shape() = default;
  virtual void Info() = 0;

  void SetColor(const Color& col) {color = col;}
  void SetType(const SHAPE_TYPE& t);
  void SetOrigin(const Point& o) {origin = o;}

  uint GetVerticesCount() const {return vertices_count;}

  const SHAPE_TYPE& GetShapeType() const {return type;}

  const Color& GetColor() const {return color;}

  GLenum GetDrawType() const;

  void SetVertexCount(const uint& count) { vertices_count = count;}

 protected:
  SHAPE_TYPE type;
  Vec2 origin;
  Color color;
  uint vertices_count;
};


using ShapePtr = std::shared_ptr<Shape>;
