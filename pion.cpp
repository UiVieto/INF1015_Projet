#include "pion.h"

namespace LogiqueJeu
{
	Pion::Pion(Couleur couleur) {
		couleur_ = couleur;
		CaseInitiale = true;
	}

	bool Pion::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		if (nouvellePosition.first > 8) || (nouvellePosition.second > 8)
			return false;

		if (CaseInitiale == true) && (deplacementHorizontal == 0) && (deplacementVertical <= 2)
		{
			CaseInitiale = false;
			return true;
		}
		
		if (deplacementHorizontal != true)

	}
}