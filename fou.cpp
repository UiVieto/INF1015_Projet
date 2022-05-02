#include "fou.h"

namespace LogiqueJeu
{
	Fou::Fou(Couleur couleur) {
		couleur_ = couleur;
	}

	bool LogiqueJeu::Fou::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
		if (nouvellePosition.first > 8) || (nouvellePosition.second > 8)
			return false;
		return (abs(positionInitiale.first - nouvellePosition.first) == abs(positionInitiale.second - nouvellePosition.second));
	}
}