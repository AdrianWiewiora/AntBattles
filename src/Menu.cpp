#include "Menu.h"

Menu::Menu() {
    Mrowka.loadFromFile("../images/img1.jpg");
    Tlo.setSize(sf::Vector2f(1920.0, 1080.0));
    Tlo.setTexture(&Mrowka);
}

void Menu::Update(sf::RenderWindow *window, FrameInfo &frameInfo) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(m_Button1.buttonClicked(window) == 1){
            m_queued_game_state = (GameState *)new AntGame();
        }
        if(m_Button2.buttonClicked(window) == 1){
            m_queued_game_state = (GameState *)new MenuOptions();
        }
        if(m_Button3.buttonClicked(window) == 1){
            window->close();
        }
    }
}
void Menu::Render(sf::RenderWindow *window) {
    window->draw(Tlo);
    m_Button1.Render(window);
    m_Button2.Render(window);
    m_Button3.Render(window);
}


