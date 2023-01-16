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

void UpgradeMenu::showUpgradeMenu(sf::View view,sf::RenderWindow *window, GameBar gameBarUp, double timeGame) {
    mTloUpgradeMenu.setPosition(view.getCenter());
    mTloUpgradeMenu.setSize(sf::Vector2f(view.getSize().x/1.4f,view.getSize().y/1.4f));
    mTloUpgradeMenu.setOrigin(mTloUpgradeMenu.getSize().x/2,mTloUpgradeMenu.getSize().y/2);

    mButton1.setButton(mTloUpgradeMenu.getPosition().x - mTloUpgradeMenu.getSize().x/3.2,mTloUpgradeMenu.getPosition().y - mTloUpgradeMenu.getSize().y/2.2,mTloUpgradeMenu.getSize().x/3,mTloUpgradeMenu.getSize().y/15);
    mButton2.setButton(mTloUpgradeMenu.getPosition().x - mTloUpgradeMenu.getSize().x/3.2,mTloUpgradeMenu.getPosition().y - mTloUpgradeMenu.getSize().y/2.8,mTloUpgradeMenu.getSize().x/3,mTloUpgradeMenu.getSize().y/15);
}

void UpgradeMenu::drawUpgradeMenu(sf::RenderWindow *window) {
    window->draw(mTloUpgradeMenu);
    mButton1.Render(window);
    mButton2.Render(window);
}

Button UpgradeMenu::getButtonUpgradeAttack() {
    return mButton1;
}

sf::RectangleShape UpgradeMenu::getTlo() {
    return mTloUpgradeMenu;
}

Button UpgradeMenu::getButtonUpgradeHealing() {
    return mButton2;
}


