#include "InterfacePieces.h"
#include <Qpen>
#include <QGraphicsScene>

InterfacePiece::InterfacePiece() {
	setRect(0, 0, 50, 50);
	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::red));

	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);
}

void InterfacePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) {
	int x = (pos().x() + 25) - ((int(pos().x()) + 25) % 50);
	int y = (pos().y() + 25) - ((int(pos().y()) + 25) % 50);
		
	setPos(x, y);

	QGraphicsRectItem::mouseReleaseEvent(evenement);
}