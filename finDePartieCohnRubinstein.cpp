#pragma once
#include "finDePartieCohnRubinstein.h"
#include "echiquier.h"
#include "roi.h"
#include "tour.h"
#include "pion.h"

namespace LogiqueJeu 
{
	FinDePartieCohnRubinstein FinDePartieCohnRubinstein::instance_ = FinDePartieCohnRubinstein();

	FinDePartieCohnRubinstein::FinDePartieCohnRubinstein() : StrategiePlacementPieces(FinDePartieCohnRubinstein::nomStrategie_) {
		description_ = "Fin de partie du match entre Erich Cohn et Akiba Rubinstein lors du Tournoi de St. Petersburg le 28 fevrier 1909.";
	}

	//Tour 24, tour au noir
	void FinDePartieCohnRubinstein::placerPieces()
	{
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir)), { 5, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir)), { 5, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 1, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 2, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 5, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 6, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 7, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 8, 7 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 4, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 3, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 1, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 2, 4 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 5, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 6, 3 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 6, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 8, 2 });
	}
}