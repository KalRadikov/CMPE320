#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "../BattleScrabble/BattleshipBoard.h"
#include "../BattleScrabble/HumanPlayer.h"
#include "difficultywindow.h"
#include "../BattleScrabble/Game.h"
int p1specialAmmoCount;
int p2specialAmmoCount;

MainWindow::MainWindow(int grid, QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*
    QPixmap pixmap("sprites/torpedo.png");
    QIcon ButtonIcon(pixmap);
    ui->specialMissileButton->setIcon(ButtonIcon);
    ui->specialMissileButton->setIconSize(pixmap.rect().size());
    */
    ui->setupUi(this);
    ui->battleshipBoardView->setMouseTracking(true);

    g = new Game(grid);
    game = new GameRender(g, ui->battleshipBoardView, ui->playerTurnLabel,ui->boardTurnLabel,this, ui->carrierLabel, ui->carrierSpriteLabel, ui->battleshipLabel, ui->battleshipSpriteLabel, ui->subLabel, ui->subSpriteLabel, ui->cruiserLabel, ui->cruiserSpriteLabel, ui->destroyerLabel, ui->destoryerSpriteLabel, ui->confrimButton);
    ui->boardTurnLabel->setVisible(false);
    p1specialAmmoCount = g->getAmmoCount();
    p2specialAmmoCount = g->getAmmoCount();
    game->updateGameScreen();

    ui->specialMissileButton->setIcon(QIcon("../BattleshipGUI/Sprites/3missile.png"));
    ui->specialMissileButton->setIconSize(QSize(65,65));

    ui->defaultMissileButton->setIcon(QIcon("../BattleshipGUI/Sprites/missile2.png"));
    ui->defaultMissileButton->setIconSize(QSize(65,65));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    int minValue = min(ui->battleshipBoardView->width(),ui->battleshipBoardView->height());
    ui->battleshipBoardView->resize(minValue,minValue);
    game->updateBoardViewSize(ui->battleshipBoardView->width());

}
void MainWindow::on_confrimButton_clicked()
{
    game->confimShips();
}

void MainWindow::on_showMine_clicked()
{
    game->viewMyBoard();
}


void MainWindow::on_defaultMissileButton_clicked()
{
    ui->defaultMissileButton->setCheckable(true);

    ui->defaultMissileButton->setChecked(true);
    ui->specialMissileButton->setChecked(false);

    g->selectAmmo(0);


}

void MainWindow::on_specialMissileButton_clicked()
{
    ui->specialMissileButton->setCheckable(true);

    ui->specialMissileButton->setChecked(true);
    ui->defaultMissileButton->setChecked(false);

    QString text;
    if(g->getCurrentTurn() == 0){
        p1specialAmmoCount--;
        g->selectAmmo(1);
        text = QString("x%1").arg(p1specialAmmoCount);
    } else {
        p2specialAmmoCount--;
        g->selectAmmo(1);
        text = QString("x%1").arg(p2specialAmmoCount);
    }
    ui->specialMissileButton->setText(text);

}
