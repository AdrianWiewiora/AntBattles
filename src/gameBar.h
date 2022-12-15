#ifndef ZALICZENIE2_GAMEBAR_H
#define ZALICZENIE2_GAMEBAR_H

#include "SFML/Graphics.hpp"
#include <cmath>

class gameBar {
private:
    sf::RectangleShape resourcesBar;
    sf::Vector2f sizeResourcesBar;
    sf::CircleShape redResources;
    sf::CircleShape greenResources;
    sf::Text redResourcesAmountBar,greenResourcesAmountBar;
    sf::Font mFont;
    int redResourcesAmount,greenResourcesAmount;
public:
    gameBar();
    static sf::Vector2f round(sf::Vector2f vector);
    void drawGameBar(sf::RenderWindow *window);
    sf::Vector2f getSizeGameBar();
    void setGameBar(sf::View view);

};


#endif //ZALICZENIE2_GAMEBAR_H
