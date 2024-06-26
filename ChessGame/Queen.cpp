#include "Queen.h"

int Queen::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
    /*
        Funzione che controlla la validit� della mossa
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
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                {
                    newPos.y += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
                return 1;
            }
            // Verifica il caso in cui si muove orizontalmente
            if (newPos.y == pos.y)
            {
                int conta = 1;
                conta = newPos.x > pos.x ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                {
                    newPos.x += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
                return 1;
            }
            // Verifica il caso in cui si muove diagonalmente
            Vector2i valoreAssoluto;
            valoreAssoluto.x = newPos.x - pos.x;
            valoreAssoluto.y = newPos.y - pos.y;
            // Verifica che la nuova posizione sia una cassella diagonale controllando che la differenza delle coordinate in valore assoluto siano uguali
            if ((valoreAssoluto.x < 0 ? -valoreAssoluto.x : valoreAssoluto.x) == (valoreAssoluto.y < 0 ? -valoreAssoluto.y : valoreAssoluto.y))
            {
                Vector2i conta(1, 1);
                conta.x = newPos.x > pos.x ? -conta.x : conta.x;
                conta.y = newPos.y > pos.y ? -conta.y : conta.y;

                // Verifica che le caselle precedenti a quelle selezionate siano libere partendo dalla casella selezionato
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                {
                    newPos.x += conta.x;
                    newPos.y += conta.y;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia l'alfiere
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
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
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                {
                    newPos.y += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
                return 1;
            }
            // Verifica il caso in cui si muove orizontalmente
            if (newPos.y == pos.y)
            {
                int conta = 1;
                conta = newPos.x > pos.x ? -conta : conta;

                // Verifica che non si trovi un pezzo nel percorso
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                {
                    newPos.x += conta;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia la torre
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
                return 1;
            }
            // Verifica il caso in cui si muove diagonalmente
            Vector2i valoreAssoluto;
            valoreAssoluto.x = newPos.x - pos.x;
            valoreAssoluto.y = newPos.y - pos.y;
            // Verifica che la nuova posizione sia una cassella diagonale controllando che la differenza delle coordinate in valore assoluto siano uguali
            if ((valoreAssoluto.x < 0 ? -valoreAssoluto.x : valoreAssoluto.x) == (valoreAssoluto.y < 0 ? -valoreAssoluto.y : valoreAssoluto.y))
            {
                Vector2i conta(1, 1);
                conta.x = newPos.x > pos.x ? -conta.x : conta.x;
                conta.y = newPos.y > pos.y ? -conta.y : conta.y;

                // Verifica che le caselle precedenti a quelle selezionate siano libere partendo dalla casella selezionato
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                {
                    newPos.x += conta.x;
                    newPos.y += conta.y;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia l'alfiere
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKQUEEN)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa � valida
                return 1;
            }
            break;
        }

        // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
        return 0;
    }
}