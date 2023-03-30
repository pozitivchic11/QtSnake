#pragma once

#include <QDialog>
#include "ui_settingsWindow.h"

class Settings : public QDialog
{
	Q_OBJECT

public:
	Settings(QWidget *parent = nullptr);
	~Settings();

signals:
	void goToSettings();

private:
	Ui::SettingsClass ui;

	void backToMenu();
};
