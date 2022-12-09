#include "AntGame.h"


AntGame::AntGame() {
    Torf.loadFromFile("../images/mapTexture1.png");

    tlo.setSize(sf::Vector2f(3840.0, 5400.0));
    tlo.setTexture(&Torf);
    view1.setSize(viewWidth,viewHeight);
    view1.setCenter(1920,2700);

    t.loadFromFile("../images/ant1.png");

    // ant1.setOrigin(2000,2000);

    ant1.setTexture(t);
    ant1.setOrigin(sf::Vector2f(ant1.getTexture()->getSize().x * 0.5,ant1.getTexture()->getSize().y * 0.5));
    ant1.setScale(sf::Vector2f(0.2f, 0.2f));
    ant1.setPosition(500, 500);
}

//float Clamp(float value, float max, float min)
//{
//    if(value < min)
//        return min;
//    if(value > max)
//        return max;
//    return value;
//}

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


    //Funkcje pozostale




    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Vector2f helpPos;
        sf::Vector2f currentPosition = ant1.getPosition();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
        helpPos = window->mapPixelToCoords(mousePosition);

        const float PI = 3.14159265;

        float a = currentPosition.x - helpPos.x;
        float b = currentPosition.y - helpPos.y;

        float rotation = ( atan2( b, a ) ) * 180 / PI;
        rotation -= 90;

        ant1.setRotation( rotation );


        vectorI = sf::Mouse::getPosition(*window);
        vectorF = window->mapPixelToCoords(vectorI);
        //MoveAnts(vectorF,frameInfo);

        //ant1.move(sf::Vector2f(vectorF * float(frameInfo.delta)));
        //ant1.move(sf::Vector2f(vector.x*frameInfo.delta,vector.y*frameInfo.delta));
        //ant1.move(((pozX-ant1.getPosition().x)/100)*delta,((pozY-ant1.getPosition().y)/100)*delta);
    }


    float rotation;
    rotation = ant1.getRotation();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        ant1.move(-100*frameInfo.delta, 0);
        if(rotation<270 && rotation>=90){ant1.rotate(60*frameInfo.delta);}
        else if(rotation>270 || rotation<=90){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        ant1.move(100*frameInfo.delta, 0);
        if(rotation<=270 && rotation>90){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation>=270 || rotation<90){ant1.rotate(60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        ant1.move(0, -100*frameInfo.delta);
        if(rotation<=180 && rotation>0){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation>=180 || rotation<0){ant1.rotate(60*frameInfo.delta);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        ant1.move(0, 100*frameInfo.delta);
        if(rotation<180 && rotation>=0){ant1.rotate(60*frameInfo.delta);}
        else if(rotation>180 || rotation<=0){ant1.rotate(-60*frameInfo.delta);}
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(rotation<315 && rotation>=135){ant1.rotate(60*frameInfo.delta);}
        else if(rotation>315 || rotation<=135){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(rotation<225 && rotation>=45){ant1.rotate(60*frameInfo.delta);}
        else if(rotation>225 || rotation<=45){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(rotation<=225 && rotation>45){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation>=225 || rotation<45){ant1.rotate(60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(rotation<=315 && rotation>135){ant1.rotate(-60*frameInfo.delta);}
        else if(rotation>=315 || rotation<135){ant1.rotate(60*frameInfo.delta);}
        else if(rotation==0){ant1.setRotation(360);}
    }
}

void AntGame::Render(sf::RenderWindow *window) {
    window->setView(view1);
    window->draw(tlo);
    window->draw(ant1);
}

void AntGame::MoveAnts(sf::Vector2f positions,FrameInfo &frameInfo) {
    ant1.setPosition(positions);

//    sf::Vector2f help1;
//    help1.x =2;
//    help1.y =2;
//    while(ant1.getPosition() != positions){
//        ant1.move(help1.x * frameInfo.delta,help1.y * frameInfo.delta);
//    }

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
