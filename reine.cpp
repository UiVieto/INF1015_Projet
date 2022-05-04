#include "reine.h"

namespace LogiqueJeu
{
	Reine::Reine(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Reine::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		if (nouvellePosition.first > 8) || (nouvellePosition.second > 8)
			return false;

		if ((abs(positionInitiale.first - nouvellePosition.first) != abs(positionInitiale.second - nouvellePosition.second)))
			return (deplacementHorizontal * deplacementVertical == 0 && deplacementHorizontal - deplacementVertical != 0);

		return true;
	}
}