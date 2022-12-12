//
// Created by Benjamin on 11/12/2022.
//
#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <glad/glad.h>

#include "type/type.h"

class Shader {
 public:
  // the program type
  uint ID;
  static std::string shaders_directory;

  // constructor reads and builds the shader
  inline Shader() : ID(0) {};
  inline Shader(const std::string& vertex_path, const std::string& fragment_path) {
    Init(vertex_path, fragment_path);
  };
  void Init(const std::string& vertex_path, const std::string& fragment_path);

  // use/activate the shader
  void Use();
  // utility uniform functions
  void SetBool(const std::string& name, bool value) const;
  void SetInt(const std::string& name, int value) const;
  void SetFloat(const std::string& name, float value) const;

  static void SetShadersDirectory(const std::string& path);

 private:
  // 2. compile shaders
  // vertex shader
  // fragment Shader
  // shader Program
  // delete the shaders as they're linked into our program now and no longer necessary


};

