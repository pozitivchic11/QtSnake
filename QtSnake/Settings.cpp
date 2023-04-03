#include "Settings.h"

Settings::Settings(QWidget *parent) : QDialog(parent)
{
	ui.setupUi(this);

	ui.snakeColorBox->addItem("Green");
	ui.snakeColorBox->addItem("Red");
	ui.snakeColorBox->addItem("Yellow");
	ui.snakeColorBox->addItem("Black");

	connect(ui.backToMenu, &QPushButton::clicked, this, &Settings::backToMenu);
}

Settings::~Settings() {}

void Settings::backToMenu()
{
	this->close();
	emit goToSettings();
}

QString& Settings::getSnakeColor() 
{ 
	color = ui.snakeColorBox->currentText();

	return color; 
}

bool Settings::getHeadState()
{
	if (ui.checkTheme->isChecked())
	{
		return true;
	}
	else { return false; }
}