#include "InterfacePieces.h"
#include <Qpen>

InterfacePiece::InterfacePiece() {
	setRect(0, 0, 50, 50);
	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::red));

	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);
}