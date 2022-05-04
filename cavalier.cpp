#include "cavalier.h"

namespace LogiqueJeu
{
	Cavalier::Cavalier(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Cavalier::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const
	{
		int deplacementVertical = abs(nouvellePosition.second - positionInitiale.second);
		int deplacementHorizontal = abs(nouvelLePosition.first - positionInitiale.first);
		if (nouvellePosition.first > 8) || (nouvellePosition.second > 8) || (deplacementHorizontal == 0) || (deplacementVertical == 0)
			return false;
		if ((deplacementVertical + deplacementHorizontal) == 3)
		{
			changerCouleur();
			return true;
		}

		return false;
	}

	void Cavalier::changerCouleur() {
		(couleur_ == Noir) ? couleur_ = Blanc : couleur_ = Noir;
	}

}