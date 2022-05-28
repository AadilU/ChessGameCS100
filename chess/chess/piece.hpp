#ifndef PIECE_H
#define PIECE_H

#include "square.hpp"

class Piece {
protected:
	bool white;
	bool alive;
	square* currSquare;
public:
	Piece(bool isWhite) {
		white = isWhite;
		alive = true;
	};

	void kill() {
		alive = false;
	}

	bool isDead() {
		return (!alive);
	}

	bool isWhite() {
		return white;
	}
	virtual bool canMove(square* moveSquare) = 0;
};
#endif