#include "Menu.h"
#include "AntGame.h"
#include "MenuOptions.h"

#include "SFML/Graphics/RenderTexture.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

Menu::Menu() {
  Mrowka.loadFromFile("../images/img1.jpg");
  Tlo.setSize(sf::Vector2f(1920.0, 1080.0));
  Tlo.setTexture(&Mrowka);
}

void Menu::Input(sf::RenderWindow *window) {}
void Menu::Update(sf::RenderWindow *window, float delta) {
  m_lifetime -= delta;
  m_Button1.MakeB(1300,150);
  m_Button2.MakeB(1300,250);
  m_Button3.MakeB(1300,350);
  m_Button1.SetTex("Start",1320,150);
  m_Button2.SetTex("Options",1320,250);
  m_Button3.SetTex("Exit",1320,350);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 180 && sf::Mouse::getPosition().y < 255){
            //m_Button1.SetTex("Chujowo",1320,150);
            m_queued_game_state = (GameState *)new AntGame();
        }
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 280 && sf::Mouse::getPosition().y < 355){
            m_queued_game_state = (GameState *)new MenuOptions();
        }
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 380 && sf::Mouse::getPosition().y < 455){
            window->close();
        }
    }


  if (m_lifetime <= 0.0)
    m_queued_game_state = (GameState *)new AntGame();
}
void Menu::Render(sf::RenderWindow *window) {
    window->draw(Tlo);
    m_Button1.Render(window);
    m_Button2.Render(window);
    m_Button3.Render(window);
}
