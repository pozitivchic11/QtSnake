#include "Game.h"
#include "MainWindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    
    mainWindow.setWindowTitle("MainWindow");
    mainWindow.show();

    return app.exec();
}
