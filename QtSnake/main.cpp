#include "Game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game snakeGame;
    
    snakeGame.setWindowTitle("Snake");
    snakeGame.show();

    return app.exec();
}
