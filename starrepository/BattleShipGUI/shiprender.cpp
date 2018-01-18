#include "shiprender.h"
#include "boardrender.h"
#include <Qpainter>
#include <iostream>
#include <QGraphicsSceneMouseEvent>

ShipRender::ShipRender(Ship *_ship, int _tileSize)
{
    ship=_ship;
    tileSize=_tileSize;
    if(ship->getOccupiedTiles().size()==0){
        ship->setLocation(Point(0,0),false);
    }

    redraw();
    updateSprite();

}

QRectF ShipRender::boundingRect() const
{
    return rect;

}

void ShipRender::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *image);
}

void ShipRender::redraw()
{
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for each (QGraphicsItem* graphicsItem in collidingItemsList) {
        BoardRenderTile* tile = dynamic_cast<BoardRenderTile*>(graphicsItem);
        if(tile!=nullptr){
            tile->setHighlighted(false);
        }
    }

    Point startPoint = ship->getOccupiedTiles()[0];
    xPos=startPoint.getX()*tileSize;
    yPos=startPoint.getY()*tileSize;
    setPos(xPos, yPos);

    collidingItemsList = collidingItems();
    bool collidingWithShip = collidingItemsList.size()>ship->getSize();
    for each (QGraphicsItem* graphicsItem in collidingItemsList) {
        BoardRenderTile* tile = dynamic_cast<BoardRenderTile*>(graphicsItem);
        if(tile!=nullptr){
            tile->setHighlighted(collidingWithShip);
        }
    }


}

void ShipRender::rotateShip()
{

    ship->setPlaceHorizontally(!ship->isPlacedHorizontally());
    QList<QGraphicsItem*> collidingItemsList = collidingItems();
    for each (QGraphicsItem* graphicsItem in collidingItemsList) {
        BoardRenderTile* tile = dynamic_cast<BoardRenderTile*>(graphicsItem);
        if(tile!=nullptr){
            tile->setHighlighted(false);
        }
    }
    QMatrix rm;
    if(ship->isPlacedHorizontally()){
        rm.translate(0,tileSize);
        rm.rotate(-90);
    }else{
        rm.rotate(0);
    }
    setTransform(QTransform(rm));
    redraw();
}

void ShipRender::moveTo(int xCoord, int yCoord)
{
    ship->setLocation(Point(xCoord,yCoord),ship->isPlacedHorizontally());
    redraw();
}

void ShipRender::updateSprite()
{
    if(ship->isDead()){

        switch (ship->getId()) {
            case BattleShip:
                image = new QPixmap("../BattleshipGUI/Sprites/battleship sunk.svg");
                break;
            case Submarine:
                image = new QPixmap("../BattleshipGUI/Sprites/submarine sunk.svg");
                break;
            case Destroyer:
                image = new QPixmap("../BattleshipGUI/Sprites/destroyer sunk.svg");
                break;
            case Cruiser:
                image = new QPixmap("../BattleshipGUI/Sprites/cruiser sunk.svg");
                break;
            case AircraftCarrier:
                image = new QPixmap("../BattleshipGUI/Sprites/carrier sunk.svg");
                break;
            default:
                break;
        }


    } else{
        switch (ship->getId()) {
            case BattleShip:
                image = new QPixmap("../BattleshipGUI/Sprites/battleship.svg");
                break;
            case Submarine:
                image = new QPixmap("../BattleshipGUI/Sprites/submarine.svg");
                break;
            case Destroyer:
                image = new QPixmap("../BattleshipGUI/Sprites/destroyer.svg");
                break;
            case Cruiser:
                image = new QPixmap("../BattleshipGUI/Sprites/cruiser.svg");
                break;
            case AircraftCarrier:
                image = new QPixmap("../BattleshipGUI/Sprites/carrier.svg");
                break;
            default:
                break;
        }
    }
    *image=image->scaled(tileSize,tileSize*ship->getSize());


    rect= QRectF(0,0,tileSize,ship->getSize()*tileSize);


    if(ship->isPlacedHorizontally()){
        ship->setPlaceHorizontally(false);
        rotateShip();
    }
}

bool ShipRender::isDead() const
{
    return ship->isDead();
}

Ship *ShipRender::getShip() const
{
    return ship;
}

void ShipRender::updateTileSize(int size)
{
    tileSize=size;
    updateSprite();

}

