#include Piece.h


class Reine : public Piece {
public:
	bool getType() {
		return estUneReine;
	};
private:
	bool estUneReine = true;
};