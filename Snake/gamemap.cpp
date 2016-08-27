#include "gamemap.h"
#include "mathematic.h"

GameSnake::Map::Map(int rows, int cols, std::function<void (int, int, GameSnake::Cell)> showFunc) :
    showCell{showFunc},
    data(rows, cols, Cell::empty)
{
    createWall();

    for (int i{}; i < 5; ++i)
        addRabbit();
}

void GameSnake::Map::createWall()
{
    for (size_type row{}; row < data.size1(); ++row) {
        data(row, 0) = Cell::wall;
        data(row, data.size2() - 1) = Cell::wall;

        showCell(row, 0, Cell::wall);
        showCell(row, data.size2() - 1, Cell::wall);
    }

    for (size_type col{}; col < data.size2(); ++col) {
        data(0, col) = Cell::wall;
        data(data.size1() - 1, col) = Cell::wall;

        showCell(0, col, Cell::wall);
        showCell(data.size1() - 1, col, Cell::wall);
    }
}

void GameSnake::Map::addRabbit()
{
    int loop{200};

    while (loop-- > 0) {
        int row = ClarensMath::randomInRange(0, data.size1()-1);
        int col = ClarensMath::randomInRange(0, data.size2()-1);

        if (data(row, col) == Cell::empty) {
            data(row, col) = Cell::rabbit;

            showCell(row, col, Cell::rabbit);
            break;
        }
    }
}

std::queue<GameSnake::Coord> GameSnake::Map::addSnake()
{
    std::queue<Coord> snake;

    int loop{200};

    while (loop-- > 0) {
        int row = ClarensMath::randomInRange(0, data.size1()-1);
        int col = ClarensMath::randomInRange(0, data.size2()-1);

        if (data(row, col) == Cell::empty &&
                data(row, col + 1) == Cell::empty &&
                data(row, col + 2) == Cell::empty) {
            data(row, col) = Cell::snake;
            showCell(row, col, Cell::snake);
            data(row, col+1) = Cell::snake;
            showCell(row, col+1, Cell::snake);
            data(row, col+2) = Cell::snake;
            showCell(row, col+2, Cell::head);

            snake.push(Coord{row, col});
            snake.push(Coord{row, col+1});
            snake.push(Coord{row, col+2});
            break;
        }
    }

    return snake;
}

bool GameSnake::Map::inRange(Coord p)
{
    return p.row >= 0 && p.row < static_cast<int>(data.size1()) &&
           p.col >= 0 && p.col < static_cast<int>(data.size2());
}
