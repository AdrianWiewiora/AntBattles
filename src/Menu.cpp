#include "Menu.h"
#include <windows.h>


void Menu::renderM(sf::RenderWindow *Window) {
    Window->clear();

    Mrowka.loadFromFile("../images/img1.jpg");
    sf::RectangleShape Tlo;
    Tlo.setSize(sf::Vector2f(1920.0,1080.0));
    Tlo.setTexture(&Mrowka);

    Window->draw(Tlo);

    Window->display();

    Sleep(1000);
    Window->close();
}
