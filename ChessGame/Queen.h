#pragma once

#include "Piece.h"

class Queen :
    public Piece
{
public:
	// Update
	int checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color) override;
};