#include "Knight.h"

int Knight::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
    /*
        Funzione che controlla la validitá della mossa
    */
    switch (color) // Controlla il colore del pezzo
    {
        // Bianco
    case false:
        // Verifica che la nuova posizione non sia un alleato
        if (chessboard[newPos.y][newPos.x] == pieceType::EMPTY || chessboard[newPos.y][newPos.x] >= pieceType::BLACKPAWN)
            // Verifica che la nuova posizione sia una delle possibili mosse del cavallo
            if (
                ((newPos.x == pos.x - 1 || newPos.x == pos.x + 1) && (newPos.y == pos.y - 2 || newPos.y == pos.y + 2))
                ||
                ((newPos.x == pos.x - 2 || newPos.x == pos.x + 2) && (newPos.y == pos.y - 1 || newPos.y == pos.y + 1))
                )
                return 1;
        // Nero
    case true:
        // Verifica che la nuova posizione non sia un alleato
        if (chessboard[newPos.y][newPos.x] <= pieceType::WHITEKING)
            // Verifica che la nuova posizione sia una delle possibili mosse del cavallo
            if (
                ((newPos.x == pos.x - 1 || newPos.x == pos.x + 1) && (newPos.y == pos.y - 2 || newPos.y == pos.y + 2))
                ||
                ((newPos.x == pos.x - 2 || newPos.x == pos.x + 2) && (newPos.y == pos.y - 1 || newPos.y == pos.y + 1))
               )
                return 1;
    }

    // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
    return 0;
}
