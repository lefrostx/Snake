#ifndef SNAKE_COORD_H
#define SNAKE_COORD_H

namespace GameSnake {

    struct Coord {
        int row;
        int col;
    };

    inline bool operator == (Coord p1, Coord p2)
    {
        return p1.row == p2.row && p1.col == p2.col;
    }

}

#endif // SNAKE_COORD_H
