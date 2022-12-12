//
// Created by Benjamin on 11/12/2022.
//

#include "coink_gl/shader/shader.h"
#include "utils/utils.h"

std::string GetFileContents(const char* filename);
void CheckCompileErrors(unsigned int shader, std::string type);

void Shader::Init(const std::string& vertex_path, const std::string& fragment_path) {
  Utils::Log(Utils::INFO, "Creating shader ...");
  // 1. retrieve the vertex/fragment source code from filePath
  std::string vertexCode = GetFileContents((shaders_directory + vertex_path).c_str());
  std::string fragmentCode = GetFileContents((shaders_directory + fragment_path).c_str());
  const char* vShaderCode = vertexCode.c_str();
  const char* fShaderCode = fragmentCode.c_str();

  // 2. compile shaders
  unsigned int vertex, fragment;
  // vertex shader
  vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex, 1, &vShaderCode, NULL);
  glCompileShader(vertex);
  CheckCompileErrors(vertex, "VERTEX");
  // fragment Shader
  fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, &fShaderCode, NULL);
  glCompileShader(fragment);
  CheckCompileErrors(fragment, "FRAGMENT");
  // shader Program
  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);
  CheckCompileErrors(ID, "PROGRAM");
  // delete the shaders as they're linked into our program now and no longer necessary
  glDeleteShader(vertex);
  glDeleteShader(fragment);

  Utils::Log(Utils::INFO, "Creating shader OK");
}
// activate the shader
// ------------------------------------------------------------------------
void Shader::Use() {
  glUseProgram(ID);
}
// utility uniform functions
// ------------------------------------------------------------------------
void Shader::SetBool(const std::string& name, bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void Shader::SetInt(const std::string& name, int value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void Shader::SetFloat(const std::string& name, float value) const {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetShadersDirectory(const std::string& path) {
  Utils::Log(Utils::INFO, std::string("Setting shaders directory to ") + path);
  shaders_directory = path;
}



std::string Shader::shaders_directory = "";
// utility function for checking shader compilation/linking errors.
// ------------------------------------------------------------------------
void CheckCompileErrors(unsigned int shader, std::string type) {
  int success;
  char infoLog[1024];
  if (type != "PROGRAM") {
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
      glGetShaderInfoLog(shader, 1024, NULL, infoLog);
      Utils::Log(Utils::ERROR, std::string("Shader compilation error of type: ") + type + "\n" + infoLog);
    }
  } else {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, infoLog);
      Utils::Log(Utils::ERROR, std::string("Shader program linking error of type: ") + type + "\n" + infoLog);
    }
  }
}


std::string GetFileContents(const char* filename) {
  std::ifstream in(filename, std::ios::binary);
  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  Utils::Log(Utils::ERROR,
             std::string("file :") + filename + " at " + Shader::shaders_directory + " does not exist");
  throw(errno);
}
