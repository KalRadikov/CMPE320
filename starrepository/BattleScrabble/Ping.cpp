#include "stdafx.h"
#include "Ping.h"


bool Ping::handleHit(BattleshipBoard* board, Point hitLocation)
{
	//check if tile contains ship...logic. Make sure it returns if theres a ship there
	try
	{
		BattleshipBoardTile& tile = board->getTile(hitLocation);
		bool containsShip = tile.containsShip();
		tile.setPinged(containsShip);
		return containsShip;
	}
	catch (const TileOutOfBoundsException&)
	{
		return false;
	}
}
