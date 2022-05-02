#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Pion : public piece
	{
	public:
		Pion(Couleur couleur);

	private:
		bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition) const override;
		int Tour = 0;
		bool CaseInitiale;
		bool Promotion;
	}

}
