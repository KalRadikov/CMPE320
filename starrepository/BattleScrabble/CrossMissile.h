#pragma once
#include "Ammo.h"


class CrossMissile : public Ammo
{
public:
    CrossMissile() :Ammo() {};
    CrossMissile(int count) :Ammo(count) {};
	// Virtual funciton to be overridden by specific ammo implementations
	// Should update board to reflect new status and return true if a hit
	// was registered
	virtual bool handleHit(BattleshipBoard* board, Point hitLocation) override;
};
