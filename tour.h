#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Tour : public Piece
	{
	public:
		Tour(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition) const override;
	};
}
