//
// Created by AdiAs on 26.12.2022.
//

#ifndef ZALICZENIE2_ENEMY_H
#define ZALICZENIE2_ENEMY_H


#include "SFML/Graphics.hpp"
#include "FrameInfo.h"
#include "GameBar.h"
#include <cmath>
#include <iostream>

class Enemy {
private:
    sf::Texture textureAnt;
    sf::Sprite *redAnt;
    int hpEnemy = 10;
    int hpTimeHelp,helpEnemyPos=0;
public:
    Enemy();
    ~Enemy();
    sf::Vector2f getPositionEnemy();
    void drawEnemy(sf::RenderWindow *window);
    void
    moveEnemy(FrameInfo &frameInfo, sf::RenderWindow *window, sf::Vector2f targetPosition, sf::Vector2f otherPosition[5]);
    void setEnemy(float x, float y);
    void setHP(double timeGame, GameBar gameBarF);
    sf::Sprite* getPtr();
    int getHp();
};


#endif //ZALICZENIE2_ENEMY_H
