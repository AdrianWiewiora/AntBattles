#pragma once

#include "SFML/Graphics.hpp"
#include "FrameInfo.h"
#include <cmath>

class Ant {
private:
    sf::Sprite ant;
    sf::Texture textureAnt;
public:
    Ant();
    sf::Vector2f getPositionAnt();
    void setRotationAnt(sf::RenderWindow *window);
    void rotationSteering(FrameInfo &frameInfo);
    void moveKeyboard(FrameInfo &frameInfo);
    void drawAnt(sf::RenderWindow *window);
    void moveAnt(FrameInfo &frameInfo, sf::RenderWindow *window);
    sf::Vector2f targetPosition;
};



