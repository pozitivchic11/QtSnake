#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include <qmainwindow.h>

#include "ui_mainWindow.h"
#include "Game.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QMainWindow*parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

	Game* game;

private slots:
	void startButton();
	void exitButton();
};
