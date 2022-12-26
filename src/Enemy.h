//
// Created by AdiAs on 26.12.2022.
//

#ifndef ZALICZENIE2_ENEMY_H
#define ZALICZENIE2_ENEMY_H


#include "SFML/Graphics.hpp"
#include "FrameInfo.h"
#include <cmath>

class Enemy {
private:
    sf::Sprite enemy;
    sf::Texture textureAnt;
public:
    Enemy();
    sf::Vector2f getPositionEnemy();
    void drawEnemy(sf::RenderWindow *window);
    void moveEnemy(FrameInfo &frameInfo, sf::RenderWindow *window,sf::Vector2f targetPosition);
    void setEnemy(float x, float y);
};


#endif //ZALICZENIE2_ENEMY_H
