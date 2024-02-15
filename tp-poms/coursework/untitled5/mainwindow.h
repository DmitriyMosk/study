
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "QTimer"
#include "QLabel"
#include "QMovie"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *label;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int time;

private slots:
    void Timerslot();
};

#endif // MAINWINDOW_H
