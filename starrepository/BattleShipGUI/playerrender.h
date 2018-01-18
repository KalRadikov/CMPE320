#pragma once
#include "../BattleScrabble/Player.h"
#include <QGraphicsScene>
#include "boardrender.h"
#include "gamerender.h"

class BoardRender;
class GameRender;

class PlayerRender : public QGraphicsScene
{
public:
    PlayerRender(Player *_player, QLabel* boardLabel, GameRender* parent, QLabel* carrierLabel, QLabel* carrierSpriteLabel, QLabel* battleshipLabel, QLabel* battleshipSpriteLabel, QLabel* subLabel, QLabel* subSpriteLabel, QLabel* cruiserLabel, QLabel* cruiserSpriteLabel, QLabel* destroyerLabel, QLabel* destroyerSpriteLabel, QWidget *_confirmButton);
    void drawToView(QGraphicsView* view);
    void endTurn();
    BoardRender *getBoardRender() const;
    void setEnemyBoardRender(BoardRender* board);
    void updateBoardSize(int size);
    void setDrawEnemy(bool draw);
private:
    Player* player;
    GameRender* gameRender;
    BoardRender* boardRender;
    BoardRender* enemyBoardRender;
    bool drawEnemy;
    QLabel* boardLabel;
    QLabel* carrierLabel;
    QLabel* carrierSpriteLabel;
    QLabel* battleshipLabel;
    QLabel* battleshipSpriteLabel;
    QLabel* subLabel;
    QLabel* subSpriteLabel;
    QLabel* cruiserLabel;
    QLabel* cruiserSpriteLabel;
    QLabel* destroyerLabel;
    QLabel* destroyerSpriteLabel;

};
