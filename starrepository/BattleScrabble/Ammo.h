#pragma once

#include "BattleshipBoard.h"
#include "stdafx.h"


class BattleshipBoard;

class Ammo
{
public:
    Ammo() :ammoCount(INT32_MAX) {}
    Ammo(int count) :ammoCount(count) {}
	virtual ~Ammo() = default;
	// Virtual funciton to be overridden by specific ammo implementations
	// Should update board to reflect new status and return true if a hit
	// was registered
	virtual bool handleHit(BattleshipBoard* board, Point hitLocation) =0;

protected:
    int ammoCount;
};
