#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <queue>
#include "coord.h"
#include "gamemap.h"

namespace GameSnake {

    enum class Direction {
        up,
        down,
        left,
        right
    };

    class Snake {
    public:
        explicit Snake(Map &gameMap);
        void move();
        void turn(Direction d);

    private:
        std::queue<Coord> body;
        Coord head;
        Map &map;
        int stepRow{0};
        int stepCol{1};
    };

}

#endif // SNAKE_SNAKE_H
