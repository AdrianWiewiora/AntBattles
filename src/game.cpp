#include "game.h"
#include "Menu.h"
#include "SFML/Graphics/Color.hpp"

// Initializer functions
void Game::initWindow() {
  // this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big
  // Strategy",sf::Style::Fullscreen);
  this->window =
      new sf::RenderWindow(sf::VideoMode(1920, 1080), "Little Big Strategy");
}

// Constructors
Game::Game() {
  this->initWindow();
  m_current_state = (GameState *)new Menu;
}

void Game::update() { this->updateSFMLEvents(); }

void Game::updateSFMLEvents() {
  while (window->pollEvent(this->sfEvent))
    if (this->sfEvent.type == sf::Event::Closed)
      this->window->close();
}

void Game::run() {
  sf::Clock time;
  while (window->isOpen()) {
    if (m_current_state->getQueuedGameState() != nullptr) {
      auto t = m_current_state->getQueuedGameState();
      delete m_current_state;
      m_current_state = t;
    }

    updateSFMLEvents();
    window->clear(sf::Color::Black);
    m_current_state->Input(window);
    m_current_state->Update(window, time.restart().asSeconds());
    m_current_state->Render(window);
    window->display();
  }
}
