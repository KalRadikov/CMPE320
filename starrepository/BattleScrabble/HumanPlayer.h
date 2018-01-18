#pragma once

#include "Player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer(const int boardSize, const int playerDifficulty, Game* _game)
        : Player(boardSize, playerDifficulty, _game)
	{
	}

	void makeMove() override;
};
