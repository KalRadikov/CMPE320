/********************************************************************************
** Form generated from reading UI file 'difficultywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIFFICULTYWINDOW_H
#define UI_DIFFICULTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_difficultyWindow
{
public:
    QPushButton *easyDiffButton;
    QPushButton *mediumDifficultyButton;
    QPushButton *hardDifficultyButton;
    QLabel *label;

    void setupUi(QDialog *difficultyWindow)
    {
        if (difficultyWindow->objectName().isEmpty())
            difficultyWindow->setObjectName(QStringLiteral("difficultyWindow"));
        difficultyWindow->resize(485, 385);
        difficultyWindow->setMinimumSize(QSize(485, 385));
        difficultyWindow->setMaximumSize(QSize(485, 385));
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/Sprites/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        difficultyWindow->setWindowIcon(icon);
        easyDiffButton = new QPushButton(difficultyWindow);
        easyDiffButton->setObjectName(QStringLiteral("easyDiffButton"));
        easyDiffButton->setGeometry(QRect(110, 70, 271, 81));
        easyDiffButton->setStyleSheet(QLatin1String("color:green;\n"
"font-size: 20px;"));
        mediumDifficultyButton = new QPushButton(difficultyWindow);
        mediumDifficultyButton->setObjectName(QStringLiteral("mediumDifficultyButton"));
        mediumDifficultyButton->setGeometry(QRect(110, 170, 271, 81));
        mediumDifficultyButton->setStyleSheet(QStringLiteral("font-size: 20px;"));
        hardDifficultyButton = new QPushButton(difficultyWindow);
        hardDifficultyButton->setObjectName(QStringLiteral("hardDifficultyButton"));
        hardDifficultyButton->setGeometry(QRect(110, 270, 271, 81));
        hardDifficultyButton->setStyleSheet(QLatin1String("color:red;\n"
"font-size: 20px;\n"
"\n"
""));
        label = new QLabel(difficultyWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 481, 41));
        label->setStyleSheet(QStringLiteral("font: 10pt;"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(difficultyWindow);

        QMetaObject::connectSlotsByName(difficultyWindow);
    } // setupUi

    void retranslateUi(QDialog *difficultyWindow)
    {
        difficultyWindow->setWindowTitle(QApplication::translate("difficultyWindow", "Battleship++", Q_NULLPTR));
        easyDiffButton->setText(QApplication::translate("difficultyWindow", "Easy", Q_NULLPTR));
        mediumDifficultyButton->setText(QApplication::translate("difficultyWindow", "Medium", Q_NULLPTR));
        hardDifficultyButton->setText(QApplication::translate("difficultyWindow", "Hard", Q_NULLPTR));
        label->setText(QApplication::translate("difficultyWindow", "Select your Difficulty", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class difficultyWindow: public Ui_difficultyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIFFICULTYWINDOW_H
