//
// Created by Benjamin on 11/12/2022.
//
#include "renderer/internal_renderer.h"


InternalRenderer::InternalRenderer(const Size& scr_size) :
  screen_size(scr_size),
  order_list(std::vector<OrderPtr>())
{
  helper = new VertexHelper();
  shader = new Shader("default.vert", "default.frag");
}

InternalRenderer::~InternalRenderer() {
  this->Clear();
  delete shader;
  delete helper;
}


void InternalRenderer::GenerateVertices() {
  Utils::Log(Utils::INFO, "Generating vertices ...");

  FreeShapes();

  helper->ClearVertices();

  for (const auto& order : order_list) {

    for (const auto& shape : order->GetShapeList()) {
      AddShapeVertices(shape);
    }

    Utils::Log(Utils::DEBUG, "InternalRenderer::GenerateVertices Vertices generated for order, goes from index " + std::to_string(order->GetBegin()) + " to " + std::to_string(order->GetEnd()));
  }

  helper->UpdateBufferData();

  Utils::Log(Utils::INFO, "Generating vertices ...OK");

}

void InternalRenderer::Clear() {
  helper->ClearVertices();
}

void InternalRenderer::Render() {
  if (shader == nullptr) return;

  shader->Use();

  for (const auto& order : order_list) {
    helper->Draw(
      order->GetDrawType(),
      order->GetBegin(),
      order->GetEnd()
      );
  }
}

void InternalRenderer::QueueFree(const ShapePtr& shape) {
  queue_free_list.push_back(shape);
}

void InternalRenderer::QueueShape(const ShapePtr& shape) {
  // if there is no order, create one, and add the shape to it
  if (order_list.size() == 0) {
    auto new_order = OrderPtr(new Order(shape->type, 0, shape->GetVerticesCount()));
    new_order->AddShape(shape);
    new_order->SetDrawType(shape->GetDrawType());

    order_list.push_back(new_order);
    return;
  }

  // if there is an order, check if the shape type is the same as the last order
  // if it is, add the shape to the last order
  //    and update the end index of the order
  if (order_list.back()->GetDrawType() == shape->GetDrawType()) {
    order_list.back()->MoveEnd(shape->GetVerticesCount());
    order_list.back()->AddShape(shape);
    return;
  }

  // if the shape type is different, create a new order
  auto new_order = OrderPtr(
    new Order(
      shape->type,
      order_list.back()->GetEnd(),
      order_list.back()->GetEnd() + shape->GetVerticesCount()
      )
    );

  new_order->AddShape(shape);
  new_order->SetDrawType(shape->GetDrawType());

  order_list.push_back(new_order);
}



void InternalRenderer::AddShapeVertices(const ShapePtr& p_shape) {
  Shape* shape = p_shape.get();

  switch (shape->type) {
    case SHAPE_BASE:
      Utils::Log(Utils::ERROR, "InternalRenderer::AddShapeVertices() try to update a SHAPE_BASE");
      break;

    case SHAPE_TRIANGLE:
      AddTriangleVertices(shape);
      break;

    case SHAPE_PIXEL:
      AddPixelVertices(shape);
      break;

    case SHAPE_RECT:
      AddRectVertices(shape);
      break;

    case SHAPE_FILL_RECT:
      AddFillRectVertices(shape);
      break;

    case SHAPE_LINE:
      AddLineVertices(shape);
      break;

    default:
      Utils::Log(Utils::ERROR, "InternalRenderer::AddShapeVertices() end of switch without break");
      break;
  }

}


void InternalRenderer::AddTriangleVertices(Shape* shape) {
  auto triangle = static_cast<Triangle*>(shape);

  helper->VerticesPushVec2({NormalizeWidth(triangle->aPos.x), NormalizeHeight(triangle->aPos.y)});
  helper->VerticesPushColor(triangle->color);

  helper->VerticesPushVec2({NormalizeWidth(triangle->bPos.x), NormalizeHeight(triangle->bPos.y)});
  helper->VerticesPushColor(triangle->color);

  helper->VerticesPushVec2({NormalizeWidth(triangle->cPos.x), NormalizeHeight(triangle->cPos.y)});
  helper->VerticesPushColor(triangle->color);
}

void InternalRenderer::AddRectVertices(Shape* shape) {
  auto rect = static_cast<Rect*>(shape);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x),
                            NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x),
                            NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
}

void InternalRenderer::AddFillRectVertices(Shape* shape) {
  auto rect = static_cast<Rect*>(shape);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);

  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x),
                            NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x + rect->size.x), NormalizeHeight(rect->position.y)});
  helper->VerticesPushColor(rect->color);
  helper->VerticesPushVec2({NormalizeWidth(rect->position.x), NormalizeHeight(rect->position.y + rect->size.y)});
  helper->VerticesPushColor(rect->color);

}

void InternalRenderer::AddPixelVertices(Shape* shape) {
  auto pixel = static_cast<Pixel*>(shape);

  helper->VerticesPushVec2({NormalizeWidth(pixel->position.x), NormalizeHeight(pixel->position.y)});
  helper->VerticesPushColor(pixel->color);
}

void InternalRenderer::AddLineVertices(Shape* shape) {
  auto line = static_cast<Line*>(shape);

  helper->VerticesPushVec2({NormalizeWidth(line->pos1.x), NormalizeHeight(line->pos1.y)});
  helper->VerticesPushColor(line->color);
  helper->VerticesPushVec2({NormalizeWidth(line->pos2.x), NormalizeHeight(line->pos2.y)});
  helper->VerticesPushColor(line->color);
}


void InternalRenderer::FreeShapes() {
  // If there is no order, there is no shape
  if (queue_free_list.empty())
    return;

  Utils::Log(Utils::INFO, "Removing free queued shapes ...");

  // Prepare the list of order to remove in case there is one which no longer contain shapes
  std::vector<OrderPtr> order_to_remove;
  int range_modif = 0;

  // For each shape queued to be removed we look for the order it belongs to
  for (const auto& shape_ptr : queue_free_list) {
    for (const auto& order_ptr : order_list) {

      // If the order contains the shape, we save the vertex range of shape
      //  and we remove the shape from the order
      if (order_ptr->Contain(shape_ptr)) {
        range_modif -= shape_ptr->GetVerticesCount();
        order_ptr->RemoveShape(shape_ptr);

        // If the order is empty, we add it to the list of order to remove
        if (order_ptr->IsEmpty())
          order_to_remove.push_back(order_ptr);
      }

      // After removing a shape from an order, we must move vertices ranges of all orders after this one
      order_ptr->MoveVerticesRange(range_modif);
    }

    // We remove the shape from the list of shapes
    for (const auto& order_ptr : order_to_remove) {
      order_list.erase(std::remove(order_list.begin(), order_list.end(), order_ptr), order_list.end());
    }

    Utils::Log(Utils::DEBUG, "Order list begin and end moved of " + std::to_string(range_modif) + " vertices");

    // We reset the vertices range modifier
    range_modif = 0;
  }

  // We clear the list of shapes to remove
  queue_free_list.clear();

  Utils::Log(Utils::INFO, "Removing free queued shapes OK");
}
