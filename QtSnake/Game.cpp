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
    Q_UNUSED(event);

    if (game_state)
    {
        checkApple();
        move();
        checkBorders();
    }

    this->repaint();
}

void Game::keyPressEvent(QKeyEvent* event)
{
    int key = event->key();
    
    if ((key == Qt::Key_Left) && (key != Qt::Key_Right)) { dir = LEFT; }
    if ((key == Qt::Key_Right) && (key != Qt::Key_Left)) { dir = RIGHT; }
    if ((key == Qt::Key_Up) && (key != Qt::Key_Down)) { dir = UP; }
    if ((key == Qt::Key_Down) && (key != Qt::Key_Up)) { dir = DOWN; }
}

void Game::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    doDrawing();
}

void Game::doDrawing()
{
    QPainter painter(this);

    if (game_state)
    {
        painter.setBrush(Qt::red);
        painter.drawEllipse(applePoint.x() * DOT_WIDTH, applePoint.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
        
        for (int i = 0; i < snakePoints.size(); ++i)
        {
            if(i != 0)
            {
                painter.setBrush(color);
                
                painter.drawEllipse(snakePoints[i].x() * DOT_WIDTH, snakePoints[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
            else
            {
                if (!checkHeadColor) {
                    painter.setBrush(Qt::white);
                }
                else { painter.setBrush(color); }

                painter.drawEllipse(snakePoints[i].x() * DOT_WIDTH, snakePoints[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
        }
    }
    else 
    {
        gameOver();
    }
}

void Game::locateApple()
{
    applePoint.rx() = rand() % DOT_WIDTH;
    applePoint.ry() = rand() % DOT_HEIGHT;
}

void Game::move()
{
    for (int i = snakePoints.size() - 1; i > 0; --i)
    {
        snakePoints[i] = snakePoints[i - 1];
    }

    switch (dir)
    {
    case LEFT:
        snakePoints[0].rx() -= 1;
        break;
    case RIGHT:
        snakePoints[0].rx() += 1;
        break;
    case UP:
        snakePoints[0].ry() -= 1;
        break;
    case DOWN:
        snakePoints[0].ry() += 1;
        break;
    }
}

void Game::checkBorders()
{
    if (snakePoints.size() > 4)
    {
        for (int i = 1; i < snakePoints.size(); ++i)
        {
            if (snakePoints[0] == snakePoints[i])
            {
                game_state = false;
            }
        }
    }

    if (snakePoints[0].x() >= FIELD_WIDTH) { game_state = false; }
    if (snakePoints[0].x() < 0) { game_state = false; }
    if (snakePoints[0].y() >= FIELD_HEIGHT) { game_state = false; }
    if (snakePoints[0].y() < 0) { game_state = false; }

    if (!game_state) { killTimer(timerId); }
}

void Game::gameOver()
{
    QMessageBox msg;
    
    backToMenu = QMessageBox::question(this, "BackToMenu", "Do you wanna back to main menu?", QMessageBox::Yes | QMessageBox::No);
    
    switch (backToMenu)
    {
    case QMessageBox::Yes:
        this->close();
        emit goToGame();

        break;
    case QMessageBox::No:
        break;
    }

    initGame();
}

void Game::checkApple()
{
    if (applePoint == snakePoints[0])
    {
        snakePoints.push_back(QPoint(0, 0));
        locateApple();
    }
}

void Game::initGame()
{
    game_state = true;
    
    dir = STAY;

    snakePoints.resize(3);

    for (int i = 0; i < snakePoints.size(); i++)
    {
        snakePoints[i].rx() = snakePoints.size() - i - 1;
        snakePoints[i].ry() = 0;
    }

    locateApple();

    timerId = startTimer(DELAY);
}

void Game::setSnakeColor(const QString& color)
{
    if (color == "Green")
    {
        this->color = Qt::green;
    }
    else if (color == "Red")
    {
        this->color = Qt::red;
    }
    else if (color == "Yellow")
    {
        this->color = Qt::yellow;
    }
    else if (color == "Black")
    {
        this->color = Qt::black;
    }
}

void Game::setHeadColor(const bool& boolean)
{
    checkHeadColor = boolean;
}