#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Fou : public Piece
	{
	public:
		Fou(Couleur couleur);

	protected:
		bool estMouvementPossible(std::pair<int, int>& positionInitiale,
			std::pair<int, int>& nouvellePosition) const override;
	};
}
