//
// Created by Benjamin on 11/12/2022.
//

#ifndef COINKGL_ENGINE_2_VAO_H
#define COINKGL_ENGINE_2_VAO_H


#include <memory>
#include "type/type.h"
#include "renderer/vbo/vbo.h"

class VAO {
 public:
  uint ID;

  VAO();
  ~VAO();

  void Bind();
  void Unbind();

  void LinkAttrib(std::shared_ptr<VBO> vbo, const uint& layout, const int& size, const GLsizei& stride, const void* pointer);
};


#endif //COINKGL_ENGINE_2_VAO_H
