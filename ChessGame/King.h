#pragma once

#include "Piece.h"

class King :
    public Piece
{
public:
	// Update
	int checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color) override;

	King(Vector2i* vec);

private:
	Vector2i* m_canCastle;
};