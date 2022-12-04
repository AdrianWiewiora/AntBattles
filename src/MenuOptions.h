//
// Created by Adrian on 19.11.2022.
//

#ifndef ZALICZENIE2_MENUOPTIONS_H
#define ZALICZENIE2_MENUOPTIONS_H

#include <iostream>
#include <cmath>

#include "GameState.h"
#include "Button.h"
#include "Menu.h"

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"


class MenuOptions : GameState {
private:
    sf::Texture mTloMenuTexture;
    sf::RectangleShape mShapeTlo;
    sf::RectangleShape mRactangleTloTransparent;
    sf::Text mSelectDifLevelText;
    sf::Font mFontOptions;
    Button m_ButtonOptions1;
    Button m_ButtonOptions2;
    Button m_ButtonOptions3;

public:
    MenuOptions();
    void Render(sf::RenderWindow *window) override;
    void Input(sf::RenderWindow *window) override;
    void Update(sf::RenderWindow *window, FrameInfo &frameInfo) override;

    static sf::Vector2f round(sf::Vector2f vector);
};


#endif //ZALICZENIE2_MENUOPTIONS_H
