#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include <boost/numeric/ublas/matrix.hpp>
#include <queue>
#include <functional>
#include "cell.h"
#include "coord.h"

using boost::numeric::ublas::matrix;

namespace GameSnake {

    class Map {
        friend class Snake;

    public:
        explicit Map(int rows, int cols, std::function<void(int, int, Cell)> showFunc);

    private:
        using size_type = matrix<Cell>::size_type;

        std::function<void(int, int, Cell)> showCell;

        void createWall();
        void addRabbit();
        std::queue<Coord> addSnake();
        bool inRange(Coord point);

        matrix<Cell> data;
    };

}

#endif // SNAKE_MAP_H
