#include "node/manager.h"
#include "utils/utils.h"
#include <memory>
#include <type_traits>

namespace CoinkGL {

namespace {
  std::vector<NodePtr> scenes = {nullptr};
  size_t current_scene = 0;
}

size_t LoadScene(const NodePtr& node) {
  if (node == nullptr) {
    Utils::ErrorLog("Cannot load null node as scene.");
    return 0; // scenes[0] == nullptr
  }

  scenes.push_back(node); // register node as scene
  current_scene++;  // update current scene index (make new scene active)
  Utils::InfoLog("New scene loaded...");
  return current_scene; // return current scene identifier
}

size_t PreloadScene(const NodePtr& node) {
  if (node == nullptr) {
    Utils::ErrorLog("Cannot preload null node as scene.");
    return 0;
  }

  scenes.push_back(node);
  return scenes.size() - 1; // return new loaded scene identifier
}


void UnloadScene(const size_t& scene) {
  scenes[scene] = nullptr;
  current_scene = 0;
}

// nodes management


// getters

const NodePtr& GetCurrentScene() {
  return scenes[current_scene];
}


}
