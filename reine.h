#pragma once
#include "piece.h"

namespace LogiqueJeu 
{
	class Reine : public Piece
	{
	public:
		Reine(Couleur couleur);

	private:
		bool estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille)) const override;
	};
}
