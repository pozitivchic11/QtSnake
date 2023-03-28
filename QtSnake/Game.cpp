#include "Game.h"

#include <QPainter>
#include <random>

Game::Game(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);

    this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);

    initGame();
}

Game::~Game() {}

void Game::timerEvent(QTimerEvent* event)
{
    qDebug() << 1;
}

void Game::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        break;
    }
}

void Game::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    //doDrawing();
}

void Game::doDrawing()
{
    QPainter painter(this);

    if (game_state)
    {

    }
    else 
    {
        //gaveOver();
    }
}

void Game::locateApple()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dist(0, DOT_WIDTH);

    applePoint.first = dist(gen);
}

void Game::initGame()
{
    game_state = true;
    dir = RIGHT;

    for (int i = 0; i < 3; i++)
    {
        points.insert(std::pair<int, int>((3 - i), 0));
    }

    locateApple();

    timerId = startTimer(DELAY);
}