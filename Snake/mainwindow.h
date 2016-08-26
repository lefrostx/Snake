#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamemain.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void moveSnake();

protected:
    virtual void keyPressEvent(QKeyEvent* pe) override;

private:
    Ui::MainWindow *ui;

    GameSnake::GameMain *game;
};

#endif // MAINWINDOW_H
