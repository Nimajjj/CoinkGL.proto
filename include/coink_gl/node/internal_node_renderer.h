//
//  Created by Benjamin 23/12/2022
//
#pragma once

#include <map>
#include <vector>

#include "utils/utils.h"
#include "node/manager.h"
#include "renderer/internal_renderer.h"
#include "shape/shape.h"

namespace CoinkGL {
namespace InternalNodeRenderer {

void Init(const Size& scr_size);
void RenderCurrentScene();

void RenderNode(const NodePtr& node);
}
}
