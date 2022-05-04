#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Tour : public Piece
	{
	public:
		Tour(Couleur couleur);

	protected:
		bool estMouvementPossible(std::pair<int, int>& positionInitiale,
			std::pair<int, int>& nouvellePosition) const override;
	};
}
