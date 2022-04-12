#include "InterfacePieces.h"
#include "Position.h"
#include "echiquier.h"

enum class TypePiece
{
	Roi,
	Reine,
	Pion,
	Tour,
	Cavalier
};

enum class CouleurPiece
{
	noir,
	blanc
};

class Piece : public interfacesPiece
{
public:
	Piece(TypePiece type, CouleurPiece couleur, Poition pos, Echiquier echiquier);

	~Piece();

	CouleurPiece getCouleurPiece();
	TypePiece getTypePiece();
	bool estUnMouvementValide(Position pos);
	void setPremierCoup();

	Position pos;
	TypePiece type;
	CouleurPiece couleur;
	bool estUnPremierCoup = false;

};