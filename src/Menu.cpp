#include "Menu.h"

Menu::Menu() {
    Mrowka.loadFromFile("../images/img1.jpg");
    Tlo.setSize(sf::Vector2f(1920.0, 1080.0));
    Tlo.setTexture(&Mrowka);
}

void Menu::Input(sf::RenderWindow *window) {}
void Menu::Update(sf::RenderWindow *window, float delta) {
    m_lifetime -= delta;
    m_Button1.MakeB(1450,187.5);
    m_Button2.MakeB(1450,287.5);
    m_Button3.MakeB(1450,387.5);
    m_Button1.SetTex("Start",1450,187.5);
    m_Button2.SetTex("Options",1450,287.5);
    m_Button3.SetTex("Exit",1450,387.5);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 180 && sf::Mouse::getPosition().y < 255){
            //m_Button1.SetTex("Chujowo",1320,150);
            m_queued_game_state = (GameState *)new AntGame();
        }
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 280 && sf::Mouse::getPosition().y < 355){
            m_queued_game_state = (GameState *)new MenuOptions();
        }
        if(sf::Mouse::getPosition().x < 1600 && sf::Mouse::getPosition().x > 1300 && sf::Mouse::getPosition().y > 380 && sf::Mouse::getPosition().y < 455){
            std::cout<<mDifficultLevel;
            //window->close();
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


