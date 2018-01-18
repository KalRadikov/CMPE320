#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include "HumanPlayer.h"
#include "Player.h"
using namespace std;

//int main() {
//    cout << "Starting point is in Game.cpp" << endl;
//    return 0;
//}


Game::Game(int _boardSize):boardSize(_boardSize)
{
    gameOver=false;
    winner=-1;

    players.push_back(new HumanPlayer(boardSize, difficulty, this));
    players.push_back(new HumanPlayer(boardSize, difficulty, this));
    players[0]->setEnemy(players[1]);
    players[1]->setEnemy(players[0]);
    currentTurn = 0;


}

void Game::selectAmmo(int ammoType) {

    players[currentTurn]->selectAmmo(ammoType);
}

int Game::getAmmoCount()
{
    return players[currentTurn]->getAmmoCount();
}


bool Game::progressGame()
{
    std::cout<<"1: "<<players[0]->hasLiveShips() << " \t2: "<<players[1]->hasLiveShips()<<std::endl;
    if(players[0]->hasLiveShips() && players[1]->hasLiveShips())
	{
		players[currentTurn]->makeMove();
		currentTurn = (currentTurn + 1) % 2;
        return false;
	}else
	{
        gameOver=true;
        winner= players[0]->hasLiveShips()? 0 : 1;
        return true;
	}
}

Player * Game::getFirstPlayer() const
{
	return players[0];
}

Player * Game::getSecondPlayer() const
{
	return players[1];
}

int Game::getCurrentTurn() const
{
    return currentTurn;
}

bool Game::isGameOver() const
{
 return gameOver;
}
