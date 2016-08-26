#include <QPixmap>
#include <QString>
#include "box.h"

Snake::Box::Box(Snake::Cell cell, QWidget *parent) :
    QLabel{parent}
{
    setCell(cell);
}

void Snake::Box::setCell(Snake::Cell cell)
{
    QString filename;

    switch(cell) {
    case Cell::empty:   filename = ":/empty.png";   break;
    case Cell::wall:    filename = ":/wall.png";    break;
    case Cell::rabbit:  filename = ":/rabbit.png";  break;
    case Cell::snake:   filename = ":/snake.png";   break;
    }

    setPixmap(filename);
}
