#ifndef DIFFICULTYWINDOW_H
#define DIFFICULTYWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include <QButtonGroup>

namespace Ui {
class difficultyWindow;
}

class difficultyWindow : public QDialog
{
    Q_OBJECT

public:
    enum Difficult{
        EASY,
        MEDIUM,
        HARD

    };
    explicit difficultyWindow(QWidget *parent = 0);
    ~difficultyWindow();

private slots:
    void onClicked(int id);

private:
    Ui::difficultyWindow *ui;
    MainWindow *mWindow;
    QButtonGroup *group;
};

#endif // DIFFICULTYWINDOW_H
