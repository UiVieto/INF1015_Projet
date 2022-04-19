#include "vue.h"
#include <Qpen>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

InterfaceEchiquier::InterfaceEchiquier(Echiquier*& echiquier, QObject* parent) : QGraphicsScene(parent) {
	pointeurEchiquier_ = echiquier;

	for (int i = 0; i <= 8; i++) {
		addLine(0, i * 50, 400, i * 50, QPen(Qt::gray));
		addLine(i * 50, 0, i * 50, 400), QPen(Qt::gray);
	}

	for (auto& element : pointeurEchiquier_->grille_) {
		if (element.second.get() != nullptr) {
			InterfacePiece* interfacePiece = new InterfacePiece(element.second, echiquier, element.first);
			interfacePiece->setPos((element.first.first - 1) * 50, (8 - element.first.second) * 50);
			listePieces.append(interfacePiece);
			addItem(interfacePiece);
		}
	}
}

InterfaceGraphique::InterfaceGraphique(Echiquier* pointeurEchiquier, QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("Jeu d'echec (prototype)");

	vue = new QGraphicsView(this);
	echiquier = new InterfaceEchiquier(pointeurEchiquier, vue);

	vue->setScene(echiquier);

	vue->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	vue->centerOn(0, 0);

	vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	setCentralWidget(vue);
}

InterfaceGraphique::~InterfaceGraphique() {
	qDebug() << "Destruction de l'interface graphique" << Qt::endl;
}

//TODO ajouter des images différents pour les pieces
InterfacePiece::InterfacePiece(const shared_ptr<Piece>& piece, Echiquier*& echiquier, pair<int, int> position) {
	setRect(0, 0, 50, 50);
	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::red));

	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

	pointeurEchiquier_ = echiquier;
	positionActuelle_ = position;
}

void InterfacePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) {
	int x = (pos().x() + 25) - ((int(pos().x()) + 25) % 50);
	int y = (pos().y() + 25) - ((int(pos().y()) + 25) % 50);
	pair<int, int> nouvellePosition = { x / 50 + 1, 8 - y / 50 };

	pointeurEchiquier_->deplacerPiece(positionActuelle_, nouvellePosition);

	if (pointeurEchiquier_->prendrePiece(positionActuelle_).get() == nullptr) {
		setPos(x, y);
		positionActuelle_ = nouvellePosition;
	}
		
	else {
		setPos((positionActuelle_.first - 1) * 50, (8 - positionActuelle_.second) * 50);
	}

	QGraphicsRectItem::mouseReleaseEvent(evenement);
}
