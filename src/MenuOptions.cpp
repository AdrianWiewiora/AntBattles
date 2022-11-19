//
// Created by Adrian on 19.11.2022.
//


#include "MenuOptions.h"


void MenuOptions::Input(sf::RenderWindow *window) {}
void MenuOptions::Update(sf::RenderWindow *window, float delta) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 280 && sf::Mouse::getPosition().y < 355){
            m_queued_game_state = (GameState *)new Menu();
        }
    }

}

void MenuOptions::Render(sf::RenderWindow *window) {
    window->draw(mShapeTlo);
    window->draw(mRactangleTloTransparent);
    window->draw(mSelectDifLevelText);
}

MenuOptions::MenuOptions() {


    mTloMenuTexture.loadFromFile("../images/img1.jpg");
    mShapeTlo.setSize(sf::Vector2f(1920.0, 1080.0));
    mShapeTlo.setTexture(&mTloMenuTexture);
    mRactangleTloTransparent.setSize(sf::Vector2f(1920.0, 1080.0));
    mRactangleTloTransparent.setFillColor(sf::Color(0,0,0,180));
    mSelectDifLevelText.setFillColor(sf::Color::White);
    mSelectDifLevelText.setFont(mFontOptions);
    mFontOptions.loadFromFile("../fonts/CalibriRegular.ttf");
    mSelectDifLevelText.setCharacterSize(50);
    mSelectDifLevelText.setString("Select Difficult Level");


    auto center = mSelectDifLevelText.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + mSelectDifLevelText.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    mSelectDifLevelText.setOrigin(rounded);
    mSelectDifLevelText.setPosition(960,140);

}

sf::Vector2f MenuOptions::round(const sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}
