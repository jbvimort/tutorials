/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QWidget *outputDisplay;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(789, 316);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        load1 = new QPushButton(centralWidget);
        load1->setObjectName(QString::fromUtf8("load1"));
        load1->setGeometry(QRect(350, 30, 114, 32));
        inputDisplay = new QWidget(centralWidget);
        inputDisplay->setObjectName(QString::fromUtf8("inputDisplay"));
        inputDisplay->setGeometry(QRect(9, 9, 301, 251));
        input1 = new QLineEdit(centralWidget);
        input1->setObjectName(QString::fromUtf8("input1"));
        input1->setGeometry(QRect(350, 10, 113, 21));
        load2 = new QPushButton(centralWidget);
        load2->setObjectName(QString::fromUtf8("load2"));
        load2->setGeometry(QRect(350, 80, 114, 32));
        input2 = new QLineEdit(centralWidget);
        input2->setObjectName(QString::fromUtf8("input2"));
        input2->setGeometry(QRect(350, 60, 113, 21));
        unio = new QRadioButton(centralWidget);
        unio->setObjectName(QString::fromUtf8("unio"));
        unio->setGeometry(QRect(350, 110, 102, 20));
        inter = new QRadioButton(centralWidget);
        inter->setObjectName(QString::fromUtf8("inter"));
        inter->setGeometry(QRect(350, 140, 102, 20));
        diff = new QRadioButton(centralWidget);
        diff->setObjectName(QString::fromUtf8("diff"));
        diff->setGeometry(QRect(350, 170, 102, 20));
        aplication = new QPushButton(centralWidget);
        aplication->setObjectName(QString::fromUtf8("aplication"));
        aplication->setGeometry(QRect(340, 220, 121, 32));
        outputDisplay = new QWidget(centralWidget);
        outputDisplay->setObjectName(QString::fromUtf8("outputDisplay"));
        outputDisplay->setGeometry(QRect(480, 10, 301, 251));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 270, 81, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(580, 270, 91, 20));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(350, 200, 131, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        load1->setText(QApplication::translate("MainWindow", "Load figure 1", 0, QApplication::UnicodeUTF8));
        load2->setText(QApplication::translate("MainWindow", "Load figure 2", 0, QApplication::UnicodeUTF8));
        unio->setText(QApplication::translate("MainWindow", "uniom", 0, QApplication::UnicodeUTF8));
        inter->setText(QApplication::translate("MainWindow", "intersection", 0, QApplication::UnicodeUTF8));
        diff->setText(QApplication::translate("MainWindow", "difference", 0, QApplication::UnicodeUTF8));
        aplication->setText(QApplication::translate("MainWindow", "Filter aplication", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Input figures", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Output figure", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("MainWindow", "intersection line", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
