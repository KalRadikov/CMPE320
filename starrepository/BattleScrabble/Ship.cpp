#include "stdafx.h"
#include "Ship.h"
#include <algorithm>

Ship::Ship(ShipType id)
{
	this->size = shipSizes[id];
	this->id = id;
	this->health = size;
	this->dead = false;
}

Ship::~Ship()
{
	delete[] shipSizes;
    shipSizes = nullptr;
}

void Ship::setPlaceHorizontally(bool value)
{
    placeHorizontally=value;
    setLocation(occupiedTiles[0],placeHorizontally);
}

int Ship::getId() const
{
	return id;
}


void Ship::setLocation(Point _startLocation, bool _placeHorizontally)
{
	occupiedTiles.clear();
    occupiedTiles.push_back(Point(_startLocation.getX(), _startLocation.getY()));

    if (_placeHorizontally == true)
	{
		for (int i = 1; i < size; i++)
		{
			occupiedTiles.push_back(Point(occupiedTiles[i - 1].getX() + 1, occupiedTiles[i - 1].getY()));
		}
	}
	else
	{
		for (int i = 1; i < size; i++)
		{
			occupiedTiles.push_back(Point(occupiedTiles[i - 1].getX(), occupiedTiles[i - 1].getY() + 1));
		}
	}

    placeHorizontally = _placeHorizontally;
}

bool Ship::markHit(Point p)
{
	if (health == 0)
	{
		return false;
	}
	else
	{
		//If this tile was NOT already hit
		if (std::find(hitTiles.begin(), hitTiles.end(), p) == hitTiles.end())
		{
			hitTiles.push_back(p);
			health -= 1;
            if (health <= 0)
			{
				dead = true;
			}
		}

		return true;
	}
}

std::vector<Point> Ship::getOccupiedTiles() const
{
	return occupiedTiles;
}

bool Ship::isDead() const
{
	return dead;
}

int Ship::getSize() const
{
	return size;
}

int Ship::getHealth() const
{
    return health;
}

bool Ship::isPlacedHorizontally() const
{
    return placeHorizontally;
}

bool Ship::hasValidLocations(int boardSize) const
{
    for (int i = 0; i < size; ++i)
    {
        if(occupiedTiles[i].getX()>=boardSize || occupiedTiles[i].getY()>=boardSize){
            return false;
        }
    }
    return true;
}

std::vector<Point> Ship::getHitLocations() const
{
	return hitTiles;
}
