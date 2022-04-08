#pragma once
#include <QMainWindow>
#include <QpushButton>
#include <QVBoxLayout>

#include "echiquier.h"

class InterfaceGraphique : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceGraphique(QWidget* parent = nullptr);
	~InterfaceGraphique();

private slots:
	void direBonjour();

private:
	QGraphicsView* vue;
	InterfaceEchiquier* echiquier;
};
