#pragma once

#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <cmath>
#include "FrameInfo.h"
#include "Ant.h"
#include "GameBar.h"
#include "UpgradeMenu.h"


class AntGame : GameState {
private:
    sf::RectangleShape tlo,greenResourcesRS,blueResourcesRS;
    sf::Texture Torf,greenResourceTexture,greenResourceTextureBW,blueResourceTexture,blueResourceTextureBW;
    sf::View view1;
    float viewWidth = 1920,viewHeight = 1080;
    Ant ant1;
    GameBar gameBar;
    double time=0,timeHelpGreenResources=0,timeHelpBlueResources=0;
    int mUpgradeMenuExist=0;
    UpgradeMenu mUpgradeMenu;

public:
    AntGame();
    virtual void Render(sf::RenderWindow *window) override;
    virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo)  override;

    sf::Vector2f MaxCenter(FrameInfo &frameInfo);
    sf::Vector2f MinCenter(FrameInfo &frameInfo);
    float Clamp(float value, float max, float min);
};
