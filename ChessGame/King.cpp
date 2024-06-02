#include "King.h"

int King::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
    /*
        Funzione che controlla la validitá della mossa
    */
    switch (color) // Controlla il colore del pezzo
    {
        // Bianco
    case false:
        // Verifica che la nuova posizione non contenghi un pezzo alleato
        if (chessboard[newPos.y][newPos.x] == pieceType::EMPTY || chessboard[newPos.y][newPos.x] >= pieceType::BLACKPAWN )
        {
            // Verifica il caso in cui si muove di una casella
            if (
                (newPos.x == pos.x - 1 || newPos.x == pos.x + 1 || newPos.x == pos.x) 
                && 
                (newPos.y == pos.y - 1 || newPos.y == pos.y + 1 || newPos.y == pos.y)
               )
                return 1;
            
            if (pos.y == newPos.y)
            {
                // Destra
                if (newPos.x == pos.x + 2 && (this->m_canCastle->x == 2 || this->m_canCastle->x == 3))
                {
                    if (chessboard[pos.y][pos.x + 1] == pieceType::EMPTY)
                        return 2;
                }
                
                // Sinistra
                if (newPos.x == pos.x - 2 && (this->m_canCastle->x == 1 || this->m_canCastle->x == 3))
                {
                    if (chessboard[pos.y][pos.x - 1] == pieceType::EMPTY && chessboard[pos.y][pos.x - 3] == pieceType::EMPTY)
                        return 3;
                }
            }
        }
        break;

        // Nero
    case true:
        // Verifica che la nuova posizione non contenghi un pezzo alleato
        if (chessboard[newPos.y][newPos.x] <= pieceType::WHITEKING)
        {
            // Verifica il caso in cui si muove di una casella
            if (
                (newPos.x == pos.x - 1 || newPos.x == pos.x + 1 || newPos.x == pos.x)
                &&
                (newPos.y == pos.y - 1 || newPos.y == pos.y + 1 || newPos.y == pos.y)
                )
                return 1;

            if (pos.y == newPos.y)
            {
                // Destra
                if (newPos.x == pos.x + 2 && (this->m_canCastle->y == 2 || this->m_canCastle->y == 3))
                {
                    if (chessboard[pos.y][pos.x + 1] == pieceType::EMPTY)
                        return 2;
                }

                // Sinistra
                if (newPos.x == pos.x - 2 && (this->m_canCastle->y == 1 || this->m_canCastle->y == 3))
                {
                    if (chessboard[pos.y][pos.x - 1] == pieceType::EMPTY && chessboard[pos.y][pos.x - 3] == pieceType::EMPTY)
                        return 3;
                }
            }
        }
        break;
    }

    // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
    return 0;
}

/// //////////////////////////////////////////////////////////////////////
King::King(Vector2i* vec)
    :m_canCastle(vec)
{
}
/// //////////////////////////////////////////////////////////////////////