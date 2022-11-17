//
// Created by AdiAs on 17.11.2022.
//

#include "Button.h"

void Button::MakeB(float posX,float posY) {
    mButton.setPosition(posX,posY);
    mButton.setFillColor(sf::Color::Blue);
    mButton.setOutlineColor(sf::Color::White);
    mButton.setSize(sf::Vector2f(50,50));
}
void Button::Render(sf::RenderWindow *window) {
    window->draw(mButton);
}