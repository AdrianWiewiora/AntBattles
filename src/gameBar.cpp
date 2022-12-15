//
// Created by AdiAs on 15.12.2022.
//

#include "gameBar.h"

sf::Vector2f gameBar::round(sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

gameBar::gameBar() {
    sf::Color colorResourcesBar(47, 152, 145);
    sizeResourcesBar.x = 1080;
    sizeResourcesBar.y = 50;
    resourcesBar.setFillColor(colorResourcesBar);
    resourcesBar.setSize(sizeResourcesBar);

    redResources.setRadius(20.0);
    redResources.setFillColor(sf::Color::Blue);
    greenResources.setRadius(20.0);
    greenResources.setFillColor(sf::Color::Green);

    redResourcesAmount = 0;
    greenResourcesAmount = 0;
    redResourcesAmountBar.setString(std::to_string(redResourcesAmount));
    redResourcesAmountBar.setCharacterSize(20);
    redResourcesAmountBar.setFont(mFont);
    mFont.loadFromFile("../fonts/CalibriRegular.ttf");
    redResourcesAmountBar.setFillColor(sf::Color::Black);
    greenResourcesAmountBar.setString(std::to_string(greenResourcesAmount));
    greenResourcesAmountBar.setCharacterSize(20);
    greenResourcesAmountBar.setFont(mFont);
    greenResourcesAmountBar.setFillColor(sf::Color::Black);
}

void gameBar::drawGameBar(sf::RenderWindow *window) {
    window->draw(resourcesBar);
    window->draw(redResources);
    window->draw(greenResources);
    window->draw(redResourcesAmountBar);
    window->draw(greenResourcesAmountBar);
}

sf::Vector2f gameBar::getSizeGameBar() {
    return sizeResourcesBar;
}

void gameBar::setGameBar(sf::View view) {
    //Function gameBar
    sizeResourcesBar = view.getSize();
    sizeResourcesBar.y /= 25;
    resourcesBar.setPosition(view.getCenter().x-view.getSize().x/2,view.getCenter().y +1 -view.getSize().y/2);
    resourcesBar.setSize(sizeResourcesBar);

    //Function resourcesIconsOnBar
    redResources.setOrigin(redResources.getRadius(),redResources.getRadius());
    redResources.setPosition(resourcesBar.getPosition().x+(resourcesBar.getSize().x/80),resourcesBar.getPosition().y+(resourcesBar.getSize().y/2));
    redResources.setRadius(resourcesBar.getSize().y/2.3);

    greenResources.setOrigin(redResources.getRadius(),redResources.getRadius());
    greenResources.setPosition(resourcesBar.getPosition().x+2*(resourcesBar.getSize().x/30),resourcesBar.getPosition().y+(resourcesBar.getSize().y/2));
    greenResources.setRadius(resourcesBar.getSize().y/2.3);

    //Function resources amount on bar
    auto center = redResourcesAmountBar.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + redResourcesAmountBar.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    redResourcesAmountBar.setOrigin(rounded);
    redResourcesAmountBar.setPosition(resourcesBar.getPosition().x+1.2*(resourcesBar.getSize().x/30),resourcesBar.getPosition().y+(resourcesBar.getSize().y/2));
    redResourcesAmountBar.setCharacterSize(resourcesBar.getSize().y);

    greenResourcesAmountBar.setOrigin(rounded);
    greenResourcesAmountBar.setPosition(resourcesBar.getPosition().x+2.8*(resourcesBar.getSize().x/30),resourcesBar.getPosition().y+(resourcesBar.getSize().y/2));
    greenResourcesAmountBar.setCharacterSize(resourcesBar.getSize().y);

    //Function steering resources Amount


}
