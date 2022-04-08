#pragma once
#include <QObject>
#include <QGraphicsScene>
#include "InterfacePieces.h"

class InterfaceEchiquier : public QGraphicsScene
{
public:
	InterfaceEchiquier(QObject* parent = nullptr);
	~InterfaceEchiquier() = default;

	QList<InterfacePiece*> listePieces;
};