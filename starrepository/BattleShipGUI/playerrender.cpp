#include "playerrender.h"
#include <QGraphicsView>
#include "gamerender.h"

PlayerRender::PlayerRender(Player *_player, QLabel *boardLabel, GameRender* parent, QLabel* carrierLabelPtr, QLabel* carrierSpriteLabelPtr, QLabel* battleshipLabelPtr, QLabel* battleshipSpriteLabelPtr, QLabel* subLabelPtr, QLabel* subSpriteLabelPtr, QLabel* cruiserLabelPtr, QLabel* cruiserSpriteLabelPtr, QLabel* destroyerLabelPtr, QLabel* destroyerSpriteLabelPtr, QWidget *_confirmButton) : QGraphicsScene(parent), gameRender(parent)
{

    player=_player;
    boardRender=new BoardRender(player->getBattleshipBoard(), gameRender->getBoardWidth(), boardLabel, _confirmButton, this);
    drawEnemy=false;
    carrierLabel = carrierLabelPtr;
    carrierSpriteLabel = carrierSpriteLabelPtr;
    battleshipLabel = battleshipLabelPtr;
    battleshipSpriteLabel = battleshipSpriteLabelPtr;
    subLabel = subLabelPtr;
    subSpriteLabel = subSpriteLabelPtr;
    cruiserLabel = cruiserLabelPtr;
    cruiserSpriteLabel = cruiserSpriteLabelPtr;
    destroyerLabel = destroyerLabelPtr;
    destroyerSpriteLabel = destroyerSpriteLabelPtr;
}

void PlayerRender::drawToView(QGraphicsView *view)
{
    std::vector<QString> healths;
    std::vector<Ship*> ships = player->getBattleshipBoard()->getShips();
    int i;
    for(i=0;i<ships.size();i++){
        healths.push_back(QString::number((ships[i]->getHealth())));
    }
    if(drawEnemy){
        QPixmap * battlePix = new QPixmap("../BattleshipGUI/Sprites/battleship.svg");
        battleshipSpriteLabel->setPixmap(*battlePix);
        battleshipSpriteLabel->setScaledContents( true );
        battleshipSpriteLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        delete battlePix;

        QPixmap * carrierPix = new QPixmap("../BattleshipGUI/Sprites/carrier.svg");
        carrierSpriteLabel->setPixmap(*carrierPix);
        carrierSpriteLabel->setScaledContents( true );
        carrierSpriteLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        delete carrierPix;

        QPixmap * cruiserPix = new QPixmap("../BattleshipGUI/Sprites/cruiser.svg");
        cruiserSpriteLabel->setPixmap(*cruiserPix);
        cruiserSpriteLabel->setScaledContents( true );
        cruiserSpriteLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        delete cruiserPix;

        QPixmap * subPix = new QPixmap("../BattleshipGUI/Sprites/submarine.svg");
        subSpriteLabel->setPixmap(*subPix);
        subSpriteLabel->setScaledContents( true );
        subSpriteLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        delete subPix;

        QPixmap * destroyerPix = new QPixmap("../BattleshipGUI/Sprites/destroyer.svg");
        destroyerSpriteLabel->setPixmap(*destroyerPix);
        destroyerSpriteLabel->setScaledContents( true );
        destroyerSpriteLabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        delete destroyerPix;

        view->setScene(enemyBoardRender);
        carrierLabel->setText(healths[0]);
        battleshipLabel->setText(healths[1]);
        subLabel->setText(healths[2]);
        cruiserLabel->setText(healths[3]);
        destroyerLabel->setText(healths[4]);
    }else{
        view->setScene(boardRender);
        drawEnemy=true;
    }
}

void PlayerRender::endTurn()
{
    player->endMove();
    gameRender->updateGameScreen();
}

BoardRender *PlayerRender::getBoardRender() const
{
    return boardRender;
}

void PlayerRender::setEnemyBoardRender(BoardRender *board)
{
    enemyBoardRender=board;
}

void PlayerRender::updateBoardSize(int size)
{
    boardRender->updateSize(size);
}


void PlayerRender::setDrawEnemy(bool draw)
{
    drawEnemy = draw;
}
