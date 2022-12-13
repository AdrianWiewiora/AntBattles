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
#include "FrameInfo.h"

class Game {
private:
  sf::RenderWindow *window{};
  sf::Event sfEvent{};
  sf::Clock clock;
  GameState *m_current_state;
  FrameInfo frameInfo;

  Menu menu;
  void initWindow();

public:
  Game();

  void updateSFMLEvents();
  void update();
  void run();
};
