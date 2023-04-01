#pragma once

#include <QWidget>
#include <qmessagebox.h>
#include <qmainwindow.h>

#include "ui_mainWindow.h"
#include "Game.h"
#include "Settings.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QMainWindow*parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindowClass ui;

public:
	Game* game;
	Settings* settings;

private slots:
	void startButton();
	void settingsButton();
	void exitButton();
};
