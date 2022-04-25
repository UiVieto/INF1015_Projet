#pragma once
#include "pieces.h"
#include <cmath>
#include <stdexcept>

Roi::Roi(Couleur couleur) {

	if (compteurRoi_ == 2)
		throw logic_error("Il ne peut pas y avoir plus de 2 rois");

	compteurRoi_++;
	couleur_(couleur);
}
Roi::getCompteur() {
	return compteurRoi_;
}

bool Roi::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
	return (abs(nouvellePosition.first - positionInitiale.first) <= 1 &&
		abs(nouvellePosition.second - positionInitiale.second) <= 1);
}

Reine::Reine(Couleur couleur) {
	couleur_ = couleur;
}

bool Reine::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
	const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
	const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

	if ((abs(positionInitiale.first - nouvellePosition.first) != abs(positionInitiale.second - nouvellePosition.second)))
		return (deplacementHorizontal * deplacementVertical == 0 && deplacementHorizontal - deplacementVertical != 0);

	return true;
}

Tour::Tour(Couleur couleur) {
	couleur_ = couleur;
}

bool Tour::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
	const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
	const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

	return (deplacementHorizontal * deplacementVertical == 0 &&
		deplacementHorizontal - deplacementVertical != 0);
}

Fou::Fou(Couleur couleur) {
	couleur_ = couleur;
}

bool Fou::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
	return (abs(positionInitiale.first - nouvellePosition.first) == abs(positionInitiale.second - nouvellePosition.second));
}
