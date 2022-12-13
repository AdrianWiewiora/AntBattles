#include "AntGame.h"


AntGame::AntGame() {
    Torf.loadFromFile("../images/mapTexture1.png");
    tlo.setSize(sf::Vector2f(3840.0, 5400.0));
    tlo.setTexture(&Torf);
    view1.setSize(viewWidth,viewHeight);
    view1.setCenter(1920,2700);
}

void AntGame::Input(sf::RenderWindow *window) {}
void AntGame::Update(sf::RenderWindow *window, FrameInfo &frameInfo)  {
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
    float move = 500 * frameInfo.delta;
    sf::Vector2f vectorCenterMax = MaxCenter(frameInfo);
    sf::Vector2f vectorCenterMin = MinCenter(frameInfo);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) view1.move(0,-move);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) view1.move(-move,0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) view1.move(0,move);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) view1.move(move,0);

    float x = Clamp(view1.getCenter().x,vectorCenterMin.x,vectorCenterMax.x);
    float y = Clamp(view1.getCenter().y,vectorCenterMin.y,vectorCenterMax.y);
    view1.setCenter(x,y);

    //Function steering ants
    ant1.rotationSteering(frameInfo);
    ant1.moveKeyboard(frameInfo);

    //Funkcje pozostale

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2f helpPos;
        sf::Vector2f currentPosition = ant1.getPositionAnt();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        helpPos = window->mapPixelToCoords(mousePosition);

        const float PI = 3.14159265;
        float a = currentPosition.x - helpPos.x;
        float b = currentPosition.y - helpPos.y;
        float rotation = ( atan2( b, a ) ) * 180 / PI;
        rotation -= 90;
        ant1.setRotationAnt( rotation );

        ant1.targetPosition = window->mapPixelToCoords(mousePosition);

    }
    ant1.moveAnt(frameInfo,window);

}

void AntGame::Render(sf::RenderWindow *window) {
    window->setView(view1);
    window->draw(tlo);
    ant1.drawAnt(window);
}

sf::Vector2f AntGame::MaxCenter(FrameInfo &frameInfo) {
    sf::Vector2f vectorHelp;
    vectorHelp =  view1.getSize();
    sf::Vector2f maximum;
    maximum.x = vectorHelp.x/2;
    maximum.y = vectorHelp.y/2;
    return maximum;
}

sf::Vector2f AntGame::MinCenter(FrameInfo &frameInfo) {
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
