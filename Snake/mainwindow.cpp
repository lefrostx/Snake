#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->panel->resize(900, 600);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::moveSnake);
    timer->start(100);

    game = new GameSnake::GameMain(ui->panel, this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveSnake()
{
    game->moveSnake();
}

void MainWindow::keyPressEvent(QKeyEvent *pe)
{
    switch(pe->key()) {
    case Qt::Key_Up:     game->turnUp();      break;
    case Qt::Key_Down:   game->turnDown();    break;
    case Qt::Key_Left:   game->turnLeft();    break;
    case Qt::Key_Right:  game->turnRight();   break;
    }
}
