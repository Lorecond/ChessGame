#include "Pawn.h"

int Pawn::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
    /*
        Funzione che controlla la validitá della mossa 
    */
    switch (color) // Controlla il colore del pezzo
    {
        // Bianco
    case false:
        // Verifica il caso in cui si vuole muovere di una casella
        if (newPos.y == pos.y - 1)
        {
            // Verifica il caso in cui si muove nella casella frontale
            if (chessboard[newPos.y][newPos.x] == pieceType::EMPTY && pos.x == newPos.x)
                return 1;
            // Verifica il caso in cui si muove nella casella laterale
            if (chessboard[newPos.y][newPos.x] >= pieceType::BLACKPAWN && (pos.x == newPos.x - 1 || pos.x == newPos.x + 1))
                return 1;
        }
        // Verifica il caso in cui il si vuole muovere di due caselle
        if (pos.y == 6)
        {
            if (
                (newPos.y == pos.y - 2 && pos.x == newPos.x)
                && 
                (chessboard[newPos.y][newPos.x] == pieceType::EMPTY && chessboard[newPos.y + 1][newPos.x] == pieceType::EMPTY)
               )
                return 1;
        }
        break;

        // Nero
    case true:
        // Verifica il caso in cui si vuole muovere di una casella
        if (newPos.y == pos.y + 1)
        {
            // Verifica il caso in cui si muove nella casella frontale
            if (chessboard[newPos.y][newPos.x] == pieceType::EMPTY && pos.x == newPos.x)
                return 1;
            // Verifica il caso in cui si muove nella casella laterale
            if (chessboard[newPos.y][newPos.x] <= pieceType::WHITEKING && (pos.x == newPos.x - 1 || pos.x == newPos.x + 1))
                return 1;
        }
        // Verifica il caso in cui il si vuole muovere di due caselle
        if (pos.y == 1)
        {
            if (
                (newPos.y == pos.y + 2 && pos.x == newPos.x)
                && 
                (chessboard[newPos.y][newPos.x] == pieceType::EMPTY && chessboard[newPos.y - 1][newPos.x] == pieceType::EMPTY)
               )
                return 1;
        }
        break;
    }

    // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
    return 0;
}