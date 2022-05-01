#include "tour.h"

namespace LogiqueJeu 
{
	Tour::Tour(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Tour::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		return (deplacementHorizontal * deplacementVertical == 0 &&
			deplacementHorizontal - deplacementVertical != 0);
	}
}
