#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->panel->resize(910, 610);
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::moveSnake);
    timer->start(100);

    map = new Snake::Map(ui->panel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::moveSnake()
{
    map->moveSnake();
}

void MainWindow::keyPressEvent(QKeyEvent *pe)
{
    switch(pe->key()) {
    case Qt::Key_Up:     map->turnUp();      break;
    case Qt::Key_Down:   map->turnDown();    break;
    case Qt::Key_Left:   map->turnLeft();    break;
    case Qt::Key_Right:  map->turnRight();   break;
    }
}
