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
    void drawAnt(sf::RenderWindow *window);
    void moveAnt(FrameInfo &frameInfo);
    sf::Vector2f targetPosition;
};



