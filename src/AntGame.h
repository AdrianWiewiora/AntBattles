#pragma once

#include "GameState.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "FrameInfo.h"
#include "Ant.h"
#include "GameBar.h"
#include "UpgradeMenu.h"
#include "Enemy.h"
#include "Menu.h"


class AntGame : GameState {
private:
    sf::RectangleShape tlo,greenResourcesRS,blueResourcesRS,redResourcesRS[50],*blackResourcesRS;
    sf::Texture Torf,greenResourceTexture,greenResourceTextureBW,blueResourceTexture,blueResourceTextureBW;
    sf::View view1;
    float viewWidth = 1920,viewHeight = 1080;
    Ant ant1;
    Enemy enemies[5];
    Enemy *enemy;
    GameBar gameBar;
    double time=0,timeHelpGreenResources=0,timeHelpBlueResources=0;
    int mUpgradeMenuExist=0,mRainExist = 0;
    UpgradeMenu mUpgradeMenu;
    sf::Vector2f antPosition, enemyPosition[5];

public:
    AntGame();
    ~AntGame();
    virtual void Render(sf::RenderWindow *window) override;
    virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo)  override;

    sf::Vector2f MaxCenter();
    sf::Vector2f MinCenter();
    float Clamp(float value, float max, float min);
};
