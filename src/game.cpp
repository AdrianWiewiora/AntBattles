#include "game.h"

//Initializer functions
void Game::initWindow() {
    //this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big Strategy",sf::Style::Fullscreen);
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big Strategy");
}

//Constructors
Game::Game(){
    this->initWindow();
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::updateSFMLEvents() {
    while (window->pollEvent(this->sfEvent))
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
}

void Game::render() {
    window->clear();
    //Render item
    window->draw(tlo);
    window->draw(ant1);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        ant1.move(-0.05,0);
        //ant1.setRotation(270);
        ant1.rotate(-0.1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        ant1.move(0.05,0);
        //ant1.setRotation(90);
        ant1.rotate(0.1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        ant1.move(0,-0.05);
        //ant1.setRotation(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        ant1.move(0,0.05);
        //ant1.setRotation(180);
    }

    window->display();
}

void Game::run() {
    while (this->window->isOpen())
    {
        Menu menu1;
        menu1.renderM(window);
        this->update();
        //this->render();
    }
    initWindow();
    sf::Texture Torf;
    Torf.loadFromFile("../images/torf2.png");

    tlo.setSize(sf::Vector2f(1920.0,1080.0));
    tlo.setTexture(&Torf);

    sf::Texture Mroweczka;
    Mroweczka.loadFromFile("../images/ant1.png");

    //ant1.setOrigin(2000,2000);

    ant1.setTexture(Mroweczka);
    ant1.setOrigin(sf::Vector2f(ant1.getTexture()->getSize().x*0.5,ant1.getTexture()->getSize().y*0.5));
    ant1.setScale(sf::Vector2f(0.2f, 0.2f));
    ant1.setPosition(0,0);


    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
