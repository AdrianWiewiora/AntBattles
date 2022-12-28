#include "AntGame.h"



AntGame::AntGame() {
    Torf.loadFromFile("../images/mapTexture2.png");
    tlo.setSize(sf::Vector2f(3840.0, 5400.0));
    tlo.setTexture(&Torf);

    greenResourceTexture.loadFromFile("../images/greenResources.png");
    greenResourceTextureBW.loadFromFile("../images/greenResourcesBW.png");
    blueResourceTexture.loadFromFile("../images/blueResources.png");
    blueResourceTextureBW.loadFromFile("../images/blueResourcesBW.png");
    greenResourcesRS.setSize(sf::Vector2f(100.0, 100.0));
    blueResourcesRS.setSize(sf::Vector2f(100.0, 100.0));
    greenResourcesRS.setTexture(&greenResourceTexture);
    greenResourcesRS.setOrigin(50,50);
    blueResourcesRS.setTexture(&blueResourceTexture);
    blueResourcesRS.setOrigin(50,50);

    view1.setSize(viewWidth,viewHeight);
    view1.setCenter(1920,2700);


    //Enemys
    for(int h=0;h<5;h++){
        enemies[h].setEnemy(rand()%3840,rand()%5400);
    }



}

void AntGame::Update(sf::RenderWindow *window, FrameInfo &frameInfo)  {
    //Time counter
    time += frameInfo.delta;
    //Function steering zoom/view size
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp))view1.zoom(-1.1f * frameInfo.delta +1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)) view1.zoom(1.1f * frameInfo.delta +1);
    view1.zoom(1.0 +frameInfo.mouseWheelDelta * -0.1);
    sf::Vector2f vectorViewSize;
    vectorViewSize = view1.getSize();
    float sizeX = Clamp(vectorViewSize.x,3840,960);
    float sizeY = Clamp(vectorViewSize.y,2160,540);
    view1.setSize(sizeX,sizeY);

    //Function steering View Center itd
    float move = 1000 * frameInfo.delta;
    sf::Vector2f vectorCenterMax = MaxCenter();
    sf::Vector2f vectorCenterMin = MinCenter();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view1.move(0,-move);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view1.move(-move,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view1.move(0,move);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view1.move(move,0);

    float x = Clamp(view1.getCenter().x,vectorCenterMin.x,vectorCenterMax.x);
    float y = Clamp(view1.getCenter().y,vectorCenterMin.y,vectorCenterMax.y);
    view1.setCenter(x,y);

    //Function steering ants
    if(mUpgradeMenuExist==0){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            ant1.setRotationAnt(window);
            ant1.targetPosition = window->mapPixelToCoords(mousePosition);
        }
        ant1.moveAnt(frameInfo,window);
    }
    //Function GameBar
    gameBar.setGameBar(view1,window);

    //Function spawn Rains
    if(mRainExist == 0){
        if(time > 10.000){
            for(auto & i : redResourcesRS){
                i.setSize(sf::Vector2f(100.0, 100.0));
                i.setTexture(&blueResourceTexture);
                i.setOrigin(50,50);
                i.setPosition(rand()%3840,rand()%5400);
            }
            std::cout<<time << std::endl;
            mRainExist = 1;
        }
    }

    //Function green resource
    greenResourcesRS.setPosition(800,360);
    if(time > timeHelpGreenResources){
        timeHelpGreenResources = 0;
        greenResourcesRS.setTexture(&greenResourceTexture);
        if(ant1.getPositionAnt().x <= greenResourcesRS.getPosition().x+50 && ant1.getPositionAnt().x >= greenResourcesRS.getPosition().x-50){
            if(ant1.getPositionAnt().y <= greenResourcesRS.getPosition().y+50 && ant1.getPositionAnt().y >= greenResourcesRS.getPosition().y-50){
                timeHelpGreenResources += (time+1);
                gameBar.setGreenResource();
                greenResourcesRS.setTexture(&greenResourceTextureBW);
            }
        }
    }
    //Function blue resource
    blueResourcesRS.setPosition(2700,2000);
    if(time > timeHelpBlueResources){
        timeHelpBlueResources = 0;
        blueResourcesRS.setTexture(&blueResourceTexture);
        if(ant1.getPositionAnt().x <= blueResourcesRS.getPosition().x+50 && ant1.getPositionAnt().x >= blueResourcesRS.getPosition().x-50){
            if(ant1.getPositionAnt().y <= blueResourcesRS.getPosition().y+50 && ant1.getPositionAnt().y >= blueResourcesRS.getPosition().y-50){
                timeHelpBlueResources += (time+1);
                gameBar.setBlueResource();
                blueResourcesRS.setTexture(&blueResourceTextureBW);
            }
        }
    }
    //Function HP
    gameBar.setHp(ant1.getPositionAnt(),time);
    if(gameBar.getHpAmount() == 0){
        m_queued_game_state = (GameState *)new Menu();
    }

    //Function Red resources
    for(auto & i : redResourcesRS){
        if(ant1.getPositionAnt().x <= i.getPosition().x+50 && ant1.getPositionAnt().x >= i.getPosition().x-50){
            if(ant1.getPositionAnt().y <= i.getPosition().y+50 && ant1.getPositionAnt().y >= i.getPosition().y-50){
                gameBar.setBlueResource();
                i.setFillColor(sf::Color::Transparent);
                i.setPosition(-100,-100);
            }
        }
    }

    //Function UpgradeMenu
    if(frameInfo.keyPressed == sf::Keyboard::E){
        if(mUpgradeMenuExist == 1) mUpgradeMenuExist = 0;
        else mUpgradeMenuExist = 1;
    }
    frameInfo.keyPressed = 0;
    if(mUpgradeMenuExist==1) mUpgradeMenu.showUpgradeMenu(view1, window, gameBar);

    //Function Enemies
    for(int j=0;j<5;j++){
        if(enemies[j].getHp() != 0){
            for(int g=0;g<5;g++){
                enemyPosition[g]=enemies[g].getPositionEnemy();
                if(g==j){
                    enemyPosition[g]=antPosition;
                }
            }
            enemies[j].moveEnemy(frameInfo, window, ant1.getPositionAnt(), enemyPosition);
            antPosition = ant1.getPositionAnt();
            if(enemies[j].getPositionEnemy().x > antPosition.x-200 && enemies[j].getPositionEnemy().x < antPosition.x+200){
                if(enemies[j].getPositionEnemy().y > antPosition.y-200 && enemies[j].getPositionEnemy().y < antPosition.y+200){
                    gameBar.attackHP(time);
                    enemies[j].setHP(time, gameBar);
                }
            }
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(mUpgradeMenu.getButtonUpgradeAttack().buttonClickedMap(window,mUpgradeMenu.getTlo().getSize().x/4,mUpgradeMenu.getTlo().getSize().y/15 ) == 1){
            gameBar.buyUpgradePlayerAttack();
        }
    }

}


void AntGame::Render(sf::RenderWindow *window) {
    window->setView(view1);
    window->draw(tlo);
    window->draw(greenResourcesRS);
    window->draw(blueResourcesRS);
    for(auto & i : redResourcesRS) window->draw(i);
    ant1.drawAnt(window);
    for(int i = 0;i<5;i++)enemies[i].drawEnemy(window);
    gameBar.drawGameBar(window);
    if(mUpgradeMenuExist==1) mUpgradeMenu.drawUpgradeMenu(window);

}

sf::Vector2f AntGame::MaxCenter() {
    sf::Vector2f vectorHelp;
    vectorHelp =  view1.getSize();
    sf::Vector2f maximum;
    maximum.x = vectorHelp.x/2;
    maximum.y = vectorHelp.y/2  - gameBar.getSizeGameBar().y;
    return maximum;
}

sf::Vector2f AntGame::MinCenter() {
    sf::Vector2f vectorHelp;
    sf::Vector2f minimum;
    vectorHelp =  view1.getSize();
    minimum.x = 3840 - vectorHelp.x/2;
    minimum.y = 5400 - vectorHelp.y/2;
    return minimum;
}

float AntGame::Clamp(float value, float max, float min) {
    if(value < min)
        return min;
    if(value > max)
        return max;
    return value;
}

AntGame::~AntGame() {
    delete blackResourcesRS;
    delete enemy;
}
