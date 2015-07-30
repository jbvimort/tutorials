/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *load1;
    QWidget *inputDisplay;
    QLineEdit *input1;
    QPushButton *load2;
    QLineEdit *input2;
    QRadioButton *unio;
    QRadioButton *inter;
    QRadioButton *diff;
    QPushButton *aplication;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(475, 331);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        load1 = new QPushButton(centralWidget);
        load1->setObjectName(QStringLiteral("load1"));
        load1->setGeometry(QRect(350, 30, 114, 32));
        inputDisplay = new QWidget(centralWidget);
        inputDisplay->setObjectName(QStringLiteral("inputDisplay"));
        inputDisplay->setGeometry(QRect(9, 9, 301, 251));
        input1 = new QLineEdit(centralWidget);
        input1->setObjectName(QStringLiteral("input1"));
        input1->setGeometry(QRect(350, 10, 113, 21));
        load2 = new QPushButton(centralWidget);
        load2->setObjectName(QStringLiteral("load2"));
        load2->setGeometry(QRect(350, 90, 114, 32));
        input2 = new QLineEdit(centralWidget);
        input2->setObjectName(QStringLiteral("input2"));
        input2->setGeometry(QRect(350, 70, 113, 21));
        unio = new QRadioButton(centralWidget);
        unio->setObjectName(QStringLiteral("unio"));
        unio->setGeometry(QRect(350, 130, 102, 20));
        inter = new QRadioButton(centralWidget);
        inter->setObjectName(QStringLiteral("inter"));
        inter->setGeometry(QRect(350, 160, 102, 20));
        diff = new QRadioButton(centralWidget);
        diff->setObjectName(QStringLiteral("diff"));
        diff->setGeometry(QRect(350, 190, 102, 20));
        aplication = new QPushButton(centralWidget);
        aplication->setObjectName(QStringLiteral("aplication"));
        aplication->setGeometry(QRect(343, 220, 121, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 475, 22));
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
        load1->setText(QApplication::translate("MainWindow", "Load figure 1", 0));
        load2->setText(QApplication::translate("MainWindow", "Load figure 2", 0));
        unio->setText(QApplication::translate("MainWindow", "uniom", 0));
        inter->setText(QApplication::translate("MainWindow", "intersection", 0));
        diff->setText(QApplication::translate("MainWindow", "difference", 0));
        aplication->setText(QApplication::translate("MainWindow", "Filter aplication", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
