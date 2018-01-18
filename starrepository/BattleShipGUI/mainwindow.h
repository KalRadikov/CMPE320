#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "boardrender.h"
#include "playerrender.h"
#include "../BattleScrabble/BattleshipBoard.h"
#include "../BattleScrabble/HumanPlayer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(int grid, QWidget *parent = 0);
    ~MainWindow();
protected:
    void resizeEvent(QResizeEvent* event);


    Game *g;
    GameRender *b;
private slots:
    void on_confrimButton_clicked();

    void on_showMine_clicked();

    void on_defaultMissileButton_clicked();

    void on_specialMissileButton_clicked();

private:
    Ui::MainWindow *ui;
     GameRender* game;
};

#endif // MAINWINDOW_H
