#include "stdafx.h"
#include "Player.h"
#include "CrossMissile.h"
#include "Missile.h"

Player::Player(const int boardSize, const int playerDifficulty, Game *_game): game(_game)
{

    AmmoCount = 3;
	battleshipBoard = new BattleshipBoard(boardSize, this);
	scrabbleBoard = new ScrabbleBoard(boardSize);
	scrabbleBin = new ScrabbleTileContainer();
    CrossMissile *specialAmmo = new CrossMissile(AmmoCount);
    Missile *defaultAmmo = new Missile();
    addAmmo(defaultAmmo);
    addAmmo(specialAmmo);
    selectAmmo(0);
}

Player::~Player()
{
	delete battleshipBoard;
	delete scrabbleBoard;
	delete scrabbleBin;

}

void Player::selectAmmo(const int index)
{
	currentlySelectedAmmo = ammoOptions[index];
}

void Player::addAmmo(Ammo* ammoToAdd)
{
	ammoOptions.push_back(ammoToAdd);
}

void Player::endMove()
{
    game->progressGame();
}

void Player::setEnemy(Player *e)
{
    battleshipBoard->setEnemy(e);
}

bool Player::hasLiveShips() const
{
    std::vector<Ship *> ships = battleshipBoard->getShips();
    for each (Ship* ship in ships)
	{
		if (ship->isDead() == false)
		{
			return true;
		}
	}
    return false || ships.size()==0;
}

std::vector<Ship*> Player::getShips()
{
    return battleshipBoard->getShips();
}

Ammo *Player::getSelectedAmmo() const
{
    return currentlySelectedAmmo;
}

int Player::getAmmoCount()
{
    return AmmoCount;
}


BattleshipBoard *Player::getBattleshipBoard() const
{
 return battleshipBoard;
}

//bool Player::placeShip(ShipType shipID, Point location, bool placeHorizontally)
//{
//	Ship* shipToPlace = ships[shipID];
//	if (shipToPlace->getOccupiedTiles().size() > 0) //This means the ship was already placed
//	{
//		return false;
//	}
//	else
//	{
//		shipToPlace->setLocation(location, placeHorizontally);
//		try
//		{
//			battleshipBoard->addShip(shipToPlace);
//		}
//		catch (const ShippAddException&)
//		{
//			// TODO maybe add a resetShip function to avoid having to redeclare the ship
//			delete shipToPlace;
//			ships[shipID] = new Ship(shipID);
//			return false;
//		}
//	}
//	return true;
//}
