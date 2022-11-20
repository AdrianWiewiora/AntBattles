#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameState.h"
#include "Button.h"

#include "AntGame.h"
#include "MenuOptions.h"

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Menu : GameState {
private:
    sf::Texture Mrowka;
    sf::RectangleShape Tlo;
    Button m_Button1;
    Button m_Button2;
    Button m_Button3;

    double m_lifetime = 50;

public:
    Menu();
    virtual void Render(sf::RenderWindow *window) override;
    virtual void Input(sf::RenderWindow *window) override;
    virtual void Update(sf::RenderWindow *window, float delta) override;
};
