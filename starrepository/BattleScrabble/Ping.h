#pragma once

#include "Ammo.h"
#include "Point.h"

class Ping : public Ammo
{
public:
	Ping() :Ammo(1) {};
	// Virtual funciton to be overridden by specific ammo implementations
	// Should update board to reflect new status and return true if a hit
	// was registered
	virtual bool handleHit(BattleshipBoard* board, Point hitLocation) override;
};
