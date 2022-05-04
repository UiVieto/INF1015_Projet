#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Tour : public Piece
	{
	public:
		Tour(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const override;
		bool tentativePrisePiece(pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const override;
	};
}
