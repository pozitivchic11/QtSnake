#pragma once

#include <QDialog>
#include "ui_settingsWindow.h"

class Settings : public QDialog
{
	Q_OBJECT

public:
	Settings(QWidget *parent = nullptr);
	~Settings();

	QString& getSnakeColor();
	bool getHeadState();

signals:
	void goToSettings();

private slots:
	void backToMenu();

private:
	Ui::SettingsClass ui;

	QString color;
};
