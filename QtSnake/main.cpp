#include "Game.h"
#include "MainWindow.h"

#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    QFile mainWindowStyle("mainWindowStyle.css");

    try 
    {
        if (mainWindowStyle.open(QFile::ReadOnly))
        {
            QTextStream textStream(&mainWindowStyle);
            QString styleMainSheet = textStream.readAll();

            mainWindowStyle.close();

            app.setStyleSheet(styleMainSheet);
        }
        else
        {
            throw std::exception("File wasn`t oppened");
        }
    }
    catch (const std::exception ex)
    {
        QMessageBox::critical(&mainWindow, "FileOpenError", ex.what());
    }
    
    
    mainWindow.setWindowTitle("MainWindow");
    mainWindow.show();

    return app.exec();
}
