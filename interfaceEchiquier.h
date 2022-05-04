#pragma once
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "interfacePiece.h"

namespace Affichage
{
	class InterfaceEchiquier : public QGraphicsScene
	{
		Q_OBJECT

	public:
		InterfaceEchiquier(QObject* parent = nullptr);

	public slots:
		void actualiserPosition(std::pair<int, int>& position);

	private:
		void creerGrille();

		QList<InterfacePiece*> listePieces;
		QList<QGraphicsRectItem*> listeCases;
	};
}
