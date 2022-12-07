#pragma once

#include "GameState.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include <iostream>
#include "FrameInfo.h"


class AntGame : GameState {
    sf::RectangleShape tlo;
    sf::Sprite ant1;
    sf::Texture Torf;
    sf::Texture t;
    sf::View view1;
    sf::Event event;
    float viewWidth = 1920,viewHeight = 1080;

    sf::Vector2f vectorF;
    sf::Vector2i vectorI;
    sf::Vector2f vectorViewCenter;

public:
  AntGame();
  virtual void Render(sf::RenderWindow *window) override;
  virtual void Input(sf::RenderWindow *window) override;
  virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo)  override;

  void MoveAnts(sf::Vector2f positions,FrameInfo &frameInfo);
};
