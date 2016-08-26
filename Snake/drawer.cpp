#include "drawer.h"

GameSnake::Drawer::Drawer(QWidget *panel, QWidget *parent) :
    QWidget(parent),
    boxes(panel->height() / cellSize, panel->width() / cellSize)
{
    using size_type = matrix<Box*>::size_type;

    for (size_type row{}; row < boxes.size1(); ++row)
        for (size_type col{}; col < boxes.size2(); ++col) {
            boxes(row, col) = new Box{Cell::empty, panel};
            boxes(row, col)->resize(cellSize, cellSize);
            boxes(row, col)->move(col * cellSize, row * cellSize);
            boxes(row, col)->show();
        }
}

void GameSnake::Drawer::setCell(int row, int col, GameSnake::Cell cell)
{
    boxes(row, col)->setCell(cell);
}
