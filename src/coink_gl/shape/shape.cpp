//
// Created by Benjamin on 13/12/2022.
//

#include "shape/shape.h"

Shape::Shape() :
  type(SHAPE_BASE),
  origin(Vec2(0,0)),
  color(COLOR_WHITE)
{}

Shape::Shape(const SHAPE_TYPE& t) :
  type(t),
  origin(Vec2(0,0)),
  color(COLOR_WHITE)
{}

Shape::Shape(const SHAPE_TYPE& t, const Color& col) :
  type(t),
  origin(Vec2(0,0)),
  color(col)
{}


// set the type of the shape
void
Shape::SetType(const SHAPE_TYPE& t) {
  type = t;
  if (type == SHAPE_RECT) {
    SetVertexCount(8);
  } else if (type == SHAPE_FILL_RECT) {
    SetVertexCount(6);
  }
}


// getters
GLenum
Shape::GetDrawType() const {
  switch (type) {
    case SHAPE_FILL_RECT:
    case SHAPE_TRIANGLE:
      return GL_TRIANGLES;

    case SHAPE_PIXEL:
      return GL_POINTS;

    case SHAPE_RECT:
    case SHAPE_LINE:
      return GL_LINES;

    default:
      return GL_TRIANGLES;
  }
}