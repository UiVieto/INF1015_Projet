#pragma once
#include "finDePartieRhanmouniNguyen.h"
#include "echiquier.h"
#include "roi.h"
#include "fou.h"
#include "cavalier.h"
#include "pion.h"

namespace LogiqueJeu
{
	FinDePartieRhanmouniNguyen FinDePartieRhanmouniNguyen::instance_ = FinDePartieRhanmouniNguyen();

	FinDePartieRhanmouniNguyen::FinDePartieRhanmouniNguyen() : StrategiePlacementPieces(FinDePartieRhanmouniNguyen::nomStrategie_) {
		description_ = "Fin de partie de la premiere partie entre Reda Rhanmouni et Huy Viet Nguyen lors du PolyTour. Trouverez-vous le mouvement decisif?";
	}

	//Tour 34, tour au blancs
	void FinDePartieRhanmouniNguyen::placerPieces() {
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur(Couleur::Noir))), { 5, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur(Couleur::Noir))), { 5, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur(Couleur::Noir))), { 4, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Noir))), { 2, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Noir))), { 4, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Noir))), { 5, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Noir))), { 6, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Noir))), { 8, 7 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur(Couleur::Blanc))), { 7, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Fou>(LogiqueJeu::Fou(Couleur(Couleur::Blanc))), { 5, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Cavalier>(LogiqueJeu::Cavalier(Couleur(Couleur::Blanc))), { 6, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Blanc))), { 6, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Blanc))), { 7, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Blanc))), { 8, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Blanc))), { 1, 5 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur(Couleur::Blanc))), { 2, 5 });
	}
}