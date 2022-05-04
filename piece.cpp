#pragma once
#include "piece.h"
#include <iostream>

Piece::~Piece() {
	cout << "Destruction de piece" << endl;
}
Couleur Piece::getColor() {
	return couleur_;
}