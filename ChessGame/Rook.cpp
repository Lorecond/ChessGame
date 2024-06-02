#include "Rook.h"

int Rook::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
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
        {
            // Verifica il caso in cui si muove verticalmente
            if (pos.x == newPos.x)
            {
                int conta = 1;
                conta = newPos.y > pos.y ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEROOK)
                {
                    newPos.y += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEROOK)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
            // Verifica il caso in cui si muove orizontalmente
            if (newPos.y == pos.y)
            {
                int conta = 1;
                conta = newPos.x > pos.x ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEROOK)
                {
                    newPos.x += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEROOK)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
        }
        break;

        // Nero
    case true:
        // Verifica che la nuova posizione non sia un alleato
        if (chessboard[newPos.y][newPos.x] <= pieceType::WHITEKING)
        {
            // Verifica il caso in cui si muove verticalmente
            if (newPos.x == pos.x)
            {
                int conta = 1;
                conta = newPos.y > pos.y ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKROOK)
                {
                    newPos.y += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKROOK)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
            // Verifica il caso in cui si muove orizontalmente
            if (newPos.y == pos.y)
            {
                int conta = 1;
                conta = newPos.x > pos.x ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKROOK)
                {
                    newPos.x += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKROOK)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
            break;
        }

        // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
        return 0;
    }
}