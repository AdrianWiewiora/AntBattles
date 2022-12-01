#include <iostream>
#include "AntGame.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/Mouse.hpp"

AntGame::AntGame() {
    Torf.loadFromFile("../images/mapTexture1.png");

    tlo.setSize(sf::Vector2f(3840.0, 5400.0));
    tlo.setTexture(&Torf);
    view1.setSize(1920,1080);
    view1.setCenter(1000,1000);

    t.loadFromFile("../images/ant1.png");

    // ant1.setOrigin(2000,2000);

    ant1.setTexture(t);
    ant1.setOrigin(sf::Vector2f(ant1.getTexture()->getSize().x * 0.5,ant1.getTexture()->getSize().y * 0.5));
    ant1.setScale(sf::Vector2f(0.2f, 0.2f));
    ant1.setPosition(500, 500);
}

void AntGame::Input(sf::RenderWindow *window) {}
void AntGame::Update(sf::RenderWindow *window, float delta) {


    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        pozX = sf::Mouse::getPosition().x;
        pozY = sf::Mouse::getPosition().y;
        //ant1.setPosition(pozX,pozY);

        vectX = pozX-ant1.getPosition().x;
        vectY= pozY-ant1.getPosition().y;

        ant1.move(sf::Vector2f(vectX*delta,vectY*delta));

        //ant1.move(((pozX-ant1.getPosition().x)/100)*delta,((pozY-ant1.getPosition().y)/100)*delta);
    }

/*    if (mouseWheel.type == sf::Event::MouseWheelScrolled)
    {
        if(mouseWheel.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
        {
            view1.zoom(0.999f);
            std::cout << "dupa";
        }
        else if(mouseWheel.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
        {
            view1.zoom(1.001f);
        }
    }*/
    if(mouseWheel.type == sf::Event::MouseWheelScrolled)
    {
        if(mouseWheel.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
            std::cout << "wheel type: vertical" << std::endl;
        else if(mouseWheel.mouseWheelScroll.wheel == sf::Mouse::HorizontalWheel)
            std::cout << "wheel type: horizontal" << std::endl;
        else
            std::cout << "wheel type: unknown" << std::endl;

        std::cout << "wheel movement: " << mouseWheel.mouseWheelScroll.delta << std::endl;
        std::cout << "mouse x: " << mouseWheel.mouseWheelScroll.x << std::endl;
        std::cout << "mouse y: " << mouseWheel.mouseWheelScroll.y << std::endl;
    }



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)) {
        view1.zoom(0.999f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) {
        view1.zoom(1.001f);
    }


//    if (vectX < 0) speedX = -100;
//    else speedX = 100;
//
//    if (vectY < 0) speedY = -100;
//    else speedY = 100;
//
//    if(ant1.getPosition().x != pozX && ant1.getPosition().y != pozY) {
//        ant1.move(speedX * delta, speedY * delta);
//    }

    float rotation;
    rotation = ant1.getRotation();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        ant1.move(-100*delta, 0);
        if(rotation<270 && rotation>=90){ant1.rotate(60*delta);}
        else if(rotation>270 || rotation<=90){ant1.rotate(-60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        ant1.move(100*delta, 0);
        if(rotation<=270 && rotation>90){ant1.rotate(-60*delta);}
        else if(rotation>=270 || rotation<90){ant1.rotate(60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        ant1.move(0, -100*delta);
        if(rotation<=180 && rotation>0){ant1.rotate(-60*delta);}
        else if(rotation>=180 || rotation<0){ant1.rotate(60*delta);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        ant1.move(0, 100*delta);
        if(rotation<180 && rotation>=0){ant1.rotate(60*delta);}
        else if(rotation>180 || rotation<=0){ant1.rotate(-60*delta);}
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(rotation<315 && rotation>=135){ant1.rotate(60*delta);}
        else if(rotation>315 || rotation<=135){ant1.rotate(-60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(rotation<225 && rotation>=45){ant1.rotate(60*delta);}
        else if(rotation>225 || rotation<=45){ant1.rotate(-60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(rotation<=225 && rotation>45){ant1.rotate(-60*delta);}
        else if(rotation>=225 || rotation<45){ant1.rotate(60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(rotation<=315 && rotation>135){ant1.rotate(-60*delta);}
        else if(rotation>=315 || rotation<135){ant1.rotate(60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
}

void AntGame::Render(sf::RenderWindow *window) {
    window->setView(view1);
    window->draw(tlo);
    window->draw(ant1);
}
