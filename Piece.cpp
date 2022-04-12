#include "Piece.h"

Piece::getCouleurPiece() { return couleur;}

Piece::getTypePiece() { return type; }

Piece::setPremierCoup() 
{
	(*this).estUnPremierCoup = true;
}