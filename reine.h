#pragma once
#include "piece.h"

namespace LogiqueJeu 
{
	class Reine : public Piece
	{
	public:
		Reine(Couleur couleur);

	private:
		bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition) const override;
	};
}
