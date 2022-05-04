#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Cavalier : public Piece
	{
	public:
		Cavalier(Couleur couleur) { couleur_ = couleur; };

	protected:
		bool estMouvementPossible(std::pair<int, int>& positionInitile,
			std::pair<int, int>& nouvellePosition) const override {
			return true;
		}
	};
}
