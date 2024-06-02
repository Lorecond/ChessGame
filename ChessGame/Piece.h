#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

enum pieceType
{
	EMPTY = 0,
	WHITEPAWN,
	WHITEKNIGHT,
	WHITEBISHOP,
	WHITEROOK,
	WHITEQUEEN,
	WHITEKING,
	BLACKPAWN,
	BLACKKNIGHT,
	BLACKBISHOP,
	BLACKROOK,
	BLACKQUEEN,
	BLACKKING,
};

class Piece
{

public:
	// Update
	virtual int checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color);
	// Render
	void render(RenderWindow* window, Vector2i coord, Sprite&  sprite);
};
