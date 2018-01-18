#pragma once

#include <vector>
#include "Player.h"
#include "stdafx.h"

using namespace std;
class Player;
class Game {
private:
   enum DifficultyOption
    {
        EASY,
        NORMAL,
        HARD,
        INSANE

    };

    enum SizeOption
    {
        ELEVEN = 11,
        FIFTEEN = 15,
        SEVENTEEN = 17

    };

    enum GameMode
    {
        SINGLE_PLAYER,
        LOCAL_MULTIPLAYER
    };
    vector<Player *> players;
    DifficultyOption difficulty;
    int boardSize;
    GameMode gameMode;
    int currentTurn;
    bool gameOver;
    int winner;

public:
	
    Game(int _boardSize);
	bool progressGame();

	Player* getFirstPlayer() const;
	Player* getSecondPlayer() const;
    void selectAmmo(int ammoType);
    int getAmmoCount();

	int getCurrentTurn() const;

    bool isGameOver() const;

};
