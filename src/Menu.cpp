#include "Menu.h"
#include "AntGame.h"

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
  m_Button1.MakeB(1500,100);
  m_Button2.MakeB(1500,200);
  m_Button3.MakeB(1500,300);

  if (m_lifetime <= 0.0)
    m_queued_game_state = (GameState *)new AntGame();
}
void Menu::Render(sf::RenderWindow *window) {
    window->draw(Tlo);
    m_Button1.Render(window);
    m_Button2.Render(window);
    m_Button3.Render(window);
}
