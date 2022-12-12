//
// Created by Benjamin on 11/12/2022.
//
#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "renderer/vao/vao.h"
#include "type/type.h"

class VertexHelper {
 public:
  VertexHelper();
  ~VertexHelper();

  void VerticesPushBack(const float& data);
  void VerticesPushVec2(const Vec2& data);
  void VerticesPushColor(const Color& data);
  void SetVertices(const std::vector<float>& v);
  void ClearVertices();

  void VeticesSetFloat(const uint& index, const float& data);
  void VeticesSetVec2(const uint& index, const Vec2& data);
  void VeticesSetColor(const uint& index, const Color& data);

  void UpdateBufferData();
  void Draw(const GLenum& type);
  void Draw(const GLenum& type, const uint& begin, const uint& end);

 private:
  std::vector<float> vertices;
  std::shared_ptr<VAO> vao;
  std::shared_ptr<VBO> vbo;
  std::vector<std::vector<int>> layouts;
};
