//
// Created by Benjamin on 10/12/2022.
//
#pragma once

#include <iostream>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "type/type.h"
#include "utils/utils.h"
#include "shader/shader.h"
#include "renderer/renderer.h"

namespace CoinkGL {
// MAIN ----------
void Init(const Size& scr_size, const std::string& title);
void Terminate();

// LOOP ----------
bool ShouldNotClose();
void BeginLoop();
void EndLoop();

// DEBUG ---------
void DebugQuitOnFirstLoop();
}