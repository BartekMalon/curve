#ifndef OBJECT_MANAGER_HPP
#define OBJECT_MANAGER_HPP

#include "GameObject.hpp"
#include <unordered_map>

namespace thegame {

class ObjectManager {
public:
  ObjectManager() {}
  ~ObjectManager() {}

  void handleKeyInput(sf::Event &event) {
    for (auto &obj : gameObjects) {
      obj.second->handleKeyInput(event);
    }
  }

  void updateAll(sf::Time dt) {
    for (auto &obj : gameObjects) {
      obj.second->update(dt.asSeconds());
    }
  }

  void drawAll(sf::RenderTarget &renTarget, sf::RenderStates renStates) {
    for (auto &obj : gameObjects) {
      obj.second->draw(renTarget, renStates);
    }
  }

  void addObject(Object *obj) { gameObjects.insert(std::make_pair("player1", obj)); }
  std::unordered_map<std::string, Object *> &getObjects() { return gameObjects; }

private:
  std::unordered_map<std::string, Object *> gameObjects;
};

} // namespace thegame

#endif
