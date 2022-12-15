//
// Created by Benjamin on 11/12/2022.
//

#include "renderer/renderer.h"

void
Renderer::Init(const Size& scr_size) {
  Utils::Log(INFO, "Renderer initializing ...");
  internal_renderer = std::make_unique<InternalRenderer>(scr_size);
  Utils::Log(INFO, "Renderer initialization OK");
}

void
Renderer::Close() {
  Utils::Log(INFO, "Closing Renderer ...");
  // ...
  Utils::Log(INFO, "Closing Renderer OK");
}

void
Renderer::Update() {internal_renderer->GenerateVertices();}

void
Renderer::Render() {internal_renderer->Render();}

void
Renderer::RemoveShape(const std::shared_ptr<Shape>& shape) {internal_renderer->QueueFree(shape);}


void
Renderer::NewTriangle(const std::shared_ptr<Triangle>& shape) {internal_renderer->QueueShape(shape);}

std::shared_ptr<Triangle>
Renderer::NewTriangle(const Point& p1, const Point& p2, const Point& p3, const Color& color) {
  auto shape = std::make_shared<Triangle>(p1, p2, p3, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void
Renderer::NewRect(const std::shared_ptr<Rect>& shape) {internal_renderer->QueueShape(shape);}

std::shared_ptr<Rect>
Renderer::NewRect(const Point& position, const Size& size, const Color& color) {
  auto shape = std::make_shared<Rect>(position, size, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void
Renderer::NewFillRect(const std::shared_ptr<Rect>& shape) {
  shape->SetType(SHAPE_FILL_RECT);
  internal_renderer->QueueShape(shape);
}

std::shared_ptr<Rect>
Renderer::NewFillRect(const Point& position, const Size& size, const Color& color) {
  auto shape = std::make_shared<Rect>(position, size, color);
  shape->SetType(SHAPE_FILL_RECT);
  internal_renderer->QueueShape(shape);
  return shape;
}

void
Renderer::NewPixel(const std::shared_ptr<Pixel>& shape) {internal_renderer->QueueShape(shape);}

std::shared_ptr<Pixel>
Renderer::NewPixel(const Point& position, const Color& color) {
  auto shape = std::make_shared<Pixel>(position, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void
Renderer::NewLine(const std::shared_ptr<Line>& shape) {internal_renderer->QueueShape(shape);}

std::shared_ptr<Line>
Renderer::NewLine(const Point& p1, const Point& p2, const Color& color) {
  auto shape = std::make_shared<Line>(p1, p2, color);
  internal_renderer->QueueShape(shape);
  return shape;
}