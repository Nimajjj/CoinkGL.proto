//
// Created by Benjamin on 11/12/2022.
//

#include "renderer/renderer.h"
#include "renderer/internal_renderer.h"

namespace Renderer {
namespace {
std::unique_ptr<InternalRenderer> internal_renderer;
}

void Init(const Size& scr_size) {
  Utils::Log(Utils::INFO, "Renderer initializing ...");
  internal_renderer = std::make_unique<InternalRenderer>(scr_size);
  Utils::Log(Utils::INFO, "Renderer initialization OK");
}

void Close() {
  Utils::Log(Utils::INFO, "Closing Renderer ...");
  // ...
  Utils::Log(Utils::INFO, "Closing Renderer OK");
}

void Update() {internal_renderer->GenerateVertices();}
void Render() {internal_renderer->Render();}
void RemoveShape(const std::shared_ptr<Shape>& shape) {internal_renderer->QueueFree(shape);}


void NewTriangle(const std::shared_ptr<Triangle>& shape) {internal_renderer->QueueShape(shape);}

std::shared_ptr<Triangle> NewTriangle(const Point& p1, const Point& p2, const Point& p3, const Color& color) {
  auto shape = std::make_shared<Triangle>(p1, p2, p3, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void NewRect(const std::shared_ptr<Rect>& shape) {internal_renderer->QueueShape(shape);}
std::shared_ptr<Rect> NewRect(const Point& position, const Size& size, const Color& color) {
  auto shape = std::make_shared<Rect>(position, size, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void NewFillRect(const std::shared_ptr<Rect>& shape) {
  shape->SetType(SHAPE_FILL_RECT);
  internal_renderer->QueueShape(shape);
}
std::shared_ptr<Rect> NewFillRect(const Point& position, const Size& size, const Color& color) {
  auto shape = std::make_shared<Rect>(position, size, color);
  shape->SetType(SHAPE_FILL_RECT);
  internal_renderer->QueueShape(shape);
  return shape;
}

void NewPixel(const std::shared_ptr<Pixel>& shape) {internal_renderer->QueueShape(shape);}
std::shared_ptr<Pixel> NewPixel(const Point& position, const Color& color) {
  auto shape = std::make_shared<Pixel>(position, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

void NewLine(const std::shared_ptr<Line>& shape) {internal_renderer->QueueShape(shape);}
std::shared_ptr<Line> NewLine(const Point& p1, const Point& p2, const Color& color) {
  auto shape = std::make_shared<Line>(p1, p2, color);
  internal_renderer->QueueShape(shape);
  return shape;
}

};
