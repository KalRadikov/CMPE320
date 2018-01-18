#pragma once

#include "../BattleScrabble/BattleshipBoard.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "shiprender.h"
#include <vector>
#include "playerrender.h"
#include <QLabel>

class PlayerRender;

class BoardRenderTile : public QGraphicsItem
{
public:
    BoardRenderTile(int _x, int _y, int _size, BattleshipBoardTile* _tile);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void setHighlighted(bool value);

private:
    int x;
    int y;
    int size;
    bool highlighted;
    BattleshipBoardTile* tile;
};

class BoardRender : public QGraphicsScene
{
    Q_OBJECT
public slots:
    void explosionFrameChanged_Handler(int frameNumber);
    void missFrameChanged_Handler(int frameNumber);
public:
    BoardRender(BattleshipBoard* _board, int boardWidth, QLabel* boardLabel, QWidget* _confirmButton, PlayerRender* _parent);
     void confrimPlace();
     void viewMode();
     void attackMode();
     int getBoardMode();
    void setGameOver();
    void updateSize(int size);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
private:
    enum BoardMode{
        ShipPlacement,
        ShipConfirmation,
        Attack,
        View,
        GameOver
    };
    void drawGrid();
    void updateShipRenders();
    BattleshipBoard* board;
    int tileSize;
    int boardSize;
    std::vector<ShipRender*> shipRenders;
    std::vector<ShipType> shipsToPlace;
    BoardMode boardMode;
    Ship* shipToPlace;
    bool disablePlace;
    PlayerRender* parent;
    bool turnCompleted;
    QGraphicsTextItem* nextPlayerText;
    QLabel* boardLabel;
    int shipPlaceIndex;
    QWidget* confirmButton;
    void startPlacingNextShip();
    void drawExplosion(int tileX, int tileY);
    void drawMiss(int tileX, int tileY);
    QMovie *explosionMovie;
    QMovie *missMovie;
    QLabel *gifHolder;
    QGraphicsProxyWidget* holderProxy;


};
