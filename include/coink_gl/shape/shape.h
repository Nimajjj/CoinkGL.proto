//
// Created by Benjamin on 11/12/2022.
//
#pragma once
#include <iostream>
#include <glad/glad.h>
#include "type/type.h"


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
  SHAPE_TYPE type;
  Vec2 origin;
  Color color;


  Shape() :
    type(SHAPE_BASE),
    origin(Vec2(0,0)),
    color(COLOR_WHITE)
  {}

  Shape(const SHAPE_TYPE& t) :
    type(t),
    origin(Vec2(0,0)),
    color(COLOR_WHITE)
  {}

  Shape(const SHAPE_TYPE& t, const Color& col) :
    type(t),
    origin(Vec2(0,0)),
    color(col)
  {}

  virtual ~Shape() = default;

  void Info() {};

  void SetColor(const Color& col) {color = col;}
  void SetType(const SHAPE_TYPE& t) {
    type = t;
    if (type == SHAPE_RECT) {
      SetVertexCount(8);
    } else if (type == SHAPE_FILL_RECT) {
      SetVertexCount(6);
    }
  }

  uint GetVerticesCount() const {return vertices_count;}

  GLenum GetDrawType() const {
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

 protected:
  uint vertices_count;

  void SetVertexCount(const uint& count) { vertices_count = count;}
};

typedef std::shared_ptr<Shape> ShapePtr;


class Rect : public Shape {
 public:
  Vec2 position;
  Vec2 size;

  Rect() :
    Shape(SHAPE_RECT),
    position(Vec2()),
    size(Vec2())
  {
    SetVertexCount(8);
  }

  Rect(const Vec2& pos, const Vec2& sz) :
    Shape(SHAPE_RECT),
    position(pos),
    size(sz)
  {
    SetVertexCount(8);
  }

  Rect(const Vec2& pos, const Vec2& sz, const Color& col) :
    Shape(SHAPE_RECT, col),
    position(pos),
    size(sz)
  {
    SetVertexCount(8);
  }

  ~Rect() = default;

  void Info() const {
    std::cout << "type : SHAPE_RECT\n";
    std::cout << "position : (" << position.x << ", " << position.y << ")\n" <<
              "size : (" << size.x << ", " << size.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};

class Pixel : public Rect {
 public:
  Pixel() :
    Rect(Vec2(), Vec2(1,1))
  {
    this->type = SHAPE_PIXEL;
  SetVertexCount(1);
  }

  Pixel(const Vec2& pos) :
    Rect(pos, Vec2(1,1))
  {
    this->type = SHAPE_PIXEL;
    SetVertexCount(1);
  }

  Pixel(const Vec2& pos, const Color& col) :
    Rect(pos, Vec2(1,1), col)
  {
    this->type = SHAPE_PIXEL;
    SetVertexCount(1);
  }

  ~Pixel() = default;

  void Info() const {
    std::cout << "type : SHAPE_PIXEL\n";
    std::cout << "position : (" << position.x << ", " << position.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};


class Triangle : public Shape {
 public:
  Vec2 aPos;
  Vec2 bPos;
  Vec2 cPos;

  Triangle() :
    Shape(SHAPE_TRIANGLE),
    aPos(Vec2()),
    bPos(Vec2()),
    cPos(Vec2())
  {
    SetVertexCount(3);
  }

  Triangle(Vec2 a, Vec2 b, Vec2 c) :
    Shape(SHAPE_TRIANGLE),
    aPos(a),
    bPos(b),
    cPos(c)
  {
    SetVertexCount(3);
  }

  Triangle(Vec2 a, Vec2 b, Vec2 c, const Color& col) :
    Shape(SHAPE_TRIANGLE, col),
    aPos(a),
    bPos(b),
    cPos(c)
  {
    SetVertexCount(3);
  }

  ~Triangle() = default;

  void Info() const {
    std::cout << "type : SHAPE_TRIANGLE\n";
    std::cout << "aPos : (" << aPos.x << ", " << aPos.y << ")\n" <<
              "bPos : (" << bPos.x << ", " << bPos.y << ")\n" <<
              "cPos : (" << cPos.x << ", " << cPos.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};

class Line : public Shape {
 public:
  Vec2 pos1;
  Vec2 pos2;
  uint line_width;

  Line() :
    Shape(SHAPE_LINE),
    pos1(Vec2()),
    pos2(Vec2()),
    line_width(1)
  {
    SetVertexCount(2);
  }

  Line(const Vec2& pos1, const Vec2& pos2, const uint& w = 1) :
    Shape(SHAPE_LINE),
    pos1(pos1),
    pos2(pos2),
    line_width(w)
  {
    SetVertexCount(2);
  }

  Line(const Vec2& pos1, const Vec2& pos2, const Color& col, const uint& w = 1) :
    Shape(SHAPE_LINE, col),
    pos1(pos1),
    pos2(pos2),
    line_width(w)
  {
    SetVertexCount(2);
  }

  ~Line() = default;

  void Info() const {
    std::cout << "type : SHAPE_LINE\n";
    std::cout << "position 1 : (" << pos1.x << ", " << pos1.y << ")\n" <<
              "position 2 : (" << pos2.x << ", " << pos2.y << ")\n" <<
              "color : (" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << ")\n";
  }
};