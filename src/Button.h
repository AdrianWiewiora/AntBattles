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
    sf::RectangleShape mButton;
public:
    void MakeB(float posX,float posY);
    virtual void Render(sf::RenderWindow *window);
};


#endif //ZALICZENIE2_BUTTON_H
