//
// Created by Benjamin on 11/12/2022.
//

#include "renderer/vertex_helper/vertex_helper.h"

VertexHelper::VertexHelper() {
  // INIT -----
  vao = std::shared_ptr<VAO>(new VAO());
  vbo = std::shared_ptr<VBO>(new VBO());
  layouts = {
    {2, 6, 0},  // layout 0 : size = 2; stride = 6; pointer = (void*)(0 * sizeof(float))
    {4, 6, 2}   // layout 1 : size = 4; stride = 6; pointer = (void*)(2 * sizeof(float))
  };

  // LINK VAO -----
  vao->Bind();

  vao->LinkAttrib(
    vbo,
    0,
    layouts[0][0],
    layouts[0][1] * sizeof(float),
    (void*)(layouts[0][2] * sizeof(float))
  );
  vao->LinkAttrib(
    vbo,
    1,
    4,
    6 * sizeof(float),
    (void*)(2 * sizeof(float))
  );

  vao->Unbind();
}

VertexHelper::~VertexHelper() {
  vao->Unbind();
  vbo->Unbind();
}

void VertexHelper::VerticesPushBack(const float& data) {
  vertices.push_back(data);
}

void VertexHelper::VerticesPushVec2(const Vec2& data) {
  vertices.push_back((float)data.x);
  vertices.push_back((float)data.y);
}

void VertexHelper::VerticesPushColor(const Color& data) {
  vertices.push_back((float)(data.r / 0xFF));
  vertices.push_back((float)(data.g / 0xFF));
  vertices.push_back((float)(data.b / 0xFF));
  vertices.push_back((float)(data.a / 0xFF));
}

void VertexHelper::SetVertices(const std::vector<float>& v) {
  vertices = v;
}

void VertexHelper::ClearVertices() {
  if (vertices.size() == 0) return;
  vertices.clear();
}

void VertexHelper::VeticesSetFloat(const uint& index, const float& data) {
  if (index >= vertices.size()) {
    std::cout << "Error : index out of range\n";
    return;
  }

  vertices[index] = data;
}

void VertexHelper::VeticesSetVec2(const uint& index, const Vec2& data) {
  if (index + 1 >= vertices.size()) {
    std::cout << "Error : index out of range\n";
    return;
  }

  vertices[index] = data.x;
  vertices[index + 1] = data.y;
}

void VertexHelper::VeticesSetColor(const uint& index, const Color& data) {
  if (index + 3 >= vertices.size()) {
    std::cout << "Error : index out of range\n";
    return;
  }

  vertices[index] = data.r / 0xFF;
  vertices[index + 1] = data.g / 0xFF;
  vertices[index + 2] = data.b / 0xFF;
  vertices[index + 3] = data.a / 0xFF;
}



void VertexHelper::UpdateBufferData() {
  vbo->Bind();
  vbo->BufferData(&vertices.front(), vertices.size() * sizeof(float));
  vbo->Unbind();
}

void VertexHelper::Draw(const GLenum& type) {
  vao->Bind();
  glDrawArrays(type, 0, vertices.size() / layouts[0][1]);
  vao->Unbind();
}


void VertexHelper::Draw(const GLenum& type, const uint& begin, const uint& end) {
  vao->Bind();
  glDrawArrays(type, begin, end - begin);
  vao->Unbind();
}