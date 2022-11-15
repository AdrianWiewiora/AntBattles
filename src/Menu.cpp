#include "Menu.h"
#include "AntGame.h"
#include "GameState.h"
#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

Menu::Menu() {
  Mrowka.loadFromFile("../images/img1.jpg");
  Tlo.setSize(sf::Vector2f(1920.0, 1080.0));
  Tlo.setTexture(&Mrowka);
}

void Menu::Input(sf::RenderWindow *window) {}
void Menu::Update(sf::RenderWindow *window, double delta) {
  m_lifetime -= delta;

  if (m_lifetime <= 0.0)
    m_queued_game_state = (GameState *)new AntGame();
}
void Menu::Render(sf::RenderWindow *window) { window->draw(Tlo); }
