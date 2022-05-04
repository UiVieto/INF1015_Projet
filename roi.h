#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Roi : public Piece
	{
	public:
		Roi(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille)) const override;
		bool tentativePrisePiece(pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const override;
		bool estEnEchec(pair<int, int>& positionInitiale, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille);
	private:
		static int compteurRoi_;
		bool echec = false;
	};
}
