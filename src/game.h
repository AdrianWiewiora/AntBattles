#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "Menu.h"

class Game {
private:
  // Variables
  sf::RenderWindow *window{};
  sf::Event sfEvent{};
  sf::Clock clock;
  GameState *m_current_state;

  Menu menu;
  // Initialization
  void initWindow();

public:
  // Constructors
  Game();

  // Functions
  void updateSFMLEvents();
  void update();
  void render();
  void run();
};
