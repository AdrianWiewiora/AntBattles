#pragma once

#include "GameState.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include <iostream>


class AntGame : GameState {
  sf::RectangleShape tlo;
  sf::Sprite ant1;
  sf::Texture Torf;
  sf::Texture t;
  sf::View view1;
  sf::Event event;
  float pozX{},pozY{};
  float vectX=0,vectY=0;
  float viewWidth = 1920,viewHeight = 1080;
  float helpX, helpY;

public:
  AntGame();
  virtual void Render(sf::RenderWindow *window) override;
  virtual void Input(sf::RenderWindow *window) override;
  virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo)  override;
};
