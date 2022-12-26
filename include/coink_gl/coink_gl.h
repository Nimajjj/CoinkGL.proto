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
#include "node/internal_node_renderer.h"

namespace CoinkGL {
// MAIN ----------
void Init(const Size& scr_size, const std::string& title);
void Terminate();

// LOOP ----------
bool ShouldNotClose();
void BeginLoop(); // /!\ deprecated
void EndLoop(); // /!\ deprecated

// DEBUG ---------
void DebugQuitOnFirstLoop();
}
