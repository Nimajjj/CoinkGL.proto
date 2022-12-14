//
// Created by Benjamin on 11/12/2022.
//

#pragma once

#include <iostream>

#include <glad/glad.h>

#include "type/type.h"

typedef unsigned int uint;

enum SHAPE_TYPE {
  SHAPE_BASE,
  SHAPE_TRIANGLE,
  SHAPE_RECT,
  SHAPE_FILL_RECT,
  SHAPE_PIXEL,
  SHAPE_LINE
};

class Shape {
 public:
  Shape();
  Shape(const SHAPE_TYPE& t);
  Shape(const SHAPE_TYPE& t, const Color& col);

  virtual ~Shape() = default;
  virtual void Info() = 0;

  void SetColor(const Color& col) {color = col;}
  void SetType(const SHAPE_TYPE& t);

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

typedef std::shared_ptr<Shape> ShapePtr;



