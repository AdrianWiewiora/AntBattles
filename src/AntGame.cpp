#include "AntGame.h"
#include "SFML/Window/Keyboard.hpp"

AntGame::AntGame() {
    Torf.loadFromFile("../images/torf2.png");

    tlo.setSize(sf::Vector2f(1920.0, 1080.0));
    tlo.setTexture(&Torf);

    t.loadFromFile("../images/ant1.png");

    // ant1.setOrigin(2000,2000);

    ant1.setTexture(t);
    ant1.setOrigin(sf::Vector2f(ant1.getTexture()->getSize().x * 0.5,ant1.getTexture()->getSize().y * 0.5));
    ant1.setScale(sf::Vector2f(0.2f, 0.2f));
    ant1.setPosition(500, 500);
}

void AntGame::Input(sf::RenderWindow *window) {}
void AntGame::Update(sf::RenderWindow *window, double delta) {
    int rotation;
    rotation = ant1.getRotation();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        ant1.move(-100*delta, 0);
        if(rotation<=270 && rotation>=90){ant1.rotate(60*delta);}
        else if(rotation>=270 || rotation<=90){ant1.rotate(-60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        ant1.move(100*delta, 0);
        if(rotation<=270 && rotation>=90){ant1.rotate(-60*delta);}
        else if(rotation>=270 || rotation<=90){ant1.rotate(60*delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        ant1.move(0, -100*delta);
        if(rotation<=180 && rotation>=0){ant1.rotate(-60*delta);}
        else if(rotation>=180 || rotation<=0){ant1.rotate(60*delta);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        ant1.move(0, 100*delta);
        if(rotation<=180 && rotation>=0){ant1.rotate(60*delta);}
        else if(rotation>=180 || rotation<=0){ant1.rotate(-60*delta);}
    }
}

void AntGame::Render(sf::RenderWindow *window) {
    window->draw(tlo);
    window->draw(ant1);
}
