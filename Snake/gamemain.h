#ifndef SNAKE_GAMEMAIN_H
#define SNAKE_GAMEMAIN_H

#include <QWidget>
#include <memory>
#include "gamemap.h"
#include "drawer.h"
#include "snake.h"

namespace GameSnake {

    class GameMain : public QWidget {
    public:
        explicit GameMain(QWidget* panel, QWidget *parent = 0);
        void moveSnake();
        void turnLeft();
        void turnRight();
        void turnUp();
        void turnDown();

    private:
        Map *map;
        Drawer *drawer;
        std::unique_ptr<Snake> snake;
    };

}


#endif // SNAKE_GAMEMAIN_H
