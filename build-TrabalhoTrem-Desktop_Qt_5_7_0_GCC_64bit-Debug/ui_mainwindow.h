/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelTrem01;
    QLabel *labelTrilho02;
    QLabel *labelTrilho00;
    QLabel *labelTrem00;
    QLabel *labelTrem02;
    QLabel *labelTrem03;
    QLabel *labelTrilho03;
    QLabel *labelTrilho01;
    QLabel *label_4;
    QLCDNumber *count1;
    QLabel *label;
    QLCDNumber *count2;
    QLabel *label_5;
    QLCDNumber *count3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(728, 476);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        labelTrem01 = new QLabel(centralWidget);
        labelTrem01->setObjectName(QStringLiteral("labelTrem01"));
        labelTrem01->setGeometry(QRect(250, 220, 20, 20));
        labelTrem01->setStyleSheet(QStringLiteral("background-color: rgb(11, 43, 250)"));
        labelTrilho02 = new QLabel(centralWidget);
        labelTrilho02->setObjectName(QStringLiteral("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(300, 130, 140, 100));
        labelTrilho02->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrilho00 = new QLabel(centralWidget);
        labelTrilho00->setObjectName(QStringLiteral("labelTrilho00"));
        labelTrilho00->setGeometry(QRect(160, 30, 140, 100));
        labelTrilho00->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrem00 = new QLabel(centralWidget);
        labelTrem00->setObjectName(QStringLiteral("labelTrem00"));
        labelTrem00->setGeometry(QRect(170, 20, 20, 20));
        labelTrem00->setStyleSheet(QLatin1String("background-color: rgb(255, 0, 127)\n"
""));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QStringLiteral("labelTrem02"));
        labelTrem02->setGeometry(QRect(400, 120, 20, 20));
        labelTrem02->setStyleSheet(QStringLiteral("background-color: rgb(174, 10, 255)"));
        labelTrem03 = new QLabel(centralWidget);
        labelTrem03->setObjectName(QStringLiteral("labelTrem03"));
        labelTrem03->setGeometry(QRect(380, 320, 20, 20));
        labelTrem03->setStyleSheet(QStringLiteral("background-color: rgb(58, 255, 157)"));
        labelTrilho03 = new QLabel(centralWidget);
        labelTrilho03->setObjectName(QStringLiteral("labelTrilho03"));
        labelTrilho03->setGeometry(QRect(300, 230, 140, 100));
        labelTrilho03->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrilho01 = new QLabel(centralWidget);
        labelTrilho01->setObjectName(QStringLiteral("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(160, 130, 140, 100));
        labelTrilho01->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 30, 81, 20));
        count1 = new QLCDNumber(centralWidget);
        count1->setObjectName(QStringLiteral("count1"));
        count1->setGeometry(QRect(430, 60, 71, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(520, 30, 81, 20));
        count2 = new QLCDNumber(centralWidget);
        count2->setObjectName(QStringLiteral("count2"));
        count2->setGeometry(QRect(520, 60, 71, 31));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(610, 30, 81, 20));
        count3 = new QLCDNumber(centralWidget);
        count3->setObjectName(QStringLiteral("count3"));
        count3->setGeometry(QRect(610, 60, 71, 31));
        MainWindow->setCentralWidget(centralWidget);
        labelTrilho02->raise();
        labelTrilho00->raise();
        labelTrilho03->raise();
        labelTrilho01->raise();
        labelTrem01->raise();
        labelTrem03->raise();
        labelTrem02->raise();
        labelTrem00->raise();
        label_4->raise();
        count1->raise();
        label->raise();
        count2->raise();
        label_5->raise();
        count3->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 728, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelTrem01->setText(QString());
        labelTrilho02->setText(QString());
        labelTrilho00->setText(QString());
        labelTrem00->setText(QString());
        labelTrem02->setText(QString());
        labelTrem03->setText(QString());
        labelTrilho03->setText(QString());
        labelTrilho01->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Sem\303\241foro 1", 0));
        label->setText(QApplication::translate("MainWindow", "Sem\303\241foro 2", 0));
        label_5->setText(QApplication::translate("MainWindow", "Sem\303\241foro 3", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
