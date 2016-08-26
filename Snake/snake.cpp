#include "snake.h"

GameSnake::Snake::Snake(Map &gameMap) :
    body{gameMap.addSnake()},
    head(body.back()),
    map(gameMap)
{
}

void GameSnake::Snake::move()
{
    Coord newHead {head.row+stepRow, head.col+stepCol};
    if (map.inRange(newHead)) {

        if (map.data(newHead.row, newHead.col) == Cell::wall ||
            map.data(newHead.row, newHead.col) == Cell::snake )
            return;

        if (map.data(newHead.row, newHead.col) == Cell::empty) {
            head = newHead;

            Coord tail = body.front();
            body.pop();
            body.push(head);

            map.data(tail.row, tail.col) = Cell::empty;
            map.data(head.row, head.col) = Cell::snake;

            map.showCell(tail.row, tail.col, Cell::empty);
            map.showCell(head.row, head.col, Cell::snake);
        } else if (map.data(newHead.row, newHead.col) == Cell::rabbit) {
            head = newHead;

            body.push(head);

            map.data(head.row, head.col) = Cell::snake;
            map.showCell(head.row, head.col, Cell::snake);

            map.addRabbit();
        }
    }
}

void GameSnake::Snake::turn(GameSnake::Direction d)
{
    switch(d) {
    case Direction::up:     stepRow = -1; stepCol =  0; break;
    case Direction::down:   stepRow =  1; stepCol =  0; break;
    case Direction::left:   stepRow =  0; stepCol = -1; break;
    case Direction::right:  stepRow =  0; stepCol =  1; break;
    }
}
