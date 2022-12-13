#include "GameState.h"

int GameState::mDifficultyLevel = 1;

GameState *GameState::getQueuedGameState() {
    return m_queued_game_state;
}
