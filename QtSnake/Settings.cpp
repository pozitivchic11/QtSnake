#include "Settings.h"

Settings::Settings(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.backToMenu, &QPushButton::clicked, this, &Settings::backToMenu);
}

Settings::~Settings() {}


void Settings::backToMenu()
{
	this->close();
	emit goToSettings();
}