#pragma once
#include "ouvertureDuCrabe.h"
#include "echiquier.h"
#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"
#include "cavalier.h"
#include "pion.h"

namespace LogiqueJeu
{
	OuvertureDuCrabe OuvertureDuCrabe::instance_ = OuvertureDuCrabe();

	OuvertureDuCrabe::OuvertureDuCrabe() : StrategiePlacementPieces(OuvertureDuCrabe::nomStrategie_) {
		description_ = "Les blancs controlent les extremites, mais les noirs controlent le centre. Les blancs tiendront-ils la position?";
	}

	//tour au noirs
	void OuvertureDuCrabe::placerPieces()
	{
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();

		/*---------------------------------------Pieces noirs-------------------------------------*/
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir)), { 7, 8 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { 4, 8 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir)), { 1, 8 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir)), { 5, 8 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 4, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Noir)), { 5, 6 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur::Noir)), { 2, 8 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur::Noir)), { 4, 7 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 1, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 2, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 3, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 4, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 5, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 6, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 7, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 8, 7 });

		/*---------------------------------------Pieces blanches-------------------------------------*/
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 5, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc)), { 4, 1 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 1, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 8, 1 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 3, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur::Blanc)), { 5, 2 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur::Blanc)), { 4, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur::Blanc)), { 7, 1 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 1, 4 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 2, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 3, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 4, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 5, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 6, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 7, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 8, 4 });
	}
}