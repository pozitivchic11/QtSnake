#include "MainWindow.h"

MainWindow::MainWindow(QMainWindow* parent) : QWidget(parent)
{
	ui.setupUi(this);

	game = new Game();

	connect(game, &Game::backToMain, this, &Game::show);

	connect(ui.startButton, &QPushButton::clicked, this, &MainWindow::startButton);
	connect(ui.exitButton, &QPushButton::clicked, this, &MainWindow::exitButton);
}

MainWindow::~MainWindow() {}

void MainWindow::startButton()
{
	this->close();
	game->show();
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