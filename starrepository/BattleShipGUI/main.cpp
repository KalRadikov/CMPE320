#include "mainwindow.h"
#include <QApplication>
#include "difficultywindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    difficultyWindow w;
    w.show();

    return a.exec();
}
