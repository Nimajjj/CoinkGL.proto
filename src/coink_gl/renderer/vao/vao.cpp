//
// Created by Benjamin on 11/12/2022.
//

#include "coink_gl/renderer/vao/vao.h"

VAO::VAO() {
  glGenVertexArrays(1, &ID);
}

VAO::~VAO() {
  glDeleteVertexArrays(1, &ID);
}

void VAO::Bind() {
  glBindVertexArray(ID);
}

void VAO::Unbind() {
  glBindVertexArray(0);
}


void VAO::LinkAttrib(std::shared_ptr<VBO> vbo, const uint& layout, const int& size, const GLsizei& stride, const void* pointer) {
  vbo->Bind();
  glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, stride, pointer);
  glEnableVertexAttribArray(layout);
  vbo->Unbind();
}