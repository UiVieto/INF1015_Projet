#pragma once
#include <utility>
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

class Cavalier : public Piece
{
public:
	Cavalier(Couleur couleur);

protected:
	bool estMouvementPossible(pair<int, int>& positionInitile, 
							  pair<int, int>& nouvellePosition) const override;
};
