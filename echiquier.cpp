#include "echiquier.h"
#include <cmath>

/*--------------------------------Pieces---------------------------------*/

Roi::Roi(Couleur couleur) {
	couleur_ = couleur;
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

/*--------------------------------Echiquier---------------------------------*/

void Echiquier::ajouterPiece(shared_ptr<Piece> piece, pair<int, int> position) {
	//TODO: Vérifier que la pièce ajoutée soit dans l'échiquier.
		grille_[position] = move(piece);
}

void Echiquier::deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) {
	shared_ptr<Piece>& piece = prendrePiece(positionInitiale);

	if (piece->estMouvementPossible(positionInitiale, nouvellePosition)) 
	{
		if (!verifierObstacle(positionInitiale, nouvellePosition)) {
			grille_[nouvellePosition] = move(piece);
		}
	}
}

shared_ptr<Piece>& Echiquier::prendrePiece(pair<int, int> position) {
	return grille_[position];
}

bool Echiquier::verifierObstacle(pair<int, int>& positionInitiale, pair<int, int>& nouvelleInitiale)
{
	//TODO: Vérifier s'il y aucune pièce qui bloque le chemin.
	return false;  
}