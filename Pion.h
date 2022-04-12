#include "Piece.h"


class Pion : public Piece {
public:
	bool getType() {
		return estUnPion;
	}
private:
	bool estUnPion = true;
};