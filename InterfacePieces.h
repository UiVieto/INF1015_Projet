#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class InterfacePiece : public QGraphicsRectItem
{
public:
	InterfacePiece();

protected:
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) override;
};