//
// Created by AdiAs on 16.12.2022.
//

#ifndef ZALICZENIE2_UPGRADEMENU_H
#define ZALICZENIE2_UPGRADEMENU_H

#include "SFML/Graphics.hpp"
#include "SFML/Graphics.hpp"

class UpgradeMenu{
private:
    sf::RectangleShape mTloUpgradeMenu;
public:
    UpgradeMenu();
    void showUpgradeMenu(sf::View view);
    void drawUpgradeMenu(sf::RenderWindow *window);
};


#endif //ZALICZENIE2_UPGRADEMENU_H
