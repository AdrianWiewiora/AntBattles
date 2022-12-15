//
// Created by AdiAs on 17.11.2022.
//
#include "Button.h"

void Button::Render(sf::RenderWindow *window) {
    window->draw(mButton);
    window->draw(mText);
}

sf::Vector2f Button::round(const sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

Button::Button(float posX, float posY, const std::string &Text) {
    mButton.setPosition(posX,posY);
    mButtonTexture.loadFromFile("../images/buttonTexture1.png");
    mButton.setTexture(&mButtonTexture);
    mButton.setSize(sf::Vector2f(300,75));
    mButton.setOrigin(150,37.5);
    mText.setString(Text);
    mText.setCharacterSize(50);
    mText.setFont(mFont);
    mFont.loadFromFile("../fonts/CalibriRegular.ttf");
    mText.setFillColor(sf::Color::Cyan);

    auto center = mText.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + mText.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    mText.setOrigin(rounded);
    mText.setPosition(posX,posY);

    positions = mButton.getPosition();
}

int Button::buttonClicked(sf::RenderWindow *window) {
    if(sf::Mouse::getPosition(*window).x < (positions.x + 150) && sf::Mouse::getPosition(*window).x > (positions.x - 150) && sf::Mouse::getPosition(*window).y < (positions.y + 37.5) && sf::Mouse::getPosition(*window).y > (positions.y - 37.5)){
        return 1;
    }
    else return 0;
}

void Button::setButton(float positionX, float positionY, float widthX, float heightY) {
    mButton.setSize(sf::Vector2f(widthX,heightY));
    mButton.setOrigin(widthX/2,heightY/2);

    auto center = mText.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + mText.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    mText.setOrigin(rounded);
    mText.setCharacterSize(heightY);

    mButton.setPosition(positionX,positionY);
    mText.setPosition(positionX,positionY);

    positions = mButton.getPosition();
}

int Button::buttonClickedMap(sf::RenderWindow *window,float widthX, float heightY) {
    sf::Vector2f helpPos;
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
    helpPos = window->mapPixelToCoords(mousePosition);
    if(helpPos.x < (positions.x + widthX/2) && helpPos.x > (positions.x - widthX/2) && helpPos.y < (positions.y + heightY/2) && helpPos.y > (positions.y - heightY/2)){
        return 1;
    }
    else return 0;
}
