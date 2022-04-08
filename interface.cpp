#pragma once

#include "structureInterface.h"
#include <QDebug>

InterfaceGraphique::InterfaceGraphique(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("Jeu d'echec (prototype)");
	boutonDebut = new QPushButton(this);
}

InterfaceGraphique::~InterfaceGraphique() noexcept {
	qDebug() << "Destruction de l'interface graphique" << Qt::endl;
}
