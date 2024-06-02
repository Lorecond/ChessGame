#include "Bishop.h"

int Bishop::checkLegalMove(Vector2i pos, Vector2i newPos, vector<vector<pieceType>> chessboard, bool color)
{
    /*
        Funzione che controlla la validitá della mossa
    */
    switch (color) // Controlla il colore del pezzo
    {
        // Bianco
    case false:
        // Verifica che la nuova posizione non sia un alleato o che sia vuota
        if (chessboard[newPos.y][newPos.x] == pieceType::EMPTY || chessboard[newPos.y][newPos.x] >= pieceType::BLACKPAWN)
        {
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
                while (chessboard[newPos.y][newPos.x] != pieceType::WHITEBISHOP)
                {
                    newPos.x += conta.x;
                    newPos.y += conta.y;
                 
                    // Verifica che la casella sia libera e che non stia controllando che ci sia l'alfiere
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::WHITEBISHOP)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
        }
        break;

        // Nero
    case true:
        //Controlla se la nuova posizione non é un pezzo alleato
        if (chessboard[newPos.y][newPos.x] <= pieceType::WHITEKING)
        {
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
                while (chessboard[newPos.y][newPos.x] != pieceType::BLACKBISHOP)
                {
                    newPos.x += conta.x;
                    newPos.y += conta.y;

                    // Verifica che la casella sia libera e che non stia controllando che ci sia l'alfiere
                    if (chessboard[newPos.y][newPos.x] > pieceType::EMPTY && chessboard[newPos.y][newPos.x] != pieceType::BLACKBISHOP)
                        return 0;
                }
                // Se esce correttamente la ciclo allora la mossa é valida
                return 1;
            }
        }
        break;
    }

    // Se nessuna delle precedenti affermazioni risulta essere vera allora non era valida
    return 0;
}