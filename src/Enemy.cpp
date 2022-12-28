//
// Created by AdiAs on 26.12.2022.
//

#include "Enemy.h"

Enemy::Enemy() {
    textureAnt.loadFromFile("../images/ant3.png");

    delete redAnt;
    redAnt = new sf::Sprite;
    redAnt->setTexture(textureAnt);
    redAnt->setOrigin(sf::Vector2f(redAnt->getTexture()->getSize().x * 0.5,redAnt->getTexture()->getSize().y * 0.5));
    redAnt->setScale(sf::Vector2f(0.2f, 0.2f));
    redAnt->setPosition(1300, 1500);
}

sf::Vector2f Enemy::getPositionEnemy() {
    return redAnt->getPosition();
}

void Enemy::drawEnemy(sf::RenderWindow *window) {
    window->draw(*redAnt);
}

void Enemy::moveEnemy(FrameInfo &frameInfo, sf::RenderWindow *window, sf::Vector2f targetPosition, sf::Vector2f otherPosition[5]){
    sf::Vector2f currentPosition = redAnt->getPosition();
    srand( time( NULL ) );
    //Rotation
    const float PI = 3.14159265;
    float a = currentPosition.x - targetPosition.x;
    float b = currentPosition.y - targetPosition.y;
    float rotation = ( atan2( b, a ) ) * 180 / PI;
    rotation -= 90;
    redAnt->setRotation(rotation);

    for(int h=0;h<5;h++){
//            targetPosition.x += ((rand()%50)-25);
//            targetPosition.y += ((rand()%50)-25);
        if(otherPosition[h].x-currentPosition.x > 0 ) targetPosition.x -= (rand()%50);
        else targetPosition.x +=(rand()%50);
        if(otherPosition[h].y-currentPosition.y > 0 ) targetPosition.y -= (rand()%50);
        else targetPosition.y += (rand()%50);
    }



    if(targetPosition.x-currentPosition.x > 0 ) targetPosition.x -= 40;
    else targetPosition.x += 40;
    if(targetPosition.y-currentPosition.y > 0 ) targetPosition.y -= 40;
    else targetPosition.y += 40;
    sf::Vector2f normalized = (targetPosition  - currentPosition);
    float distance = std::sqrt(normalized.x * normalized.x + normalized.y * normalized.y);
    if(distance > 20.f){
        normalized /= distance;
        redAnt->move(normalized * (float)frameInfo.delta * 800.f);
    }
}

void Enemy::setEnemy(float x, float y) {
    redAnt->setPosition(x,y);
}

Enemy::~Enemy() {
    delete redAnt;
}

void Enemy::setHP(double timeGame, GameBar gameBarF) {
    if(timeGame > hpTimeHelp){
        hpTimeHelp = 0;
        if(hpEnemy > 0){
            hpTimeHelp += (timeGame + 1);
            hpEnemy -= gameBarF.getAttackEnemiesAmount();
        }

    }
    if(hpEnemy == 0){
        redAnt->setPosition(-500,-500);
    }
}

sf::Sprite* Enemy::getPtr() {
    return redAnt;
}

int Enemy::getHp() {
    return hpEnemy;
}
