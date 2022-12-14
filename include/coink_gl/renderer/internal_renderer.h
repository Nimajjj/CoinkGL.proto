//
// Created by Benjamin on 11/12/2022.
//
#pragma once

#include <vector>
#include <map>
#include <cmath>
#include <memory>

#include "renderer/order/order.h"
#include "renderer/vertex_helper/vertex_helper.h"
#include "shader/shader.h"
#include "utils/utils.h"

#include "type/type.h"
#include "shape/shape.h"
#include "shape/triangle/triangle.h"
#include "shape/rect/rect.h"
#include "shape/line/line.h"
#include "shape/pixel/pixel.h"

// TO DO :
// - Limit 'use' ans 'unuse' of shader program when rendering InternalRenderer::Render()


// private class of CoinkGL
// refer to facade class Renderer for safe rendering utilisation
class InternalRenderer {
 public:
  InternalRenderer(const Size& scr_size);
  ~InternalRenderer();

  // (Re) Generate vertices for all shapes
  void GenerateVertices();
  void Clear();

  // Render all shapes from order list (in order)
  void Render();

  // Add shape to queue for removing,
  //   applied at next InternalRenderer::GenerateVertices() call
  void QueueFree(const ShapePtr& shape);

  // Add shape to order list
  //  vertices must be generated to apply this change
  void QueueShape(const ShapePtr& shape);


 private:
  Size screen_size;
  VertexHelper* helper;
  Shader* shader;
  std::vector<OrderPtr> order_list;
  std::vector<ShapePtr> queue_free_list;


  // Normalized coordinates from screen coordinates (0 to screen_size) to OpenGL coordinate (-1 to 1)
  float NormalizeWidth(const float& x) const {return x / (screen_size.x / 2) - 1;}
  float NormalizeHeight(const float& y) const {return y / (screen_size.y / 2) - 1;}

  // Add vertices of a shape to the VertexHelper for later rendering,
  //  depends on the shape type,
  //  relies on VertexHelper::Add<Shape>Vertices() functions
  void AddShapeVertices(const ShapePtr& p_shape);

  void AddTriangleVertices(Shape* shape);
  void AddRectVertices(Shape* shape);
  void AddFillRectVertices(Shape* shape);
  void AddPixelVertices(Shape* shape);
  void AddLineVertices(Shape* shape);


  void FreeShapes();
};