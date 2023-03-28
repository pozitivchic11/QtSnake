#include "Game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);

    resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
}

Game::~Game()
{}
