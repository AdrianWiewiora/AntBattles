#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

#include "Menu.h"

class Game {
private:
    //Variables
    sf::RenderWindow *window{};
    sf::Event sfEvent{};
    sf::Clock clock;
    sf::RectangleShape tlo;
    sf::Sprite ant1;

    Menu menu;
    //Initialization
    void initWindow();

public:
    //Constructors
    Game();

    //Functions
    void updateSFMLEvents();
    void update();
    void render();
    void run();

};

