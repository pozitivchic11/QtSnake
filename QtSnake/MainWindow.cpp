#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow* parent) : QWidget(parent)
{
	ui.setupUi(this);

	game = new Game();
	settings = new Settings();

	connect(game, &Game::goToGame, this, &Game::show);
	connect(settings, &Settings::goToSettings, this, &Settings::show);

	connect(ui.startButton, &QPushButton::clicked, this, &MainWindow::startButton);
	connect(ui.settingsButton, &QPushButton::clicked, this, &MainWindow::settingsButton);
	connect(ui.exitButton, &QPushButton::clicked, this, &MainWindow::exitButton);
}

MainWindow::~MainWindow() {}

void MainWindow::startButton()
{
	this->close();
	game->show();
}

void MainWindow::settingsButton()
{
	this->close();
	settings->show();
}

void MainWindow::exitButton()
{
	int result = QMessageBox::question(this, "Exit", "Are you sure you wanna quit?", QMessageBox::Yes | QMessageBox::No);

	switch (result)
	{
	case QMessageBox::Yes:
		this->close();
		break;
	case QMessageBox::No:
		break;
	}
}