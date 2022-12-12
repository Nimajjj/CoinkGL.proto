//
// Created by Benjamin on 11/12/2022.
//
#pragma once
#include <glad/glad.h>

#include "type/type.h"


class VBO {
 public:
  uint ID;

  VBO();
  ~VBO();

  void Bind();
  void Unbind();

  void BufferData(GLfloat* vertices, GLsizeiptr size);
};