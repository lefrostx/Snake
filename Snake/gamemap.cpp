#include "gamemap.h"
#include "mathematic.h"
#include <QDebug>

namespace {
    constexpr int cellSize = 30;
}

Snake::Map::Map(QWidget *parent) :
    QWidget(parent),
    data(parent->height() / cellSize, parent->width() / cellSize, Cell::empty),
    boxes(parent->height() / cellSize, parent->width() / cellSize)
{
    resize(parent->width(), parent->height());
    for (size_type row{}; row < boxes.size1(); ++row)
        for (size_type col{}; col < boxes.size2(); ++col) {
            boxes(row, col) = new Box{Cell::empty, parent};
            boxes(row, col)->resize(cellSize, cellSize);
            boxes(row, col)->move(col * cellSize, row * cellSize);
            boxes(row, col)->show();
        }

    createWall();
    for (int i{}; i < 5; ++i)
        addRabbit();

    addSnake();
    turnRight();
}

void Snake::Map::turnLeft()
{
    srow = 0;
    scol = -1;
}

void Snake::Map::turnRight()
{
    srow = 0;
    scol = 1;
}

void Snake::Map::turnUp()
{
    srow = -1;
    scol = 0;
}

void Snake::Map::turnDown()
{
    srow = 1;
    scol = 0;
}

void Snake::Map::moveSnake()
{
    Point newHead {head.row+srow, head.col+scol};
    if (inRange(newHead)) {

        if (data(newHead.row, newHead.col) == Cell::wall ||
            data(newHead.row, newHead.col) == Cell::snake )
            return;

        if (data(newHead.row, newHead.col) == Cell::empty) {
            head = newHead;

            Point tail = snake.front();
            snake.pop();
            snake.push(head);

            data(tail.row, tail.col) = Cell::empty;
            data(head.row, head.col) = Cell::snake;

            boxes(tail.row, tail.col)->setCell(Cell::empty);
            boxes(head.row, head.col)->setCell(Cell::snake);
        } else if (data(newHead.row, newHead.col) == Cell::rabbit) {
            head = newHead;

            snake.push(head);

            data(head.row, head.col) = Cell::snake;

            boxes(head.row, head.col)->setCell(Cell::snake);
            addRabbit();
        }
    }
}

void Snake::Map::createWall()
{
    for (size_type row{}; row < data.size1(); ++row) {
        data(row, 0) = Cell::wall;
        data(row, data.size2() - 1) = Cell::wall;
        boxes(row, 0)->setCell(Cell::wall);
        boxes(row, data.size2() - 1)->setCell(Cell::wall);
    }

    for (size_type col{}; col < data.size2(); ++col) {
        data(0, col) = Cell::wall;
        data(data.size1() - 1, col) = Cell::wall;
        boxes(0, col)->setCell(Cell::wall);
        boxes(data.size1() - 1, col)->setCell(Cell::wall);
    }
}

void Snake::Map::addRabbit()
{
    int loop{200};

    while (loop-- > 0) {
        int row = ClarensMath::randomInRange(0, data.size1()-1);
        int col = ClarensMath::randomInRange(0, data.size2()-1);

        if (data(row, col) == Cell::empty) {
            data(row, col) = Cell::rabbit;
            boxes(row, col)->setCell(data(row, col));
            break;
        }
    }
}

void Snake::Map::addSnake()
{
    int loop{200};

    while (loop-- > 0) {
        int row = ClarensMath::randomInRange(0, data.size1()-1);
        int col = ClarensMath::randomInRange(0, data.size2()-1);

        if (data(row, col) == Cell::empty &&
                data(row, col + 1) == Cell::empty &&
                data(row, col + 2) == Cell::empty) {
            data(row, col) = Cell::snake;
            boxes(row, col)->setCell(Cell::snake);
            data(row, col+1) = Cell::snake;
            boxes(row, col+1)->setCell(Cell::snake);
            data(row, col+2) = Cell::snake;
            boxes(row, col+2)->setCell(Cell::snake);

            while(!snake.empty())
                snake.pop();

            snake.push(Point{row, col});
            snake.push(Point{row, col+1});
            snake.push(Point{row, col+2});
            head = Point{row, col+2};
            break;
        }
    }
}

bool Snake::Map::inRange(Point p)
{
    return p.row >= 0 && p.row < static_cast<int>(data.size1()) &&
           p.col >= 0 && p.col < static_cast<int>(data.size2());
}
