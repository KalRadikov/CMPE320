#include "stdafx.h"
#include "CrossMissile.h"
#include "Missile.h"

bool CrossMissile::handleHit(BattleshipBoard* board, Point hitLocation)
{
    ammoCount--;
    if(ammoCount<0){
        return false;
    }
    Missile *temp = new Missile();
    board->fireAtLocation(Point(hitLocation.getX()-1,hitLocation.getY()),temp);
    board->fireAtLocation(Point(hitLocation.getX()+1,hitLocation.getY()),temp);
    board->fireAtLocation(Point(hitLocation.getX(),hitLocation.getY()-1),temp);
    board->fireAtLocation(Point(hitLocation.getX(),hitLocation.getY()+1),temp);

    bool result = board->fireAtLocation(hitLocation,temp);
    delete temp;
    return result;


}
