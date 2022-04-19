#pragma once
#include <QObject>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "echiquier.h"

class InterfacePiece : public QGraphicsRectItem
{
public:
	InterfacePiece(const shared_ptr<Piece>& piece, Echiquier*& echiquier, pair<int, int> position);

protected:
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) override;

private:
	Echiquier* pointeurEchiquier_;
	pair<int, int> positionActuelle_;
};

class InterfaceEchiquier : public QGraphicsScene
{
public:
	InterfaceEchiquier(Echiquier*& echiquier, QObject* parent = nullptr);
	~InterfaceEchiquier() = default;

	QList<InterfacePiece*> listePieces;

private:
	const Echiquier* pointeurEchiquier_;
};

class InterfaceGraphique : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceGraphique(Echiquier* echiquier, QWidget* parent = nullptr);
	~InterfaceGraphique();

private:
	QGraphicsView* vue;
	InterfaceEchiquier* echiquier;
};
