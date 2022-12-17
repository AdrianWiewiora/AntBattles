//
// Created by AdiAs on 16.12.2022.
//

#include "UpgradeMenu.h"

UpgradeMenu::UpgradeMenu() {
    mTloUpgradeMenu.setSize(sf::Vector2f(100,100));
    sf::Color mColorUpgradeMenu(222,150,25);
    mTloUpgradeMenu.setFillColor(mColorUpgradeMenu);
    mTloUpgradeMenu.setOrigin(50,50);
}

void UpgradeMenu::showUpgradeMenu(sf::View view) {
    mTloUpgradeMenu.setPosition(view.getCenter());
    mTloUpgradeMenu.setSize(sf::Vector2f(view.getSize().x/1.4f,view.getSize().y/1.4f));
    mTloUpgradeMenu.setOrigin(mTloUpgradeMenu.getSize().x/2,mTloUpgradeMenu.getSize().y/2);
}

void UpgradeMenu::drawUpgradeMenu(sf::RenderWindow *window) {
    window->draw(mTloUpgradeMenu);
}


