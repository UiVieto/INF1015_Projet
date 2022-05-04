#pragma once
#include <utility>
#include <map>
#include <memory>
using namespace std;

enum class Couleur {
	Blanc,
	Noir
};

namespace LogiqueJeu 
{
	class Piece
	{
	public:
		virtual ~Piece();
		virtual Couleur getColor();

	protected:
		virtual bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition, std::map<std::pair<int, int>, std::unique_ptr<LogiqueJeu::Piece>> grille) const = 0;

		Couleur couleur_;

	private:
		friend class Echiquier;
	};
}
