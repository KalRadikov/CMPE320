/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QPushButton *showEnemy;
    QPushButton *showMine;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *boardTurnLabel;
    QLabel *playerTurnLabel;
    QGraphicsView *battleshipBoardView;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *confrimButton;
    QGraphicsView *HUDview;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(860, 960);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Sprites/sss.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(207, 208, 228);\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 75));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        showEnemy = new QPushButton(frame);
        showEnemy->setObjectName(QStringLiteral("showEnemy"));
        showEnemy->setMinimumSize(QSize(121, 65));
        showEnemy->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"background-color: rgb(87, 136, 200);\n"
"border-color: rgb(143, 203, 255);\n"
"border-radius: 5px;"));
        showEnemy->setAutoDefault(false);

        horizontalLayout->addWidget(showEnemy);

        showMine = new QPushButton(frame);
        showMine->setObjectName(QStringLiteral("showMine"));
        showMine->setMinimumSize(QSize(121, 65));
        showMine->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"background-color: rgb(87, 136, 200);\n"
"border-color: rgb(143, 203, 255);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(showMine);


        verticalLayout->addWidget(frame);

        verticalSpacer_2 = new QSpacerItem(20, 48, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(135, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        boardTurnLabel = new QLabel(frame_2);
        boardTurnLabel->setObjectName(QStringLiteral("boardTurnLabel"));

        horizontalLayout_2->addWidget(boardTurnLabel);

        playerTurnLabel = new QLabel(frame_2);
        playerTurnLabel->setObjectName(QStringLiteral("playerTurnLabel"));

        horizontalLayout_2->addWidget(playerTurnLabel);

        battleshipBoardView = new QGraphicsView(frame_2);
        battleshipBoardView->setObjectName(QStringLiteral("battleshipBoardView"));
        battleshipBoardView->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(battleshipBoardView->sizePolicy().hasHeightForWidth());
        battleshipBoardView->setSizePolicy(sizePolicy2);
        battleshipBoardView->setMinimumSize(QSize(540, 540));
        battleshipBoardView->setAutoFillBackground(false);
        battleshipBoardView->setStyleSheet(QLatin1String("border-style: double;\n"
"/*background-image: url(:/new/prefix1/Sprites/tex_Water.jpg);*/\n"
"/*background-color: rgb(0, 0, 255);*/\n"
"border-width: 5px;\n"
"border-color: grey;"));
        battleshipBoardView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        battleshipBoardView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        battleshipBoardView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        battleshipBoardView->setForegroundBrush(brush1);
        battleshipBoardView->setSceneRect(QRectF(0, 0, 0, 0));

        horizontalLayout_2->addWidget(battleshipBoardView);

        horizontalSpacer_2 = new QSpacerItem(135, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        battleshipBoardView->raise();
        playerTurnLabel->raise();
        boardTurnLabel->raise();

        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 59));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        confrimButton = new QPushButton(frame_3);
        confrimButton->setObjectName(QStringLiteral("confrimButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(confrimButton->sizePolicy().hasHeightForWidth());
        confrimButton->setSizePolicy(sizePolicy3);
        confrimButton->setMinimumSize(QSize(160, 59));
        confrimButton->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"background-color: rgb(87, 136, 200);\n"
"border-color: rgb(143, 203, 255);\n"
"border-radius: 5px;\n"
""));

        horizontalLayout_3->addWidget(confrimButton);


        verticalLayout->addWidget(frame_3);

        HUDview = new QGraphicsView(centralWidget);
        HUDview->setObjectName(QStringLiteral("HUDview"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(HUDview->sizePolicy().hasHeightForWidth());
        HUDview->setSizePolicy(sizePolicy4);
        HUDview->setMinimumSize(QSize(771, 80));
        HUDview->setStyleSheet(QLatin1String("border-style: double;\n"
"border-width: 5px;\n"
"border-color: grey;"));

        verticalLayout->addWidget(HUDview);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BATTLESHIP++", Q_NULLPTR));
        showEnemy->setText(QApplication::translate("MainWindow", "Show Emeny Board", Q_NULLPTR));
        showMine->setText(QApplication::translate("MainWindow", "Show My Board", Q_NULLPTR));
        boardTurnLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        playerTurnLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        confrimButton->setText(QApplication::translate("MainWindow", "Confirm Placment", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
