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


class Button {
private:
    sf::Texture mButtonTexture;
    sf::RectangleShape mButton;
    sf::Text mText;
    sf::Font mFont;
public:
    void MakeB(float posX,float posY);
    void SetTex(std::string Text,float pozX,float pozY);
    virtual void Render(sf::RenderWindow *window);
};


#endif //ZALICZENIE2_BUTTON_H
