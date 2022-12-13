#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "FrameInfo.h"

class GameState {
protected:
  GameState *m_queued_game_state = nullptr;

public:
    static int mDifficultyLevel;
    virtual void Render(sf::RenderWindow *window) = 0;
    virtual void Update(sf::RenderWindow *window, FrameInfo &frameInfo) = 0;
    GameState *getQueuedGameState();
};
