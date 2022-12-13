//
// Created by Adrian on 19.11.2022.
//


#include "MenuOptions.h"


void MenuOptions::Input(sf::RenderWindow *window) {}
void MenuOptions::Update(sf::RenderWindow *window, FrameInfo &frameInfo) {

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition().x < 1110 && sf::Mouse::getPosition().x > 810 && sf::Mouse::getPosition().y > 300 && sf::Mouse::getPosition().y < 370){
            GameState::mDifficultyLevel = 1;
            m_queued_game_state = (GameState *)new Menu();
        }
        if(sf::Mouse::getPosition().x < 1110 && sf::Mouse::getPosition().x > 810 && sf::Mouse::getPosition().y > 400 && sf::Mouse::getPosition().y < 470){
            GameState::mDifficultyLevel = 2;
            m_queued_game_state = (GameState *)new Menu();
        }
        if(sf::Mouse::getPosition().x < 1110 && sf::Mouse::getPosition().x > 810 && sf::Mouse::getPosition().y > 500 && sf::Mouse::getPosition().y < 570){
            GameState::mDifficultyLevel = 3;
            m_queued_game_state = (GameState *)new Menu();
        }
    }

}

void MenuOptions::Render(sf::RenderWindow *window) {
    window->draw(mShapeTlo);
    window->draw(mRactangleTloTransparent);
    window->draw(mSelectDifLevelText);
    m_ButtonOptions1.Render(window);
    m_ButtonOptions2.Render(window);
    m_ButtonOptions3.Render(window);
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

