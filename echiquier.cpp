#include "echiquier.h"

Echiquier& LogiqueJeu::Echiquier::echiquier() {
	static Echiquier echiquier;
	return echiquier;
}

void LogiqueJeu::Echiquier::ajouterPiece(unique_ptr<Piece> piece, pair<int, int> position) {
	grille_[position] = move(piece);
}

void LogiqueJeu::Echiquier::deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) {
	unique_ptr<Piece>& piece = prendrePiece(positionInitiale);
	
	if (piece->estMouvementPossible(positionInitiale, nouvellePosition)) 
	{
		if (!verifierObstacle(positionInitiale, nouvellePosition))
		{
			unique_ptr<Piece>& autrePiece = prendrePiece(nouvellePosition);
			if (autrePiece != nullptr)
			{
				if (autrePiece->couleur_ != piece->couleur_) {
					grille_[nouvellePosition] = move(piece);
				}
			}

			else {
				grille_[nouvellePosition] = move(piece);
			}
		}
	}
}

unique_ptr<Piece>& LogiqueJeu::Echiquier::prendrePiece(pair<int, int> position) {
	return grille_[position];
}

int LogiqueJeu::calculerDirection(int valeurInitiale, int nouvelleValeur) {
	const int variation = nouvelleValeur - valeurInitiale;
	
	return (variation == 0) ? 0 : variation / abs(variation);
}

bool LogiqueJeu::Echiquier::verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition)
{
	//TODO: Si c'est un cheval, passer la vérification.

	const int directionHorizontale = calculerDirection(positionInitiale.first, nouvellePosition.first);
	const int directionVerticale = calculerDirection(positionInitiale.second, nouvellePosition.second);
	int x = positionInitiale.first;
	int y = positionInitiale.second;

	while (true) {
		x += directionHorizontale;
		y += directionVerticale;

		if (nouvellePosition == pair<int, int>{x, y})
			break;

		else if (grille_[{ x, y }] != nullptr)
			return true;
	}

	return false;
}
