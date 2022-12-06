//
// Created by AdiAs on 17.11.2022.
//

#ifndef ZALICZENIE2_BUTTON_H
#define ZALICZENIE2_BUTTON_H

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "GameState.h"
#include <cmath>
#include <iostream>


class Button {
private:
    sf::Texture mButtonTexture;
    sf::RectangleShape mButton;
    sf::Text mText;
    sf::Font mFont;
    sf::Vector2f positions;
public:
    virtual void Render(sf::RenderWindow *window);
    static sf::Vector2f round(sf::Vector2f vector);
    Button(float posX, float posY, const std::string &Text);

    int buttonClicked(sf::RenderWindow *window);
};


#endif //ZALICZENIE2_BUTTON_H
