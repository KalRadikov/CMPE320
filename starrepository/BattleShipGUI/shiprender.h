#pragma once
#include <QGraphicsItem>

#include "../BattleScrabble/Ship.h"


class ShipRender : public QGraphicsItem
{
public:
    ShipRender(Ship* _ship, int _tileSize);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void redraw();
    void rotateShip();
    void moveTo(int xCoord, int yCoord);
    void updateSprite();
    bool isDead() const;
    Ship* getShip() const;
    void updateTileSize(int size);
private:
    Ship* ship;
    int tileSize;
    int xPos;
    int yPos;
    QPixmap* image;
    QRectF rect;
};
