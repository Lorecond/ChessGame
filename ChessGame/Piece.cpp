#include "Piece.h"

// Update
int Piece::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
	/*
		Funzione che controllerá la validitá di una mossa in base al pezzo selezionato
	*/

	return 0;
}
// Render
void Piece::render(RenderWindow* window, Vector2i coord, Sprite& sprite)
{
	/*
		Funzione che disegnerá lo sprite del pezzo
	*/
	sprite.setPosition(Vector2f(40 + 80 * coord.x, 40 + 80 * coord.y));
	window->draw(sprite);
}
