#include "node/internal_node_renderer.h"
#include "type/color.h"
#include "type/duck.h"
#include "utils/utils.h"
#include <map>


namespace CoinkGL {
namespace InternalNodeRenderer {

namespace {
  bool need_to_update;
  Size screen_size;
  std::unique_ptr<InternalRenderer> internal_renderer;
  std::map<DUCK, std::vector<ShapePtr>> shape_to_node;
}

void Init(const Size& scr_size) {
  Utils::InfoLog("Internal Node Renderer initializing ...");
  need_to_update = false;
  screen_size = scr_size;
  internal_renderer = std::make_unique<InternalRenderer>(scr_size);
  Utils::InfoLog("Internal Node Renderer initialization OK");
}


void RenderCurrentScene() {
  NodePtr root_node = GetCurrentScene();
  
  if (root_node == nullptr)
    return;

  RenderNode(root_node);

  if (need_to_update)
    internal_renderer->GenerateVertices();

  internal_renderer->Render();

  need_to_update = false;
}


void RenderNode(const NodePtr& node) {
  if (node->NeedUpdate()) {
    if (shape_to_node.find(node->GetID()) == shape_to_node.end()) { // if node's shape isn't registered
      shape_to_node[node->GetID()] = std::vector<ShapePtr>{}; // create shape vector
      shape_to_node[node->GetID()].push_back(           // add shapes for node
        std::make_shared<Rect>(node->GetPosition(),
                               node->GetSize(),
                               COLOR_RED
                               ));
      internal_renderer->QueueShape(shape_to_node[node->GetID()][0]);
      Utils::DebugLog("Newshape");
    } else {
      shape_to_node.at(node->GetID())[0]->SetOrigin(node->GetPosition());
    }

    node->SetNeedUpdate(false); 

    need_to_update = true;

    node->DebugInfo();
  }

  if (node->GetChildren().size() == 0)
    return;

  for (const auto& child : node->GetChildren()) {
    RenderNode(child);
  }
}


}
}

