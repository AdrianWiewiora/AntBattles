#ifndef ZALICZENIE2_GAMEBAR_H
#define ZALICZENIE2_GAMEBAR_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include "Button.h"

class GameBar {
private:
    sf::RectangleShape resourcesBar,hpOnGameBar;
    sf::Vector2f sizeResourcesBar,sizeHpIcon;
    sf::CircleShape blueResources;
    sf::CircleShape greenResources;
    sf::Text blueResourcesAmountBar,greenResourcesAmountBar,hpAmountTextBar;
    sf::Font mFont;
    sf::Texture textureHpIcon;
    std::string help,help1;
    int blueResourcesAmount,greenResourcesAmount,hpAmount;
    Button m_Button1{1450.0,387.5,"Exit"};
    double timeHelpHp = 0;
public:
    GameBar();
    static sf::Vector2f round(sf::Vector2f vector);
    void drawGameBar(sf::RenderWindow *window);
    sf::Vector2f getSizeGameBar();
    void setGameBar(sf::View view,sf::RenderWindow *window);
    void setGreenResource();
    void setBlueResource();
    void setHp(sf::Vector2f antPosition,double timeGame);
    void attackHP();
};


#endif //ZALICZENIE2_GAMEBAR_H
