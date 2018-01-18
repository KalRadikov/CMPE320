#include "stdafx.h"
#include "Missile.h"
#include <iostream>

bool Missile::handleHit(BattleshipBoard* board, Point hitLocation)
{
    ammoCount--;
    if(ammoCount<0){
        return false;
    }

	// Returns true if missile hit a target, false if missile missed
	BattleshipBoardTile& tile = board->getTile(hitLocation);
	if (tile.containsShip())
	{
		Ship* ship = tile.getShip();
		ship->markHit(hitLocation);
		tile.setHit(true);
		return true;
	}
	else
	{
		return false;
	}
}
