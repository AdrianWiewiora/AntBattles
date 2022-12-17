#include "game.h"
#include "Menu.h"
#include "SFML/Graphics/Color.hpp"

void Game::initWindow() {
    //this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big Strategy",sf::Style::Fullscreen);
    this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big Strategy");
}

Game::Game() {
  this->initWindow();
  m_current_state = (GameState *)new Menu;
}

void Game::update() { this->updateSFMLEvents(); }

void Game::updateSFMLEvents() {
    while (window->pollEvent(sfEvent))
    {
        switch(sfEvent.type){
            case sf::Event::MouseWheelScrolled:
                frameInfo.mouseWheelDelta += sfEvent.mouseWheelScroll.delta;
                break;
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyPressed:
                if (sfEvent.key.code == sf::Keyboard::E)
                {
                    frameInfo.keyPressed = sf::Keyboard::E;
                }
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
        }
    }
}

void Game::run() {
    sf::Clock time;
  while (window->isOpen()) {
      frameInfo.delta = time.restart().asSeconds();
    if (m_current_state->getQueuedGameState() != nullptr) {
      GameState* t = m_current_state->getQueuedGameState();
      delete m_current_state;
      m_current_state = t;
    }
    window->setFramerateLimit(300);

    frameInfo.mouseWheelDelta = 0;
    updateSFMLEvents();
    window->clear(sf::Color::Black);
    m_current_state->Update(window, frameInfo);
    m_current_state->Render(window);
    window->display();
  }
}
