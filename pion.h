#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Pion : public piece
	{
	public:
		Pion(Couleur couleur);

	private:
		bool estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const override;
		int Tour = 0;
		bool CasInitial;
		bool Promotion;
	}

}
