#ifndef SNAKE_DRAWER_H
#define SNAKE_DRAWER_H

#include <QWidget>
#include <boost/numeric/ublas/matrix.hpp>
#include "cell.h"
#include "box.h"

using boost::numeric::ublas::matrix;

namespace GameSnake {

    constexpr int cellSize = 30;

    class Drawer : public QWidget {

    public:
        explicit Drawer(QWidget* panel, QWidget *parent = 0);
        void setCell(int row, int col, GameSnake::Cell cell);

    private:
        matrix<Box*> boxes;
    };

}

#endif // SNAKE_DRAWER_H
