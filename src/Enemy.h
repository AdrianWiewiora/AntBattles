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
    sf::Sprite *redAnt;
    int hpEnemy = 10;
    int hpTimeHelp;
public:
    Enemy();
    ~Enemy();
    sf::Vector2f getPositionEnemy();
    void drawEnemy(sf::RenderWindow *window);
    void
    moveEnemy(FrameInfo &frameInfo, sf::RenderWindow *window, sf::Vector2f targetPosition, sf::Vector2f otherPosition[5]);
    void setEnemy(float x, float y);
    void setHP(double timeGame);
    sf::Sprite* getPtr();
    int getHp();
};


#endif //ZALICZENIE2_ENEMY_H
