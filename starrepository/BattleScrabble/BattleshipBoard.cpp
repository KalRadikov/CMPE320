#include "stdafx.h"
#include "BattleshipBoard.h"
#include "Ammo.h"
#include "Player.h"
#include <algorithm>

bool BattleshipBoard::pointWithinBounds(Point p) const
{
	return p.getX() < size && p.getY() < size && p.getY() >= 0 && p.getX() >= 0;
}

bool BattleshipBoard::fireAtLocation(const Point& fireLocation)
{
    if(boardEnemy->getSelectedAmmo()==nullptr){
        return false;
    }else{
        return fireAtLocation(fireLocation,boardEnemy->getSelectedAmmo());
    }
}

bool BattleshipBoard::fireAtLocation(const Point &fireLocation, Ammo *ammoType)
{
    try {
        bool hitLocation = ammoType->handleHit(this, fireLocation);
        getTile(fireLocation).setMissed(!hitLocation);
        return hitLocation;
    } catch (exception) {
        return false;
    }

}

void BattleshipBoard::setEnemy(Player *e)
{
 boardEnemy=e;
}

void BattleshipBoard::addShip(Ship* ship)
{
	//Check all points to make sure everything is good to go
	for each (Point coord in ship->getOccupiedTiles())
	{
		if (!pointWithinBounds(coord) || arrayOfTiles[coord.getX()][coord.getY()].containsShip())
		{
			throw ShippAddException(coord);
		}
	}
    ships.push_back(ship);
	for each (Point coord in ship->getOccupiedTiles())
	{
		//If this tile is empty add a ship
		arrayOfTiles[coord.getX()][coord.getY()].setShip(ship);
    }
}

void BattleshipBoard::removeShip(Ship *ship)
{
    //Check all points to make sure everything is good to go
    for each (Point coord in ship->getOccupiedTiles())
    {
        if (pointWithinBounds(coord) || arrayOfTiles[coord.getX()][coord.getY()].containsShip())
        {
            //If this tile is empty add a ship
            arrayOfTiles[coord.getX()][coord.getY()].setShip(nullptr);

        }
    }
    ships.erase(std::remove(ships.begin(), ships.end(), ship), ships.end());

}


BattleshipBoardTile& BattleshipBoard::getTile(Point p) const
{
	if (pointWithinBounds(p))
	{
		return arrayOfTiles[p.getX()][p.getY()];
	}
	else
	{
		throw TileOutOfBoundsException(p);
    }
}

int BattleshipBoard::getSize() const
{
    return size;
}

std::vector<Ship *> BattleshipBoard::getShips() const
{
    return ships;
}

BattleshipBoardTile& BattleshipBoard::getTile(const int x, const int y) const
{
	return getTile(Point(x, y));
}

BattleshipBoard::BattleshipBoard(const int battleshipBoardSize, Player* owner)
{
    boardOwner=owner;
    size =battleshipBoardSize;
	arrayOfTiles = new BattleshipBoardTile*[size];
	for (int x = 0; x < size; x++)
	{
		arrayOfTiles[x] = new BattleshipBoardTile[size];
	}
    ships = std::vector<Ship*>();
}

BattleshipBoard::BattleshipBoard(BattleshipBoard & copy)
{
	size = copy.size;
	arrayOfTiles = new BattleshipBoardTile*[size];
	for (int x = 0; x < size; x++)
	{
		arrayOfTiles[x] = new BattleshipBoardTile[size];
		for (int y = 0; y < size; y++)
		{
			arrayOfTiles[x][y] = copy.getTile(x, y);
		}
	}

}

BattleshipBoard & BattleshipBoard::operator=(BattleshipBoard & right)
{
	if(this!=&right)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] arrayOfTiles[i];
		}
		delete[] arrayOfTiles;
		size = right.size;

		arrayOfTiles = new BattleshipBoardTile*[size];
		for (int x = 0; x < size; x++)
		{
			arrayOfTiles[x] = new BattleshipBoardTile[size];
			for (int y = 0; y < size; y++)
			{
				arrayOfTiles[x][y] = right.getTile(x, y);
			}
		}
	}
	
	return *this;
}

BattleshipBoard::~BattleshipBoard()
{
	for (int i = 0; i < size; i++)
	{
		delete[] arrayOfTiles[i];
	}
	delete[] arrayOfTiles;
}

BattleshipBoardTile::BattleshipBoardTile()
{
	ship = nullptr;
	hit = false;
	pinged = false;
    missed=false;
}

BattleshipBoardTile::BattleshipBoardTile(Ship* shipPtr, const bool hitBool, const bool pingBool, const bool missedBool): ship(shipPtr), hit(hitBool),
                                                                              pinged(pingBool), missed(missedBool)
{
}


bool BattleshipBoardTile::containsShip() const
{
	return ship != nullptr;
}

Ship* BattleshipBoardTile::getShip() const
{
	return ship;
}

bool BattleshipBoardTile::isHit() const
{
	return hit;
}

bool BattleshipBoardTile::isPinged() const
{
    return pinged;
}

bool BattleshipBoardTile::isMissed() const
{
    return missed;
}

void BattleshipBoardTile::setShip(Ship* s)
{
	ship = s;
	hit = false;
	pinged = false;
}

void BattleshipBoardTile::setHit(const bool h)
{
	hit = h;
}

void BattleshipBoardTile::setPinged(const bool p)
{
    pinged = p;
}

void BattleshipBoardTile::setMissed(const bool m)
{   missed=m;

}
