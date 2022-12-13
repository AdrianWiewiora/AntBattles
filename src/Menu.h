#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "GameState.h"
#include "Button.h"

#include "AntGame.h"
#include "MenuOptions.h"
#include "FrameInfo.h"

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Menu : GameState {
private:
    sf::Texture Mrowka;
    sf::RectangleShape Tlo;
    Button m_Button1{1450.0,187.5,"Start"};
    Button m_Button2{1450.0,287.5,"Options"};
    Button m_Button3{1450.0,387.5,"Exit"};

    double m_lifetime = 60;

public:
    Menu();
    virtual void Render(sf::RenderWindow *window) override;
    virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo) override;
};
