/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *background;
    QLabel *train;
    QLabel *people;
    QLabel *people_1;
    QLabel *timer_txt;
    QLabel *train_1;
    QLabel *train_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1384, 639);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(-350, -290, 1911, 981));
        background->setPixmap(QPixmap(QString::fromUtf8("../lolxd/background_1.gif")));
        train = new QLabel(centralwidget);
        train->setObjectName("train");
        train->setGeometry(QRect(1500, 170, 1401, 511));
        train->setPixmap(QPixmap(QString::fromUtf8("../lolxd/trains (1) (2).png")));
        people = new QLabel(centralwidget);
        people->setObjectName("people");
        people->setGeometry(QRect(760, 270, 151, 251));
        people->setPixmap(QPixmap(QString::fromUtf8("../lolxd/people_2.png")));
        people_1 = new QLabel(centralwidget);
        people_1->setObjectName("people_1");
        people_1->setGeometry(QRect(890, 270, 291, 251));
        people_1->setPixmap(QPixmap(QString::fromUtf8("../lolxd/people_1.png")));
        timer_txt = new QLabel(centralwidget);
        timer_txt->setObjectName("timer_txt");
        timer_txt->setGeometry(QRect(350, 130, 171, 111));
        train_1 = new QLabel(centralwidget);
        train_1->setObjectName("train_1");
        train_1->setGeometry(QRect(-1300, 220, 1251, 391));
        train_1->setPixmap(QPixmap(QString::fromUtf8("../lolxd/m_trains (1) (2).png")));
        train_2 = new QLabel(centralwidget);
        train_2->setObjectName("train_2");
        train_2->setGeometry(QRect(1500, 170, 1401, 511));
        train_2->setPixmap(QPixmap(QString::fromUtf8("../lolxd/trains (1) (2).png")));
        MainWindow->setCentralWidget(centralwidget);
        background->raise();
        people->raise();
        people_1->raise();
        train->raise();
        timer_txt->raise();
        train_2->raise();
        train_1->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1384, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        background->setText(QString());
        train->setText(QString());
        people->setText(QString());
        people_1->setText(QString());
        timer_txt->setText(QString());
        train_1->setText(QString());
        train_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
