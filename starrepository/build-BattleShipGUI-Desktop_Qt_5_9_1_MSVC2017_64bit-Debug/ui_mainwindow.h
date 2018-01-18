/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
    QSpacerItem *horizontalSpacer_3;
    QPushButton *showMine;
    QSpacerItem *horizontalSpacer_4;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *playerTurnLabel;
    QLabel *boardTurnLabel;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *battleshipBoardView;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *shipHealthLabel;
    QLabel *destoryerSpriteLabel;
    QLabel *carrierLabel;
    QLabel *subSpriteLabel;
    QLabel *battleshipLabel;
    QLabel *battleshipSpriteLabel;
    QLabel *subLabel;
    QLabel *cruiserSpriteLabel;
    QLabel *cruiserLabel;
    QLabel *carrierSpriteLabel;
    QLabel *destroyerLabel;
    QPushButton *specialMissileButton;
    QPushButton *defaultMissileButton;
    QPushButton *confrimButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(994, 960);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(938, 960));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/Sprites/sss.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(100, 100, 100)"));
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
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        showMine = new QPushButton(frame);
        showMine->setObjectName(QStringLiteral("showMine"));
        showMine->setMinimumSize(QSize(600, 65));
        showMine->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"background-color: rgb(87, 136, 200);\n"
"border-color: rgb(143, 203, 255);\n"
"border-radius: 5px;"));

        horizontalLayout->addWidget(showMine);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(frame);

        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(0, 155));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        playerTurnLabel = new QLabel(frame_4);
        playerTurnLabel->setObjectName(QStringLiteral("playerTurnLabel"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        playerTurnLabel->setFont(font);
        playerTurnLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));
        playerTurnLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(playerTurnLabel);

        boardTurnLabel = new QLabel(frame_4);
        boardTurnLabel->setObjectName(QStringLiteral("boardTurnLabel"));
        QFont font1;
        font1.setPointSize(10);
        boardTurnLabel->setFont(font1);
        boardTurnLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));
        boardTurnLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(boardTurnLabel);


        verticalLayout->addWidget(frame_4);

        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setStyleSheet(QStringLiteral(""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(179, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

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

        horizontalSpacer_2 = new QSpacerItem(179, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        battleshipBoardView->raise();

        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMinimumSize(QSize(0, 80));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        shipHealthLabel = new QLabel(frame_3);
        shipHealthLabel->setObjectName(QStringLiteral("shipHealthLabel"));
        shipHealthLabel->setStyleSheet(QStringLiteral("color: rgb(255,255,255)"));

        horizontalLayout_3->addWidget(shipHealthLabel);

        destoryerSpriteLabel = new QLabel(frame_3);
        destoryerSpriteLabel->setObjectName(QStringLiteral("destoryerSpriteLabel"));
        destoryerSpriteLabel->setMaximumSize(QSize(30, 80));

        horizontalLayout_3->addWidget(destoryerSpriteLabel);

        carrierLabel = new QLabel(frame_3);
        carrierLabel->setObjectName(QStringLiteral("carrierLabel"));
        carrierLabel->setStyleSheet(QStringLiteral("color: rgb(255,255,255)"));

        horizontalLayout_3->addWidget(carrierLabel);

        subSpriteLabel = new QLabel(frame_3);
        subSpriteLabel->setObjectName(QStringLiteral("subSpriteLabel"));
        subSpriteLabel->setMaximumSize(QSize(30, 80));

        horizontalLayout_3->addWidget(subSpriteLabel);

        battleshipLabel = new QLabel(frame_3);
        battleshipLabel->setObjectName(QStringLiteral("battleshipLabel"));
        battleshipLabel->setStyleSheet(QStringLiteral("color: rgb(255,255,255)"));

        horizontalLayout_3->addWidget(battleshipLabel);

        battleshipSpriteLabel = new QLabel(frame_3);
        battleshipSpriteLabel->setObjectName(QStringLiteral("battleshipSpriteLabel"));
        battleshipSpriteLabel->setMaximumSize(QSize(20, 140));

        horizontalLayout_3->addWidget(battleshipSpriteLabel);

        subLabel = new QLabel(frame_3);
        subLabel->setObjectName(QStringLiteral("subLabel"));
        subLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(subLabel);

        cruiserSpriteLabel = new QLabel(frame_3);
        cruiserSpriteLabel->setObjectName(QStringLiteral("cruiserSpriteLabel"));
        cruiserSpriteLabel->setMaximumSize(QSize(25, 70));
        cruiserSpriteLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));

        horizontalLayout_3->addWidget(cruiserSpriteLabel);

        cruiserLabel = new QLabel(frame_3);
        cruiserLabel->setObjectName(QStringLiteral("cruiserLabel"));
        cruiserLabel->setStyleSheet(QStringLiteral("color: rgb(255,255,255)"));

        horizontalLayout_3->addWidget(cruiserLabel);

        carrierSpriteLabel = new QLabel(frame_3);
        carrierSpriteLabel->setObjectName(QStringLiteral("carrierSpriteLabel"));
        carrierSpriteLabel->setMaximumSize(QSize(20, 140));

        horizontalLayout_3->addWidget(carrierSpriteLabel);

        destroyerLabel = new QLabel(frame_3);
        destroyerLabel->setObjectName(QStringLiteral("destroyerLabel"));
        destroyerLabel->setStyleSheet(QStringLiteral("color: rgb(255,255,255)"));

        horizontalLayout_3->addWidget(destroyerLabel);

        specialMissileButton = new QPushButton(frame_3);
        specialMissileButton->setObjectName(QStringLiteral("specialMissileButton"));
        specialMissileButton->setCursor(QCursor(Qt::ArrowCursor));
        specialMissileButton->setAutoFillBackground(false);
        specialMissileButton->setStyleSheet(QLatin1String("color: rgb(255,255,255)\n"
""));
        specialMissileButton->setIconSize(QSize(64, 64));

        horizontalLayout_3->addWidget(specialMissileButton);

        defaultMissileButton = new QPushButton(frame_3);
        defaultMissileButton->setObjectName(QStringLiteral("defaultMissileButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(defaultMissileButton->sizePolicy().hasHeightForWidth());
        defaultMissileButton->setSizePolicy(sizePolicy3);
        defaultMissileButton->setBaseSize(QSize(64, 64));
        defaultMissileButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255)"));
        defaultMissileButton->setIconSize(QSize(64, 64));

        horizontalLayout_3->addWidget(defaultMissileButton);

        confrimButton = new QPushButton(frame_3);
        confrimButton->setObjectName(QStringLiteral("confrimButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(confrimButton->sizePolicy().hasHeightForWidth());
        confrimButton->setSizePolicy(sizePolicy4);
        confrimButton->setMinimumSize(QSize(160, 75));
        confrimButton->setStyleSheet(QLatin1String("font: 10pt \"MS Shell Dlg 2\";\n"
"border-style: solid;\n"
"border-width: 3px;\n"
"background-color: rgb(87, 136, 200);\n"
"border-color: rgb(143, 203, 255);\n"
"border-radius: 5px;\n"
""));

        horizontalLayout_3->addWidget(confrimButton);


        verticalLayout->addWidget(frame_3);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BATTLESHIP++", Q_NULLPTR));
        showMine->setText(QApplication::translate("MainWindow", "Toggle Board View", Q_NULLPTR));
        playerTurnLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        boardTurnLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        shipHealthLabel->setText(QApplication::translate("MainWindow", "Ship Healths:", Q_NULLPTR));
        destoryerSpriteLabel->setText(QString());
        carrierLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        subSpriteLabel->setText(QString());
        battleshipLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        battleshipSpriteLabel->setText(QString());
        subLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        cruiserSpriteLabel->setText(QString());
        cruiserLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        carrierSpriteLabel->setText(QString());
        destroyerLabel->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        specialMissileButton->setText(QApplication::translate("MainWindow", "x3", Q_NULLPTR));
        defaultMissileButton->setText(QString());
        confrimButton->setText(QApplication::translate("MainWindow", "Confirm Placement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
