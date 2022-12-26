//
// Created by AdiAs on 26.12.2022.
//

#include "Enemy.h"

Enemy::Enemy() {
    textureAnt.loadFromFile("../images/ant3.png");
    enemy.setTexture(textureAnt);
    enemy.setOrigin(sf::Vector2f(enemy.getTexture()->getSize().x * 0.5,enemy.getTexture()->getSize().y * 0.5));
    enemy.setScale(sf::Vector2f(0.2f, 0.2f));
    enemy.setPosition(1300, 1500);
}

sf::Vector2f Enemy::getPositionEnemy() {
    return enemy.getPosition();
}

void Enemy::drawEnemy(sf::RenderWindow *window) {
    window->draw(enemy);
}

void Enemy::moveEnemy(FrameInfo &frameInfo, sf::RenderWindow *window,sf::Vector2f targetPosition) {
    sf::Vector2f currentPosition = enemy.getPosition();
    if(targetPosition.x-currentPosition.x > 0 ) targetPosition.x -= 100;
    else targetPosition.x += 100;
    if(targetPosition.y-currentPosition.y > 0 ) targetPosition.y -= 100;
    else targetPosition.y += 100;
    sf::Vector2f normalized = (targetPosition  - currentPosition);
    float distance = std::sqrt(normalized.x * normalized.x + normalized.y * normalized.y);
    if(distance > 20.f){
        normalized /= distance;
        enemy.move(normalized * (float)frameInfo.delta * 800.f);
    }
    //Rotation
    const float PI = 3.14159265;
    float a = currentPosition.x - targetPosition.x;
    float b = currentPosition.y - targetPosition.y;
    float rotation = ( atan2( b, a ) ) * 180 / PI;
    rotation -= 90;
    enemy.setRotation(rotation);
}

void Enemy::setEnemy(float x, float y) {
    enemy.setPosition(x,y);
}
