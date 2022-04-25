#pragma once
#include <utility>
#include <map>
#include <memory>
using namespace std;

#include "pieces.h"

namespace LogiqueJeu {
	class Echiquier
	{
	public:
		static Echiquier& echiquier();

		unique_ptr<Piece>& prendrePiece(pair<int, int> position);
		void ajouterPiece(unique_ptr<Piece> piece, pair<int, int> position);
		void deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition);
		
	private:
		Echiquier() = default;

		bool verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition);
		
		map<pair<int, int>, unique_ptr<Piece>> grille_;
		const static int taille_ = 8;

		friend InterfaceEchiquier;
	};


}
