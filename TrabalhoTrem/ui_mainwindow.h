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
    QLabel *labelTrilho01;
    QLabel *labelTrem01;
    QLabel *labelTrilho00;
    QLabel *labelTrilho02;
    QLabel *labelTrilho03;
    QLabel *labelTrem03;
    QLabel *labelTrem02;
    QLabel *labelTrem00;
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
        labelTrilho01 = new QLabel(centralWidget);
        labelTrilho01->setObjectName(QStringLiteral("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(160, 130, 140, 100));
        labelTrilho01->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrem01 = new QLabel(centralWidget);
        labelTrem01->setObjectName(QStringLiteral("labelTrem01"));
        labelTrem01->setGeometry(QRect(180, 120, 20, 20));
        labelTrem01->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrilho00 = new QLabel(centralWidget);
        labelTrilho00->setObjectName(QStringLiteral("labelTrilho00"));
        labelTrilho00->setGeometry(QRect(160, 30, 140, 100));
        labelTrilho00->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrilho02 = new QLabel(centralWidget);
        labelTrilho02->setObjectName(QStringLiteral("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(300, 130, 140, 100));
        labelTrilho02->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrilho03 = new QLabel(centralWidget);
        labelTrilho03->setObjectName(QStringLiteral("labelTrilho03"));
        labelTrilho03->setGeometry(QRect(300, 230, 140, 100));
        labelTrilho03->setStyleSheet(QLatin1String("background-color: transparent;\n"
"border: 1px solid black"));
        labelTrem03 = new QLabel(centralWidget);
        labelTrem03->setObjectName(QStringLiteral("labelTrem03"));
        labelTrem03->setGeometry(QRect(290, 270, 20, 20));
        labelTrem03->setStyleSheet(QStringLiteral("background-color: red"));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QStringLiteral("labelTrem02"));
        labelTrem02->setGeometry(QRect(400, 120, 20, 20));
        labelTrem02->setStyleSheet(QLatin1String("QLabel label;\n"
"QPixmap pixmap(\":/home/carlos/Desktop/SO/Trabalho-Final-SO/train/png\");\n"
"label.setPixmap(pixmap);\n"
"label.setMask(pixmap.mask());\n"
"\n"
"label.show();"));
        labelTrem00 = new QLabel(centralWidget);
        labelTrem00->setObjectName(QStringLiteral("labelTrem00"));
        labelTrem00->setGeometry(QRect(220, 20, 20, 20));
        labelTrem00->setStyleSheet(QStringLiteral("background-color: red"));
        MainWindow->setCentralWidget(centralWidget);
        labelTrilho01->raise();
        labelTrilho00->raise();
        labelTrilho02->raise();
        labelTrilho03->raise();
        labelTrem01->raise();
        labelTrem03->raise();
        labelTrem02->raise();
        labelTrem00->raise();
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
        labelTrilho01->setText(QString());
        labelTrem01->setText(QString());
        labelTrilho00->setText(QString());
        labelTrilho02->setText(QString());
        labelTrilho03->setText(QString());
        labelTrem03->setText(QString());
#ifndef QT_NO_TOOLTIP
        labelTrem02->setToolTip(QApplication::translate("MainWindow", "/home/carlos/Desktop/SO/Trabalho-Final-SO/train.png", 0));
#endif // QT_NO_TOOLTIP
        labelTrem02->setText(QString());
        labelTrem00->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
