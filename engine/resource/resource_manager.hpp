#include "../core/interface/renderer.hpp"

#include <string>
#include <unordered_map>

class ResourceManager {
private:
  ResourceManager() {}
  ~ResourceManager() { unloadAllTextures(); }

  ResourceManager(const ResourceManager &) = delete;

  std::unordered_map<std::string, Texture2D> textures;

  void unloadAllTextures() {
    for (auto &pair : textures) {
      Renderer::instance().unloadTexture2D(pair.second);
    }
    textures.clear();
  }

public:
  static ResourceManager &getInstance() {
    static ResourceManager instance;
    return instance;
  }

  Texture2D getTexture(const std::string &path) {
    auto it = textures.find(path);
    if (it != textures.end()) {
      return it->second;
    } else {
      Texture2D texture = Renderer::instance().loadTexture2D(path.c_str());
      textures[path] = texture;
      return texture;
    }
  }
};
