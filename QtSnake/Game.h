#pragma once

#include <QtWidgets/QWidget>
#include <map>
#include <QKeyEvent>
#include <qmessagebox.h>
#include <qpoint.h>
#include <QRandomGenerator>
#include <random>

#include "ui_gameWindow.h"

enum Directions
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

class Game : public QWidget
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

protected:
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent*) override;
    void paintEvent(QPaintEvent*) override;

signals:
    void backToMain();

private:
    Ui::GameClass ui;

    static const int DOT_WIDTH = 20;
    static const int DOT_HEIGHT = 20;
    static const int FIELD_WIDTH = 20;
    static const int FIELD_HEIGHT = 20;
    static const int DELAY = 150;

    int timerId;
    int backToMenu;

    bool game_state;

    std::vector<QPoint> snakePoints;
    QPoint applePoint;

    Directions dir;

    void initGame();
    void doDrawing();
    void locateApple();
    void move();
    void checkBorders();
    void gameOver();
    void checkApple();
};