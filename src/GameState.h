#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
class GameState {
protected:
  GameState *m_queued_game_state = nullptr;

public:
    int mDifficultLevel = 1;
    virtual void Render(sf::RenderWindow *window) = 0;
    virtual void Input(sf::RenderWindow *window) = 0;
    virtual void Update(sf::RenderWindow *window, float delta) = 0;
    GameState *getQueuedGameState();
};
