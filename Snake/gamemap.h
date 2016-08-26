#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include <QLabel>
#include <boost/numeric/ublas/matrix.hpp>
#include "cell.h"
#include "box.h"
#include <queue>

using boost::numeric::ublas::matrix;

namespace Snake {

    struct Point {
        int row;
        int col;
    };

    inline bool operator == (Point p1, Point p2)
    {
        return p1.row == p2.row && p1.col == p2.col;
    }

    class Map : public QWidget {
    public:
        explicit Map(QWidget *parent);
        void turnLeft();
        void turnRight();
        void turnUp();
        void turnDown();
        void moveSnake();

    private:
        using size_type = matrix<Cell>::size_type;

        void createWall();
        void addRabbit();
        void addSnake();
        bool inRange(Point point);

        matrix<Cell> data;
        matrix<Box*> boxes;
        std::queue<Point> snake;
        Point head;
        int srow;
        int scol;
    };

}

#endif // SNAKE_MAP_H
