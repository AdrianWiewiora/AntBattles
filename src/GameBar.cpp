//
// Created by AdiAs on 15.12.2022.
//

#include "GameBar.h"

sf::Vector2f GameBar::round(sf::Vector2f vector) {
    return sf::Vector2f{ std::round(vector.x), std::round(vector.y) };
}

GameBar::GameBar() {
    sf::Color colorResourcesBar(47, 152, 145);
    sizeResourcesBar.x = 1080;
    sizeResourcesBar.y = 50;
    resourcesBar.setFillColor(colorResourcesBar);
    resourcesBar.setSize(sizeResourcesBar);

    blueResources.setRadius(20.0);
    blueResources.setFillColor(sf::Color::Blue);
    greenResources.setRadius(20.0);
    greenResources.setFillColor(sf::Color::Green);

    blueResourcesAmount = 0;
    greenResourcesAmount = 0;
    blueResourcesAmountBar.setString(std::to_string(blueResourcesAmount));
    blueResourcesAmountBar.setCharacterSize(20);
    blueResourcesAmountBar.setFont(mFont);
    mFont.loadFromFile("../fonts/CalibriRegular.ttf");
    blueResourcesAmountBar.setFillColor(sf::Color::Black);
    greenResourcesAmountBar.setString(std::to_string(greenResourcesAmount));
    greenResourcesAmountBar.setCharacterSize(20);
    greenResourcesAmountBar.setFont(mFont);
    greenResourcesAmountBar.setFillColor(sf::Color::Black);
    //HP
    sizeHpIcon.x = 80;
    sizeHpIcon.y = 80;
    hpOnGameBar.setSize(sizeHpIcon);
    textureHpIcon.loadFromFile("../images/hpTextureGameBar.png");
    hpOnGameBar.setTexture(&textureHpIcon);
    hpAmount = 50;
    hpAmountTextBar.setString(std::to_string(hpAmount));
    help = hpAmountTextBar.getString();
    help1 = help + "\\100";
    hpAmountTextBar.setString(help1);
    hpAmountTextBar.setCharacterSize(20);
    hpAmountTextBar.setFont(mFont);
    hpAmountTextBar.setFillColor(sf::Color::Black);

    //AttackOnGameBar
    textureAttackEnemy.loadFromFile("../images/attackiconEnemy.png");
    textureAttackPlayer.loadFromFile("../images/attackIconPlayer.png");
    attackEnemy.setTexture(&textureAttackEnemy);
    attackPlayer.setTexture(&textureAttackPlayer);
    sizeAttackIcon.x = 200;
    sizeAttackIcon.y = 200;
    attackEnemy.setSize(sizeAttackIcon);
    attackPlayer.setSize(sizeAttackIcon);
    attackEnemyAmount = 1;
    attackPlayerAmount = 5;
    attackPlayerAmountBar.setString(std::to_string(attackPlayerAmount));
    attackEnemyAmountBar.setString(std::to_string(attackEnemyAmount));
    attackPlayerAmountBar.setCharacterSize(20);
    attackPlayerAmountBar.setFont(mFont);
    attackPlayerAmountBar.setFillColor(sf::Color::Black);
    attackEnemyAmountBar.setCharacterSize(20);
    attackEnemyAmountBar.setFont(mFont);
    attackEnemyAmountBar.setFillColor(sf::Color::Black);


}

void GameBar::drawGameBar(sf::RenderWindow *window) {
    window->draw(resourcesBar);
    window->draw(blueResources);
    window->draw(greenResources);
    window->draw(blueResourcesAmountBar);
    window->draw(greenResourcesAmountBar);
    window->draw(hpOnGameBar);
    window->draw(hpAmountTextBar);
    window->draw(attackPlayer);
    window->draw(attackEnemy);
    window->draw(attackEnemyAmountBar);
    window->draw(attackPlayerAmountBar);
    m_Button1.Render(window);
}

sf::Vector2f GameBar::getSizeGameBar() {
    return sizeResourcesBar;
}

void GameBar::setGameBar(sf::View view,sf::RenderWindow *window) {
    //Function GameBar
    sizeResourcesBar = view.getSize();
    sizeResourcesBar.y /= 25;
    resourcesBar.setPosition(view.getCenter().x - view.getSize().x / 2, view.getCenter().y + 1 - view.getSize().y / 2);
    resourcesBar.setSize(sizeResourcesBar);

    //Function resourcesIconsOnBar
    blueResources.setOrigin(blueResources.getRadius(), blueResources.getRadius());
    blueResources.setPosition(resourcesBar.getPosition().x + (resourcesBar.getSize().x / 80),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    blueResources.setRadius(resourcesBar.getSize().y / 2.3);

    greenResources.setOrigin(blueResources.getRadius(), blueResources.getRadius());
    greenResources.setPosition(resourcesBar.getPosition().x + 2 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    greenResources.setRadius(resourcesBar.getSize().y / 2.3);

    //Function resources amount on bar
    auto center = blueResourcesAmountBar.getGlobalBounds().getSize() / 2.f;
    auto localBounds = center + blueResourcesAmountBar.getLocalBounds().getPosition();
    auto rounded = round(localBounds);
    blueResourcesAmountBar.setOrigin(rounded);
    blueResourcesAmountBar.setPosition(resourcesBar.getPosition().x + 1.2 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    blueResourcesAmountBar.setCharacterSize(resourcesBar.getSize().y);

    greenResourcesAmountBar.setOrigin(rounded);
    greenResourcesAmountBar.setPosition(resourcesBar.getPosition().x + 2.8 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    greenResourcesAmountBar.setCharacterSize(resourcesBar.getSize().y);

    //Function hp on Bar
    hpOnGameBar.setSize(sf::Vector2f(sizeResourcesBar.y / 1.1,sizeResourcesBar.y / 1.1));
    hpOnGameBar.setOrigin(hpOnGameBar.getSize().x,hpOnGameBar.getSize().y);
    hpOnGameBar.setPosition(resourcesBar.getPosition().x + 4 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y)/1.008);
    hpAmountTextBar.setOrigin(rounded);
    hpAmountTextBar.setPosition(resourcesBar.getPosition().x + 4.5 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    hpAmountTextBar.setCharacterSize(resourcesBar.getSize().y);

    //Function steering Button Exit
    m_Button1.setButton(resourcesBar.getPosition().x + 28.3 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2), sizeResourcesBar.x / 10,sizeResourcesBar.y / 1.1);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (m_Button1.buttonClickedMap(window,sizeResourcesBar.x / 10,sizeResourcesBar.y / 1.1) == 1) {
            window->close();
        }
    }

    //Function attack Player
    attackPlayer.setSize(sf::Vector2f(sizeResourcesBar.y / 1.1,sizeResourcesBar.y / 1.1));
    attackPlayer.setOrigin(attackPlayer.getSize().x,attackPlayer.getSize().y);
    attackPlayer.setPosition(resourcesBar.getPosition().x + 7.2 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y)/1.008);
    attackPlayerAmountBar.setOrigin(rounded);
    attackPlayerAmountBar.setPosition(resourcesBar.getPosition().x + 7.5 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    attackPlayerAmountBar.setCharacterSize(resourcesBar.getSize().y);

    //Function attack Enemy
    attackEnemy.setSize(sf::Vector2f(sizeResourcesBar.y / 1.1,sizeResourcesBar.y / 1.1));
    attackEnemy.setOrigin(attackEnemy.getSize().x,attackEnemy.getSize().y);
    attackEnemy.setPosition(resourcesBar.getPosition().x + 15 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y)/1.008);
    attackEnemyAmountBar.setOrigin(rounded);
    attackEnemyAmountBar.setPosition(resourcesBar.getPosition().x + 15.5 * (resourcesBar.getSize().x / 30),resourcesBar.getPosition().y + (resourcesBar.getSize().y / 2));
    attackEnemyAmountBar.setCharacterSize(resourcesBar.getSize().y);
}

void GameBar::setGreenResource() {
    greenResourcesAmount += 1;
    greenResourcesAmountBar.setString(std::to_string(greenResourcesAmount));
}

void GameBar::setBlueResource() {
    blueResourcesAmount += 1;
    blueResourcesAmountBar.setString(std::to_string(blueResourcesAmount));
}

void GameBar::setHp(sf::Vector2f ant,double timeGame) {
    if(timeGame > timeHelpHp){
        timeHelpHp = 0;
        if(hpAmount<100){
            if(ant.x >= 1700 && ant.x <= 2000 && ant.y >= 4100 && ant.y <= 4500){
                timeHelpHp += (timeGame+0.5);
                hpAmount+=1;
                hpAmountTextBar.setString(std::to_string(hpAmount));
                help = hpAmountTextBar.getString();
                help1 = help + "\\100";
                hpAmountTextBar.setString(help1);
            }
        }
    }
}

void GameBar::attackHP(double timeGame) {
    if(timeGame > timeHelpHPAttack){
        timeHelpHPAttack = 0;
        if(hpAmount>0){
            timeHelpHPAttack += (timeGame+1);
            hpAmount-=1;
            hpAmountTextBar.setString(std::to_string(hpAmount));
            help = hpAmountTextBar.getString();
            help1 = help + "\\100";
            hpAmountTextBar.setString(help1);
        }
    }
}

int GameBar::getHpAmount() {
    return hpAmount;
}
