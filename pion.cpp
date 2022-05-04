#include "pion.h"

namespace LogiqueJeu
{
	Pion::Pion(Couleur couleur) {
		couleur_ = couleur;
		CaseInitiale = true;
	}

	bool Pion::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const {
		const int deplacementHorizontal = nouvellePosition.first - positionInitiale.first;
		const int deplacementVertical = nouvellePosition.second - positionInitiale.second;

		if (nouvellePosition.first > 8) || (nouvellePosition.second > 8)
			return false;

		if (CasInitial == true) && (deplacementHorizontal == 0) && (deplacementVertical <= 2)
		{
			CasInitial = false;
			return true;
		}

		if (deplacementVertical < 1)
			return false;
		if (deplacementHorizontal == 1) && (deplacementVertical == 1) && (grille[nouvellePosition] != nullptr) && (grille[nouvellePosition]->getColor() != couleur_)
			return true;
		
		if (positionInitiale.second > 5)
			Promotion = true;



	}
}