#include <QPixmap>
#include <QString>
#include "box.h"

GameSnake::Box::Box(GameSnake::Cell cell, QWidget *parent) :
    QLabel{parent}
{
    setCell(cell);
}

void GameSnake::Box::setCell(GameSnake::Cell cell)
{
    QString filename;

    switch(cell) {
    case Cell::empty:   filename = ":/empty.png";   break;
    case Cell::wall:    filename = ":/wall.png";    break;
    case Cell::rabbit:  filename = ":/rabbit.png";  break;
    case Cell::snake:   filename = ":/snake.png";   break;
    case Cell::head:    filename = ":/head.png";   break;
    }

    setPixmap(filename);
}
