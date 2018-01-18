#pragma once
#include "Ammo.h"


class Missile : public Ammo
{
public:
    Missile():Ammo(){}
    Missile(int count):Ammo(count){}
	// Virtual funciton to be overridden by specific ammo implementations
	// Should update board to reflect new status and return true if a hit
	// was registered
	virtual bool handleHit(BattleshipBoard* board, Point hitLocation) override;
};
