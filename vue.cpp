#include "vue.h"
#include <Qpen>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

constexpr int LONGUEUR_CASE = 60;
constexpr int NOMBRE_CASES = 8;

Affichage::InterfaceEchiquier::InterfaceEchiquier(QObject* parent) : QGraphicsScene(parent) {
	for (int i = 0; i <= NOMBRE_CASES; i++) {
		addLine(0, i * LONGUEUR_CASE, NOMBRE_CASES * LONGUEUR_CASE, i * LONGUEUR_CASE, QPen(Qt::gray));
		addLine(i * LONGUEUR_CASE, 0, i * LONGUEUR_CASE, NOMBRE_CASES * LONGUEUR_CASE), QPen(Qt::gray);
	}

	for (auto& element : Echiquier::echiquier().grille_) 
	{
		if (element.second.get() != nullptr) 
		{
			InterfacePiece* interfacePiece = new InterfacePiece(element.first);
			interfacePiece->setPos((element.first.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - element.first.second) * LONGUEUR_CASE);
			listePieces.append(interfacePiece);
			addItem(interfacePiece);

			QObject::connect(interfacePiece, SIGNAL(changementPosition(pair<int, int>&)), this, SLOT(actualiserPosition(pair<int, int>&)));
		}
	}
}

Affichage::InterfaceGraphique::InterfaceGraphique(QWidget* parent) : QMainWindow(parent)
{
	setWindowTitle("Jeu d'echec (prototype)");

	vue = new QGraphicsView(this);
	echiquier = new InterfaceEchiquier(vue);

	vue->setScene(echiquier);

	vue->setAlignment(Qt::AlignLeft | Qt::AlignTop);

	vue->centerOn(0, 0);

	vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	setCentralWidget(vue);
}

Affichage::InterfaceGraphique::~InterfaceGraphique() {
	qDebug() << "Destruction de l'interface graphique" << Qt::endl;
}

//TODO ajouter des images différents pour les pieces
Affichage::InterfacePiece::InterfacePiece(pair<int, int> position) {
	setRect(0, 0, LONGUEUR_CASE, LONGUEUR_CASE);
	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::red));

	setFlag(QGraphicsItem::ItemIsMovable);
	setFlag(QGraphicsItem::ItemIsSelectable);

	positionActuelle_ = position;
}

void Affichage::InterfacePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) {
	int x = (pos().x() + LONGUEUR_CASE / 2) - ((int(pos().x()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
	int y = (pos().y() + LONGUEUR_CASE / 2) - ((int(pos().y()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
	pair<int, int> nouvellePosition = { x / LONGUEUR_CASE + 1, 8 - y / LONGUEUR_CASE };

	Echiquier::echiquier().deplacerPiece(positionActuelle_, nouvellePosition);

	if (Echiquier::echiquier().prendrePiece(positionActuelle_).get() == nullptr) {
		emit changementPosition(nouvellePosition);
		setPos(x, y);
		positionActuelle_ = nouvellePosition;
	}
		
	else {
		setPos((positionActuelle_.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - positionActuelle_.second) * LONGUEUR_CASE);
	}

	QGraphicsRectItem::mouseReleaseEvent(evenement);
}

void Affichage::InterfaceEchiquier::actualiserPosition(pair<int, int>& nouvellePosition) {
	for (InterfacePiece* piece : listePieces) {
		if (piece->positionActuelle_ == nouvellePosition) {
			delete piece;
			break;
		}
	}
}

