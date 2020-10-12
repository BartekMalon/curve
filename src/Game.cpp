#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Game.hpp"
#include "Player.hpp"

using namespace thegame;

thegame::ObjectManager Game::objectManager;

int main(int argc, char *argv[]) {

  sf::Window window(sf::VideoMode(1280, 720), "Game");

  sf::RenderWindow renWindow;
  renWindow.create(window.getSystemHandle());

  sf::RenderTexture renTex;
  renTex.create(window.getSize().x, window.getSize().y);

  sf::RectangleShape targetDrawRect;
  targetDrawRect.setTexture(&renTex.getTexture(), true);

  sf::Clock clock;
  clock.restart();

  Player *player = new Player("player1");
  Powerup *powerup = new Powerup("speedup");

  Game::objectManager.addObject(player);
  Game::objectManager.addObject(powerup);

  player->setPosition(sf::Vector2f(400, 200));
  // player->setColuor(sf::Color::Red);
  player->setVelocity(sf::Vector2f(0, 0));

  while (window.isOpen()) {

    sf::Event event;
    while (window.pollEvent(event)) {
      for (auto &obj : Game::objectManager.getObjects()) {
        obj.second->handleKeyInput(event);
      }
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // renWindow.clear(sf::Color::Black);

    Game::objectManager.drawAll(renTex, sf::RenderStates::Default);

    sf::CircleShape c;
    c.setFillColor(sf::Color::Red);
    c.setPointCount(32);
    c.setPosition(200, 200);
    c.setRadius(50);

    targetDrawRect.setTexture(&renTex.getTexture(), true);

    for (auto &obj : Game::objectManager.getObjects()) {
      auto tempptr = obj.second;
      renWindow.draw(c);
      // renTex.draw(c, sf::Vector2f(300, 300));
      renTex.draw(c, sf::RenderStates::Default);
      renTex.draw(reinterpret_cast<thegame::Player *>(tempptr)->getShape(),
                  sf::RenderStates::Default);
      // renTex.draw();
      sf::RenderStates rs = sf::RenderStates::Default;
      rs.transform.translate(player->getPosition());
      renWindow.draw(player->getShape(), rs);
      // renWindow.draw(;
      // window.draw(&obj.(*second)->getShape());
    }

    // renWindow.draw(targetDrawRect, sf::RenderStates::Default);
    // renWindow.draw(c);

    Game::objectManager.updateAll(clock.getElapsedTime());
    // Game::objectManager.updateAll(sf::Time::Zero);

    renWindow.display();
    clock.restart();
  }

  return 0;
}