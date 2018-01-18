#include "difficultywindow.h"
#include "ui_difficultywindow.h"
#include "DifficultyWindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


difficultyWindow::difficultyWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::difficultyWindow)
{
    ui->setupUi(this);
    group = new QButtonGroup(this);
    group->addButton(ui->easyDiffButton, EASY);
    group->addButton(ui->mediumDifficultyButton, MEDIUM);
    group->addButton(ui->hardDifficultyButton, HARD);

    connect(group, SIGNAL(buttonClicked(int)), this, SLOT(onClicked(int)));
}

difficultyWindow::~difficultyWindow()
{
    delete ui;
}

void difficultyWindow::onClicked(int id)
{
    int grid;
    switch (id) {
    case EASY:
        grid = 10;
        break;
    case MEDIUM:
        grid = 20;
        break;
    case HARD:
        grid = 30;
        break;
    }
    mWindow = new MainWindow(grid,this);
    mWindow->show();
}
