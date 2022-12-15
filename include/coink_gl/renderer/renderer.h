//
// Created by Benjamin on 11/12/2022.
//

#pragma once

#include <memory>

#include "renderer/internal_renderer.h"
#include "type/type.h"
#include "utils/utils.h"



// Singleton facade for user-friendly basic rendering
// Depend on InternalRenderer class
class Renderer {
 public:
  // main
  Renderer(const Size& scr_size) :
    screen_size(scr_size)
  {
    Init(screen_size);
  }

  ~Renderer() {
    Close();
  }

  void Init(const Size& scr_size);
  void Close();

  // update and render
  void Update();
  void Render();


  // shape related
  void RemoveShape(const std::shared_ptr<Shape>& shape);

  void NewTriangle(const std::shared_ptr<Triangle>& shape);
  std::shared_ptr<Triangle> NewTriangle(const Point& p1, const Point& p2, const Point& p3, const Color& color);

  void NewRect(const std::shared_ptr<Rect>& shape);
  std::shared_ptr<Rect> NewRect(const Point& position, const Size& size, const Color& color);

  void NewFillRect(const std::shared_ptr<Rect>& shape);
  std::shared_ptr<Rect> NewFillRect(const Point& position, const Size& size, const Color& color);

  void NewPixel(const std::shared_ptr<Pixel>& shape);
  std::shared_ptr<Pixel> NewPixel(const Point& position, const Color& color);

  void NewLine(const std::shared_ptr<Line>& shape);
  std::shared_ptr<Line> NewLine(const Point& p1, const Point& p2, const Color& color);


 private:
  Size screen_size;
  std::unique_ptr<InternalRenderer> internal_renderer;

};
