#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Fou : public Piece
	{
	public:
		Fou(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const override;
	};
}
