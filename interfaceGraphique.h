#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <QPushButton>
#include <QLayout>

#include "interfaceEchiquier.h"

namespace Affichage
{
	class InterfaceGraphique : public QMainWindow
	{
		Q_OBJECT

	public:
		InterfaceGraphique(QWidget* parent = nullptr);
		~InterfaceGraphique();

	private:
		void afficherEchiquier(QHBoxLayout*& layoutPrincipal);

		QGraphicsView* vue;
		InterfaceEchiquier* echiquier;

		QList<QPushButton*> boutonsDeSelection_;
	};
}
