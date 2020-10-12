#ifndef GAME_HPP
#define GAME_HPP

#include "ObjectManager.hpp"

namespace thegame {

class Game {
public:
  Game() {}
  ~Game() {}

  static thegame::ObjectManager objectManager;
};

} // namespace thegame

#endif
