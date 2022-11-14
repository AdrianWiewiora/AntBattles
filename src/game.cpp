#include "game.h"

//Initializer functions
void Game::initWindow() {
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

    sf::Texture Torf;
    Torf.loadFromFile("../images/torf.jpg");
    sf::RectangleShape tlo;
    tlo.setSize(sf::Vector2f(1920.0,1080.0));
    tlo.setTexture(&Torf);

    window->draw(tlo);

    window->display();
}

void Game::run() {
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}
