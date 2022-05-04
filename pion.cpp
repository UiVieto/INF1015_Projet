#include "pion.h"

namespace LogiqueJeu
{
	Pion::Pion(Couleur couleur) {
		couleur_ = couleur;
	}

	bool Pion::estMouvementPossible(std::pair<int, int>& positionInitiale, std::pair<int, int>& nouvellePosition) const {
		return true;
	}
}