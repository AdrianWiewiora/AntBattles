//
// Created by AdiAs on 15.11.2022.
//

#include "Ant.h"

Ant::Ant() {
    textureAnt.loadFromFile("../images/ant1.png");
    ant.setTexture(textureAnt);
    ant.setOrigin(sf::Vector2f(ant.getTexture()->getSize().x * 0.5,ant.getTexture()->getSize().y * 0.5));
    ant.setScale(sf::Vector2f(0.2f, 0.2f));
    ant.setPosition(1000, 1500);
    targetPosition.x = 1000;
    targetPosition.y = 1500;
}

sf::Vector2f Ant::getPositionAnt() {
    return ant.getPosition();
}

void Ant::setRotationAnt(sf::RenderWindow *window) {
    sf::Vector2f helpPos;
    sf::Vector2f currentPosition = ant.getPosition();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    helpPos = window->mapPixelToCoords(mousePosition);
    const float PI = 3.14159265;
    float a = currentPosition.x - helpPos.x;
    float b = currentPosition.y - helpPos.y;
    float rotation = ( atan2( b, a ) ) * 180 / PI;
    rotation -= 90;
    ant.setRotation(rotation);
}

void Ant::drawAnt(sf::RenderWindow *window) {
    window->draw(ant);
}

void Ant::moveAnt(FrameInfo &frameInfo) {

    sf::Vector2f currentPosition = ant.getPosition();
    sf::Vector2f normalized = (targetPosition - currentPosition);
    float distance = std::sqrt(normalized.x * normalized.x + normalized.y * normalized.y);
    if(distance > 20.f){
        normalized /= distance;
        ant.move(normalized * (float)frameInfo.delta * 1000.f);
    }
    //std::cout<<targetPosition.x << " " << targetPosition.y <<std::endl;

//    sf::Vector2f helpPos;
//    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
//    float a,b,distance,sinA,sinB,alfa,beta,Pi = 3.14159265359;
//    helpPos = window->mapPixelToCoords(mousePosition);
//    a = helpPos.x - currentPosition.x;
//    b = currentPosition.y - helpPos.y;
//    distance = a*a + b*b;
//    distance = sqrtf(distance);
//    sinA = b/distance;
//    sinB = a / distance;
//    alfa = asinf(sinA);
//    beta = asinf(sinB);
//    alfa = alfa * (180/Pi);
//    beta = beta * (180/Pi);
    //ant.move((beta/90) *frameInfo.delta *1000,(alfa/90)*frameInfo.delta * -1000);
}




//void Ant::moveKeyboard(FrameInfo &frameInfo) {
//    float rotation = ant.getRotation();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        ant.move(-100*frameInfo.delta, 0);
//        if(rotation<270 && rotation>=90){ant.rotate(60*frameInfo.delta);}
//        else if(rotation>270 || rotation<=90){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        ant.move(100*frameInfo.delta, 0);
//        if(rotation<=270 && rotation>90){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation>=270 || rotation<90){ant.rotate(60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        ant.move(0, -100*frameInfo.delta);
//        if(rotation<=180 && rotation>0){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation>=180 || rotation<0){ant.rotate(60*frameInfo.delta);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        ant.move(0, 100*frameInfo.delta);
//        if(rotation<180 && rotation>=0){ant.rotate(60*frameInfo.delta);}
//        else if(rotation>180 || rotation<=0){ant.rotate(-60*frameInfo.delta);}
//    }
//}

//void Ant::rotationSteering(FrameInfo &frameInfo) {
//    float rotation = ant.getRotation();
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        if(rotation<315 && rotation>=135){ant.rotate(60*frameInfo.delta);}
//        else if(rotation>315 || rotation<=135){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        if(rotation<225 && rotation>=45){ant.rotate(60*frameInfo.delta);}
//        else if(rotation>225 || rotation<=45){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        if(rotation<=225 && rotation>45){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation>=225 || rotation<45){ant.rotate(60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        if(rotation<=315 && rotation>135){ant.rotate(-60*frameInfo.delta);}
//        else if(rotation>=315 || rotation<135){ant.rotate(60*frameInfo.delta);}
//        else if(rotation==0){ant.setRotation(360);}
//    }
//}
