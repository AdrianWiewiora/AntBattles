//
// Created by AdiAs on 16.12.2022.
//

#ifndef ZALICZENIE2_UPGRADEMENU_H
#define ZALICZENIE2_UPGRADEMENU_H

#include "SFML/Graphics.hpp"
#include "SFML/Graphics.hpp"
#include "Button.h"
#include "GameBar.h"

class UpgradeMenu{
private:
    sf::RectangleShape mTloUpgradeMenu;
    Button mButton1{1500,200,"Upgrade Attack -10"};
    Button mButton2{1500,300,"Upgrade Healing -10"};
public:
    UpgradeMenu();
    void showUpgradeMenu(sf::View view,sf::RenderWindow *window, GameBar gameBarUp, double timeGame);
    void drawUpgradeMenu(sf::RenderWindow *window);
    Button getButtonUpgradeAttack();
    Button getButtonUpgradeHealing();
    sf::RectangleShape getTlo();
};


#endif //ZALICZENIE2_UPGRADEMENU_H
