#ifndef SNAKE_BOX_H
#define SNAKE_BOX_H

#include <QLabel>
#include "cell.h"

namespace GameSnake {

    class Box : public QLabel {
    public:
        explicit Box(Cell cell, QWidget *parent = 0);
        void setCell(Cell cell);
    };

}

#endif // SNAKE_BOX_H
