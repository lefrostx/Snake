#include "gamemain.h"

GameSnake::GameMain::GameMain(QWidget *panel, QWidget *parent) :
    QWidget{parent}
{
    drawer = new Drawer{panel, this};
    auto showFunc = [this](int row, int col, Cell cell){return drawer->setCell(row, col, cell);};
    map = new Map{panel->height() / cellSize, panel->width() / cellSize, showFunc};
    snake.reset(new Snake(*map));
}

void GameSnake::GameMain::moveSnake()
{
    snake->move();
}

void GameSnake::GameMain::turnLeft()
{
    snake->turn(Direction::left);
}

void GameSnake::GameMain::turnRight()
{
    snake->turn(Direction::right);
}

void GameSnake::GameMain::turnUp()
{
    snake->turn(Direction::up);
}

void GameSnake::GameMain::turnDown()
{
    snake->turn(Direction::down);
}
