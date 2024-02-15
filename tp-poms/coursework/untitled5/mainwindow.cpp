
#include "mainwindow.h"
#include "ui_mainwindow.h"

#define SRC_Background "D:\\Git files\\study\\tp-poms\\coursework\\lolxd\\background_1.gif"
#define SRC_People1 "D:\\Git files\\study\\tp-poms\\coursework\\lolxd\\people_1.png"
#define SRC_People2 "D:\\Git files\\study\\tp-poms\\coursework\\lolxd\\people_2.png"
// main resources

#define SRC_Train_1 "D:\\Git files\\study\\tp-poms\\coursework\\lolxd\\trains (1) (2).png"
#define SRC_Train_2 "D:\\Git files\\study\\tp-poms\\coursework\\lolxd\\m_trains (1) (2).png"
// trains

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time = 0;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Timerslot()));
    timer->start(10);
    QMovie *background_gif = new QMovie(SRC_Background);
    ui->background->setMovie(background_gif);
    ui->background->show();
    background_gif->start();

    ui->train->setPixmap(QPixmap(SRC_Train_1));
    ui->train_1->setPixmap(QPixmap(SRC_Train_2));
    ui->train_2->setPixmap(QPixmap(SRC_Train_1));
    ui->people->setPixmap(QPixmap(SRC_People1));
    ui->people_1->setPixmap(QPixmap(SRC_People2));

}
void MainWindow::Timerslot()
{
    time++;
    //ui->timer_txt->setText(QString::number(time));
    if(time <= 500)
    {
        if(ui->train->geometry().x() > 300)
        {
            ui->train->setGeometry(ui->train->geometry().x() - 2,170,1401,511);
        }
    }
    if(time >= 500 && time <= 600)
    {
        ui->people->clear();
        ui->people_1->clear();
    }
    if(time >= 700 && time <= 750)
    {
        if(ui->train->geometry().x() > -1300)
        {
            ui->train->setGeometry(ui->train->geometry().x() - 3,170,1401,511);
        }
    }
    if(time >= 750)
    {
        if(ui->train->geometry().x() > -1300)
        {
            ui->train->setGeometry(ui->train->geometry().x() - 5,170,1401,511);
        }
    }
    if(time >= 1050)
    {
        if(ui->train_1->geometry().x() < 1400)
        {
            ui->train_1->setGeometry(ui->train_1->geometry().x() + 5,220,1251,391);
        }
    }
    if(time >= 1350 && time <= 1850)
    {
        if(ui->train_2->geometry().x() > 300)
        {
            ui->train_2->setGeometry(ui->train_2->geometry().x() - 2,170,1401,511);
        }
    }
    if(time >= 1850 && time <= 1950)
    {
        ui->people->setPixmap(QPixmap(SRC_People1));
        ui->people_1->setPixmap(QPixmap(SRC_People2));
    }
    if(time >= 1950 && time <= 2000)
    {
        if(ui->train_2->geometry().x() > -1300)
        {
            ui->train_2->setGeometry(ui->train_2->geometry().x() - 3,170,1401,511);
        }
    }
    if(time >= 2000)
    {
        if(ui->train_2->geometry().x() > -1300)
        {
            ui->train_2->setGeometry(ui->train_2->geometry().x() - 5,170,1401,511);
        }
    }
    if(time >= 2500)
    {
        QApplication::exit();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


