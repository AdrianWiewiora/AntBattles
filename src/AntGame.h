#pragma once

#include "GameState.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class AntGame : GameState {
  sf::RectangleShape tlo;
  sf::Sprite ant1;
  sf::Texture Mrowka;

public:
  AntGame();
  virtual void Render(sf::RenderWindow *window) override;
  virtual void Input(sf::RenderWindow *window) override;
  virtual void Update(sf::RenderWindow *window, double delta) override;
};
