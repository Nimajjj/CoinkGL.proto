//
// Created by Benjamin on 11/12/2022.
//

#include "renderer/vbo/vbo.h"

VBO::VBO() {
  glGenBuffers(1, &ID);
}

VBO::~VBO() {
  glDeleteBuffers(1, &ID);
}


void VBO::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void VBO::BufferData(GLfloat* vertices, GLsizeiptr size) {
  glBindBuffer(GL_ARRAY_BUFFER, ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}
