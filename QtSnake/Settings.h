#pragma once

#include <QDialog>
#include "ui_settingsWindow.h"

class Settings : public QDialog
{
	Q_OBJECT

public:
	Settings(QWidget *parent = nullptr);
	~Settings();

	QString getSnakeColor();

private slots:
	void backToMenu();

signals:
	void goToSettings();

private:
	Ui::SettingsClass ui;

	QString color;
};
