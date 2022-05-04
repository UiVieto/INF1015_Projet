#include "roi.h"
#include <stdexcept>

namespace LogiqueJeu
{
	int Roi::compteurRoi_ = 0;

	Roi::Roi(Couleur couleur) {

	if (compteurRoi_ == 2)
		throw logic_error("Il ne peut pas y avoir plus de 2 rois");

	compteurRoi_++;
	couleur_ = couleur;
	}

	bool Roi::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const {
		if (abs(nouvellePosition.first - positionInitiale.first) <= 1 && abs(nouvellePosition.second - positionInitiale.second) <= 1)
		{
			return !estEnEchec(nouvellePosition, grille);
		}
	}
	bool Roi::tentativePrisePiece(pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const
	{
		if (grille[nouvellePosition]->couleur_ != couleur_)
			return true;
		return false;
	}

	bool Roi::estEnEchec(pair<int, int>& position, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille)
	{
		for (auto const& it : grille)
		{
			if (it.second->couleur_ != couleur_)
			{
				if (it.second->estMouvementPossible(it.first, position, grille))
				{
					echec = true;
					return true;
				}
			}
		}
		return false;
	}

}