#pragma once
#include <QObject>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "echiquier.h"
#include "pieces.h"

class InterfacePiece : public QObject, public QGraphicsRectItem
{
	Q_OBJECT

public:
	InterfacePiece(pair<int, int> position);

protected:
	void mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) override;

signals:
	void changementPosition(pair<int, int>& position);

private:
	pair<int, int> positionActuelle_;
	friend class InterfaceEchiquier;
};

class InterfaceEchiquier : public QGraphicsScene
{
	Q_OBJECT

public:
	InterfaceEchiquier(QObject* parent = nullptr);
	~InterfaceEchiquier() = default;

public slots:
	void actualiserPosition(pair<int, int>& position);

private:
	QList<InterfacePiece*> listePieces;
};

class InterfaceGraphique : public QMainWindow
{
	Q_OBJECT

public:
	InterfaceGraphique(QWidget* parent = nullptr);
	~InterfaceGraphique();

private:
	QGraphicsView* vue;
	InterfaceEchiquier* echiquier;
};
