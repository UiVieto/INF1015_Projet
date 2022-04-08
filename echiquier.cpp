#include "echiquier.h"

InterfaceEchiquier::InterfaceEchiquier(QObject* parent) : QGraphicsScene(parent)
{
	for (int i = 0; i < 10; i++) {
		addLine(0, i * 50, 450, i * 50, QPen(Qt::gray));
		addLine(i * 50, 0, i * 50, 450), QPen(Qt::gray);
	}

	for (int i = 0; i < 4; i++) {
		InterfacePiece* piece = new InterfacePiece();
		piece->setPos(i * 50, 0);
		listePieces.append(piece);
		addItem(piece);
	}
}