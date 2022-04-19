#pragma once
#include <utility>
#include <map>
#include <memory>
using namespace std;

enum class Couleur {
	Blanc,	
	Noir
};

class InterfaceEchiquier;

class Piece
{
public:
	virtual ~Piece() = default;

protected:	
	virtual bool estMouvementPossible(pair<int, int>& positionInitiale, 
									  pair<int, int>& nouvellePosition) const = 0;

	Couleur couleur_;

private:
	friend class Echiquier;
};

class Roi : public Piece 
{
public:
	Roi(Couleur couleur);

protected:
	bool estMouvementPossible(pair<int, int>& positionInitiale,
							  pair<int, int>& nouvellePosition) const override;
};

class Reine : public Piece
{
public:
	Reine(Couleur couleur);

private:
	bool estMouvementPossible(pair<int, int>& positionInitiale,
		pair<int, int>& nouvellePosition) const override;
};

class Tour : public Piece
{
public:
	Tour(Couleur couleur);

protected:
	bool estMouvementPossible(pair<int, int>& positionInitiale,
						      pair<int, int>& nouvellePosition) const override;
};

class Fou : public Piece
{
public:
	Fou(Couleur couleur);

protected:
	bool estMouvementPossible(pair<int, int>& positionInitiale,
							  pair<int, int>& nouvellePosition) const override;
};

class Echiquier
{
public:
	Echiquier() = default;

	shared_ptr<Piece>& prendrePiece(pair<int, int> position);
	void ajouterPiece(shared_ptr<Piece> piece, pair<int, int> position);
	void deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition);
	
private:
	
	bool verifierObstacle(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition);
	
	map<pair<int, int>, shared_ptr<Piece>> grille_;
	const static int taille_ = 8;

	friend InterfaceEchiquier;
};
