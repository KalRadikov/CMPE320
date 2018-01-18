#include "boardrender.h"
#include <QPainter>
#include <iostream>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include <QMovie>
#include <QGraphicsProxyWidget>
BoardRender::BoardRender(BattleshipBoard *_board, int boardWidth, QLabel *_boardLabel, QWidget* _confirmButton, PlayerRender* _parent)
    :parent(_parent), QGraphicsScene(_parent), boardLabel(_boardLabel), confirmButton( _confirmButton)
{
    boardMode=ShipPlacement;
    shipToPlace=nullptr;
    board=_board;
    boardSize=board->getSize();
    tileSize=boardWidth/boardSize;
    setSceneRect(QRectF(0,0,tileSize*boardSize,tileSize*boardSize));
    QImage *img = new QImage("../BattleshipGUI/Sprites/tex_Water.jpg");
    QBrush *brush = new QBrush(*img);
    setBackgroundBrush(*brush);
    shipRenders=std::vector<ShipRender*>();
    drawGrid();
    updateShipRenders();
    disablePlace=false;
    shipsToPlace.push_back(AircraftCarrier);
    shipsToPlace.push_back(Cruiser);
    shipsToPlace.push_back(BattleShip);
    shipsToPlace.push_back(Submarine);
    shipsToPlace.push_back(Destroyer);
    startPlacingNextShip();
    turnCompleted=false;

    nextPlayerText = nullptr;

    explosionMovie = new QMovie("../BattleshipGUI/Sprites/explode.gif");
    missMovie = new QMovie("../BattleshipGUI/Sprites/miss.gif");
    connect(explosionMovie, SIGNAL(frameChanged(int)), this, SLOT(explosionFrameChanged_Handler(int)));
    connect(missMovie, SIGNAL(frameChanged(int)), this, SLOT(missFrameChanged_Handler(int)));
}

void BoardRender::startPlacingNextShip()
{
    if(shipsToPlace.size()==0){
        boardLabel->setText("Click on a ship to move or click confrim to continue.");
        boardLabel->setVisible(true);
        boardMode=ShipConfirmation;
        confirmButton->setVisible(true);
        return;
    }

    ShipType type = shipsToPlace.back();
    shipsToPlace.pop_back();
    Ship* ship = new Ship(type);
    ShipRender *tempRender = new ShipRender(ship,tileSize);
    shipPlaceIndex=shipRenders.size();
    shipRenders.push_back(tempRender);
    addItem(tempRender);
    shipToPlace=ship;

}

void BoardRender::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(boardMode==ShipPlacement){

        QPointF mouseLocation = event->scenePos();
        mouseLocation /= tileSize;

        shipRenders[shipPlaceIndex]->moveTo(mouseLocation.x(), mouseLocation.y());
        disablePlace = collidingItems(shipRenders[shipPlaceIndex]).size()>shipToPlace->getSize() || !shipToPlace->hasValidLocations(board->getSize());

    }
}

void BoardRender::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(boardMode==GameOver){
        return;
    }
    if(turnCompleted){
        turnCompleted=false;
        parent->endTurn();
        if(boardMode!=ShipConfirmation){
            boardLabel->setVisible(false);
        }

        return;
    }

    if(e->button() == Qt::LeftButton){
        if(boardMode==ShipConfirmation){
            boardLabel->setVisible(false);
            ShipRender* possibleShip = dynamic_cast<ShipRender*>(itemAt(e->scenePos(),QTransform()));
            if(possibleShip){
                boardMode=ShipPlacement;
                shipToPlace=possibleShip->getShip();
                board->removeShip(shipToPlace);
                for (int i = 0; i < shipRenders.size(); ++i) {
                    if(shipRenders[i]->getShip()==shipToPlace){
                        shipPlaceIndex=i;
                        break;
                    }
                }
            }else{
                return;
            }

        }else if(boardMode==ShipPlacement && !disablePlace){
            board->addShip(shipToPlace);
            shipToPlace=nullptr;
            startPlacingNextShip();
        }else if(boardMode==Attack && !turnCompleted){
            QPointF mouseLocation = e->scenePos();
            mouseLocation /= tileSize;
            BattleshipBoardTile tile;
            try {
                tile = board->getTile(mouseLocation.x(), mouseLocation.y());
            } catch (TileOutOfBoundsException&) {
                return;
            }

            if(tile.isHit() || tile.isMissed()|| tile.isPinged()){
                return;
            }

            if(board->fireAtLocation(Point(mouseLocation.x(), mouseLocation.y()))){
                std::cout<<"TEST"<<std::endl;
                drawExplosion(mouseLocation.x(), mouseLocation.y());
            }else{
                std::cout<<"TEST"<<std::endl;
                drawMiss(mouseLocation.x(), mouseLocation.y());
            }
            updateShipRenders();
            update((int)(mouseLocation.x()-1)*tileSize,(int)(mouseLocation.y()-1)*tileSize,tileSize*3,tileSize*3);
            boardLabel->setText("Click to advance game.");
            boardLabel->setVisible(true);
            turnCompleted=true;
        }
    }else if (e->button()==Qt::RightButton)  {
        if(boardMode==ShipPlacement){
             shipRenders[shipPlaceIndex]->rotateShip();
             disablePlace = collidingItems(shipRenders[shipPlaceIndex]).size()>shipToPlace->getSize() || !shipToPlace->hasValidLocations(board->getSize());
        }

    }

}

void BoardRender::drawExplosion(int tileX, int tileY){
    gifHolder= new QLabel();
    gifHolder->setAttribute(Qt::WA_NoSystemBackground);
    gifHolder->setMovie(explosionMovie);
    explosionMovie->start();
    gifHolder->move(tileX*tileSize,tileY*tileSize);

   holderProxy = addWidget(gifHolder);
}

void BoardRender::drawMiss(int tileX, int tileY){
    gifHolder= new QLabel();
    gifHolder->setAttribute(Qt::WA_NoSystemBackground);
    gifHolder->setMovie(missMovie);
    missMovie->start();
    gifHolder->move(tileX*tileSize,tileY*tileSize);

   holderProxy = addWidget(gifHolder);
}

void BoardRender::explosionFrameChanged_Handler(int frameNumber)
{
    if(frameNumber == (explosionMovie->frameCount()-1)) {
            explosionMovie->stop();
            removeItem(holderProxy);
     }
}

void BoardRender::missFrameChanged_Handler(int frameNumber)
{
    if(frameNumber == (missMovie->frameCount()-1)) {
            missMovie->stop();
            removeItem(holderProxy);
     }
}

void BoardRender::drawGrid()
{
    for (int x = 0; x < boardSize; ++x) {
        for (int y = 0; y < boardSize; ++y) {
            addItem(new BoardRenderTile(x*tileSize ,y*tileSize, tileSize, &board->getTile(x,y)));
        }
    }
}

void BoardRender::updateShipRenders()
{
    std::vector<Ship *> ships = board->getShips();
    if(boardMode==Attack){
        for each (ShipRender* shipRender in shipRenders){
            removeItem(shipRender);
        }
        for each (ShipRender* shipRender in shipRenders){
            if(shipRender->isDead()){
                shipRender->updateSprite();
                addItem(shipRender);
            }
        }
        return;
    }

    if(boardMode==View){
        for each (ShipRender* shipRender in shipRenders){
            addItem(shipRender);
        }
    }
    for( int i=0; i<ships.size();++i) {
        if(i<shipRenders.size()){
            shipRenders[i]->redraw();
        }else{
            ShipRender* temp = new ShipRender(ships[i], tileSize);
            addItem(temp);
            shipRenders.push_back(temp);
        }
    }
}

void BoardRender::viewMode()
{
     boardMode = View;
     std::cout << "Board Mode = " << boardMode << std::endl;
     updateShipRenders();
}

void BoardRender::attackMode()
{
    boardMode = Attack;
    updateShipRenders();
}

void BoardRender::confrimPlace()
{
    if(boardMode==ShipConfirmation){
        boardMode=Attack;
        boardLabel->setVisible(false);
        updateShipRenders();
        update(0,0,boardSize*tileSize, boardSize*tileSize);
        parent->endTurn();
    }
}

int BoardRender::getBoardMode()
{
    return boardMode;
}

void BoardRender::updateSize(int size)
{

    tileSize=size/boardSize;
    for each (ShipRender* shipRender in shipRenders){
        shipRender->updateTileSize(tileSize);
        removeItem(shipRender);
    }
    clear();
    drawGrid();

    for each (ShipRender* shipRender in shipRenders){
        addItem(shipRender);
    }
    updateShipRenders();
    explosionMovie->setScaledSize(QSize(tileSize,tileSize));
    missMovie->setScaledSize(QSize(tileSize,tileSize));
}

BoardRenderTile::BoardRenderTile(int _x, int _y, int _size, BattleshipBoardTile* _tile) : x(_x), y(_y), size(_size), highlighted(false), tile(_tile)
{}

QRectF BoardRenderTile::boundingRect() const
{
    return QRectF(x,y,size,size);
}

void BoardRenderTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor colorOfTile = Qt::GlobalColor::transparent;
    if(tile->isHit() || highlighted){
        colorOfTile= Qt::GlobalColor::red;
    }else if(tile->isPinged()){
        colorOfTile= Qt::GlobalColor::cyan;
    }else if(tile->isMissed()){
        colorOfTile= Qt::GlobalColor::white;
    }
    painter->fillRect(x,y,size,size, colorOfTile);

    painter->drawRect(x,y,size,size);
}

void BoardRenderTile::setHighlighted(bool value)
{
    highlighted=value;
    update(boundingRect());
}

void BoardRender::setGameOver()
{
    addText("Game Over",QFont("Arial",30,2,false))->moveBy(tileSize*(boardSize-3)/2,tileSize*boardSize/2);

    boardMode=GameOver;
}
