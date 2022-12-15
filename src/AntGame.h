#pragma once

#include "GameState.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"
#include <iostream>
#include <cmath>
#include "FrameInfo.h"
#include "Ant.h"
#include "GameBar.h"


class AntGame : GameState {
private:
    sf::RectangleShape tlo,greenResourcesRS,blueResourcesRS;
    sf::Texture Torf,greenResourceTexture,greenResourceTextureBW,blueResourceTexture,blueResourceTextureBW;
    sf::View view1;
    sf::Event event;
    float viewWidth = 1920,viewHeight = 1080;
    Ant ant1;
    GameBar gameBar;

    double time=0,timeHelpGreenResources=0,timeHelpBlueResources=0;

public:
    AntGame();
    virtual void Render(sf::RenderWindow *window) override;
    virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo)  override;

    sf::Vector2f MaxCenter(FrameInfo &frameInfo);
    sf::Vector2f MinCenter(FrameInfo &frameInfo);
    float Clamp(float value, float max, float min);
};
