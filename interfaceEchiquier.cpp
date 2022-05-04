
#include "interfaceEchiquier.h"
#include "echiquier.h"

namespace Affichage 
{
	InterfaceEchiquier::InterfaceEchiquier(QObject* parent) : QGraphicsScene(parent) {
		creerGrille();

		for (auto& element : LogiqueJeu::Echiquier::echiquier()) {
			if (element.second.get() != nullptr)
			{
				InterfacePiece* interfacePiece = new InterfacePiece(element.first);
				interfacePiece->setPos((element.first.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - element.first.second) * LONGUEUR_CASE);
				listePieces.append(interfacePiece);
				addItem(interfacePiece);

				QObject::connect(interfacePiece, &InterfacePiece::changementPosition, this, &InterfaceEchiquier::actualiserPosition);
			}
		}
	}
	
	void InterfaceEchiquier::actualiserPosition(pair<int, int>& position) {
		for (InterfacePiece* piece : listePieces) {
			if (piece->positionActuelle_ == position) {
				delete piece;
				break;
			}
		}
	}

	void InterfaceEchiquier::creerGrille() 
	{
		Couleur couleurCase = Couleur::Blanc;

		for (int x = 1; x <= NOMBRE_CASES; x++) 
		{
			(couleurCase == Couleur::Blanc) ? couleurCase = Couleur::Noir : couleurCase = Couleur::Blanc;
			for (int y = 1; y <= NOMBRE_CASES; y++) 
			{
				QGraphicsRectItem* caseEchiquier = new QGraphicsRectItem;
				caseEchiquier->setRect(0, 0, LONGUEUR_CASE, LONGUEUR_CASE);
				caseEchiquier->setPen(QPen(Qt::black));

				if (couleurCase == Couleur::Blanc) {
					caseEchiquier->setBrush(QBrush(Qt::gray));
					couleurCase = Couleur::Noir;
				}

				else {
					caseEchiquier->setBrush(QBrush(Qt::darkGreen)); 
					couleurCase = Couleur::Blanc;
				}
					
				caseEchiquier->setPos((x - 1) * LONGUEUR_CASE, (NOMBRE_CASES - y) * LONGUEUR_CASE);
				listeCases.append(caseEchiquier);
				addItem(caseEchiquier);
			}
		}
	}

}
