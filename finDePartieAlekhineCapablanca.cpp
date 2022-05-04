#pragma once
#include "finDePartieAlekhineCapablanca.h"
#include "echiquier.h"
#include "roi.h"
#include "tour.h"
#include "reine.h"
#include "pion.h"

namespace LogiqueJeu 
{
	FinDePartieAlekhineCapablanca FinDePartieAlekhineCapablanca::instance_ = FinDePartieAlekhineCapablanca();

	FinDePartieAlekhineCapablanca::FinDePartieAlekhineCapablanca() : StrategiePlacementPieces(FinDePartieAlekhineCapablanca::nomStrategie_) {
		description_ = "Fin de partie du match final entre Jose Raul Capablanca et Alexander Alekhine en 1927 qui se termina en la victoire d'Alekhine et de son ascension au titre de Champion du monde d'echecs. Que le meilleur gagne!";
	}

	//Tour 36, tour au blanc
	void FinDePartieAlekhineCapablanca::placerPieces()
	{
		LogiqueJeu::Echiquier& echiquier = LogiqueJeu::Echiquier::echiquier();
		echiquier.nettoyer();

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir)), { 7, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), { 6, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Noir)), { 1, 8 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 6, 7 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 7, 6 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Noir)), { 8, 6 });

		echiquier.ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), { 7, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc)), { 3, 1 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Tour>(LogiqueJeu::Tour(Couleur::Blanc)), { 5, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 1, 4 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 6, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 7, 2 });
		echiquier.ajouterPiece(make_unique<LogiqueJeu::Pion>(LogiqueJeu::Pion(Couleur::Blanc)), { 8, 3 });
	}
}