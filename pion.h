#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Pion : public Piece
	{
	public:
		Pion(Couleur couleur);

	protected:
		bool estMouvementPossible(std::pair<int, int>& positionInitiale,
			std::pair<int, int>& nouvellePosition) const override;
	};
}
