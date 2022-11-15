#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameState.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Menu : GameState {
private:
  sf::Texture Mrowka;
  sf::RectangleShape Tlo;

  double m_lifetime = 5;

public:
  Menu();
  virtual void Render(sf::RenderWindow *window) override;
  virtual void Input(sf::RenderWindow *window) override;
  virtual void Update(sf::RenderWindow *window, double delta) override;
};
