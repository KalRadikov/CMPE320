#pragma once
#include "../BattleScrabble/Game.h"
#include <QGraphicsScene>
#include "playerrender.h"
#include <vector>
#include <QLabel>

class PlayerRender;

class GameRender:public QGraphicsScene
{
public:
    GameRender(Game *_game, QGraphicsView *_playerView, QLabel* _turnLabel, QLabel* _boardLabel, QObject* parent, QLabel* carrierLabel, QLabel* carrierSpriteLabel, QLabel* battleshipLabel, QLabel* battleshipSpriteLabel, QLabel* subLabel, QLabel* subSpriteLabel, QLabel* cruiserLabel, QLabel* cruiserSpriteLabel, QLabel* destroyerLabel, QLabel* destroyerSpriteLabel, QWidget *_confirmButton);
    void updateGameScreen();
    int getBoardWidth() const;
    void updateBoardViewSize(int size);
    void viewMyBoard();
    void confimShips();
private:
    Game* game;
    std::vector<PlayerRender*> playerRenders;
    QGraphicsView* playerView;
    QLabel* playerLabel;
    QWidget* confirmButton;
};

