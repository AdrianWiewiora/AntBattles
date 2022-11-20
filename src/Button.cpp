//
// Created by AdiAs on 17.11.2022.
//

#include "Button.h"

void Button::MakeB(float posX,float posY) {
    mButton.setPosition(posX,posY);
    mButtonTexture.loadFromFile("../images/buttonTexture1.png");
    mButton.setTexture(&mButtonTexture);
    mButton.setSize(sf::Vector2f(300,75));
    mButton.setOrigin(150,37.5);
}
void Button::Render(sf::RenderWindow *window) {
    window->draw(mButton);
    window->draw(mText);
}

void Button::SetTex(const std::string& Text,float pozX,float pozY) {
    mText.setString(Text);
    mText.setCharacterSize(50);
    //mText.setPosition(pozX,pozY);
    mText.setFont(mFont);
    mFont.loadFromFile("../fonts/CalibriRegular.ttf");
    mText.setFillColor(sf::Color::Cyan);

    auto center = mText.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + mText.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    mText.setOrigin(rounded);
    mText.setPosition(pozX,pozY);
}

sf::Vector2f Button::round(const sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}