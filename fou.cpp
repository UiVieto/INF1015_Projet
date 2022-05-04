#include "fou.h"

namespace LogiqueJeu
{
	Fou::Fou(Couleur couleur) {
		couleur_ = couleur;
	}

	bool LogiqueJeu::Fou::estMouvementPossible(std::pair<int, int>& positionInitiale, std::pair<int, int>& nouvellePosition) const {
		return (abs(positionInitiale.first - nouvellePosition.first) == abs(positionInitiale.second - nouvellePosition.second));
	}
}