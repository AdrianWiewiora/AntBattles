#ifndef ZALICZENIE2_GAMEBAR_H
#define ZALICZENIE2_GAMEBAR_H

#include "SFML/Graphics.hpp"
#include <cmath>
#include "Button.h"

class GameBar {
private:
    sf::RectangleShape resourcesBar,hpOnGameBar, attackPlayer, attackEnemy;
    sf::Vector2f sizeResourcesBar,sizeHpIcon, sizeAttackIcon;
    sf::CircleShape blueResources;
    sf::CircleShape greenResources;
    sf::Text blueResourcesAmountBar,greenResourcesAmountBar,hpAmountTextBar,attackPlayerAmountBar,attackEnemyAmountBar;
    sf::Font mFont;
    sf::Texture textureHpIcon, textureAttackPlayer, textureAttackEnemy;
    std::string help,help1;
    int blueResourcesAmount,greenResourcesAmount,hpAmount,attackPlayerAmount,attackEnemyAmount, hpAddAmount = 3;
    Button m_Button1{1450.0,387.5,"Exit"};
    double timeHelpHp = 0,timeHelpHPAttack = 0, timeHelpBuyUpgradeAttack = 0, timeHelpBuyUpgradeHealing = 0;
public:
    GameBar();
    static sf::Vector2f round(sf::Vector2f vector);
    void drawGameBar(sf::RenderWindow *window);
    sf::Vector2f getSizeGameBar();
    void setGameBar(sf::View view,sf::RenderWindow *window);
    void setGreenResource();
    void setBlueResource();
    void setHp(sf::Vector2f antPosition,double timeGame);
    void attackHP(double timeGame);
    int getHpAmount();
    int getAttackEnemiesAmount();
    void buyUpgradePlayerAttack(double timeGame);
    void buyUpgradePlayerHealing(double timeGame);
};


#endif //ZALICZENIE2_GAMEBAR_H
