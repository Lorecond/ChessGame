#include "Chessboard.h"

// Events
void Chessboard::updateInput(Event& eve)
{
    /*
        Gestione degli input
        Controlla se si ha premuto o rilasciato il tasto sinistro del mouse    
    */
    switch (eve.type)
    {
    case Event::MouseButtonPressed:
        if (eve.mouseButton.button == Mouse::Left)
        {
            // Salva e converte la posizione del mouse
            this->m_mousePos = Mouse::getPosition(*this->m_window);
            this->m_mousePos.x = (this->m_mousePos.x - 40) / 80;
            this->m_mousePos.y = (this->m_mousePos.y - 40) / 80;
            
            // Controlla che le coordinate rispettino la griglia
            if (this->m_mousePos.x >= 0 && this->m_mousePos.x <= 7
                &&
                this->m_mousePos.y >= 0 && this->m_mousePos.y <= 7
                )
            // Salva il pezzo selezionato
            this->m_selectedPiece = this->m_chessboard[this->m_mousePos.y][this->m_mousePos.x];
        }
        break;

    case Event::MouseButtonReleased:
        if (eve.mouseButton.button == Mouse::Left)
        {
            // Salva e converte la posizione del mouse
            this->m_newMousePos = Mouse::getPosition(*this->m_window);
            this->m_newMousePos.x = (this->m_newMousePos.x - 40) / 80;
            this->m_newMousePos.y = (this->m_newMousePos.y - 40) / 80;
            
            // Controlla che le coordinate rispettino la griglia
            if (
                this->m_newMousePos.x >= 0 && this->m_newMousePos.x <= 7
                &&
                this->m_newMousePos.y >= 0 && this->m_newMousePos.y <= 7
               )
            this->movePiece(this->checkLegaleMove(this->m_selectedPiece));
        }
        break;
    }
}
// Update
void Chessboard::update()
{
}
// Render
void Chessboard::render()
{
    /*
        Disegna la scacchiera e i suoi componenti
    */
    this->renderChessboard();
    this->renderChessPiece();
}

/// //////////////////////////////////////////////////////////////////////
Chessboard::Chessboard(RenderWindow* window, SpriteManager* spriteManager, SoundManager* soundManager)
    : m_window(window), m_spriteManager(spriteManager), m_soundManager(soundManager), 
    m_chessboard(8, vector<pieceType>(8, pieceType::EMPTY)),
    m_king(&this->m_canCastle)

{
    /*
        Inizializza le variabili necessarie per la scacchiera
    */
    this->initVariables();
    this->initChessboard();
}
Chessboard::~Chessboard()
{
    
}
/// //////////////////////////////////////////////////////////////////////


// Inizializzatori
void Chessboard::initVariables()
{
    /*
        Funzione che inizializza le variabili per le funzioni di gioco
        - kingPos       : .Variabili che salvano le posizioni dei re
        - currentMove   : false = bianco / true = nero. Variabile per il controllo del turno.
        - canCastle     : 3 = entrambi i lati / 2 = solo a destra / 1 = solo a sinistra / 0 = nessuna. Variabile per il controllo della possibilitá di arroccare
        - selectedpiece : .Variabile che salva il pezzo che si ha selezionato 
        - mousePos      : .Variabili che salvano la posizione del pezzo selezionato e della nuova posizione
    */
    this->m_currentMove = false;
    this->m_canCastle.x = 3;
    this->m_canCastle.y = 3;
    this->m_selectedPiece = pieceType::EMPTY;
    this->m_mousePos.x = 0;
    this->m_mousePos.y = 0;
    this->m_newMousePos.x = 0;
    this->m_newMousePos.y = 0;
}
void Chessboard::initChessboard()
{
    /*
        Funzione che inizializza la scacchiera
    */
    this->m_chessboard =
    {
        {pieceType::BLACKROOK,pieceType::BLACKKNIGHT,pieceType::BLACKBISHOP,pieceType::BLACKQUEEN,pieceType::BLACKKING,pieceType::BLACKBISHOP,pieceType::BLACKKNIGHT,pieceType::BLACKROOK},
        {pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN,pieceType::BLACKPAWN},
        {pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY},
        {pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY},
        {pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY},
        {pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY,pieceType::EMPTY},
        {pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN,pieceType::WHITEPAWN},
        {pieceType::WHITEROOK,pieceType::WHITEKNIGHT,pieceType::WHITEBISHOP,pieceType::WHITEQUEEN,pieceType::WHITEKING,pieceType::WHITEBISHOP,pieceType::WHITEKNIGHT,pieceType::WHITEROOK},
    };
}

// Funzioni degli eventi
void Chessboard::checkCastleAbility()
{
    /*
        Funzione che controlla se si perde la capacitá di arroccare
           Bianco|Nero
        se  < 0  | < 0   : non c'é bisogno di controllare dato che non si ha la capacitá di arroccare
            != 6 | != 14 : controlla che il re si sia mosso e toglie la capacitá di arroccare
            != 4 | != 12 : controlla sia la torre di destra che di sinistra si sia mossa e toglie la capacitá di arroccare in una delle due direzioni

        Si esce dalla funzione quando si trova quella vera perché non ci potrebbero essere casi in cui ci siano piú condizioni vere allo stesso tempo
    */

    if (this->m_canCastle.x > 0)
    {
        if (this->m_chessboard[7][4] != pieceType::WHITEKING)
        {
            this->m_canCastle.x = 0;
            return;
        }
        if (this->m_chessboard[7][0] != pieceType::WHITEROOK)
        {
            this->m_canCastle.x = 2;
            return;
        }
        if (this->m_chessboard[7][7] != pieceType::WHITEROOK)
        {
            this->m_canCastle.x = 1;
            return;
        }
    }
    if (this->m_canCastle.y > 0)
    {
        if (this->m_chessboard[0][4] != pieceType::BLACKKING)
        {
            this->m_canCastle.y = 0;
            return;
        }
        if (this->m_chessboard[0][0] != pieceType::BLACKROOK)
        {
            this->m_canCastle.y = 2;
            return;
        }
        if (this->m_chessboard[0][7] != pieceType::BLACKROOK)
        {
            this->m_canCastle.y = 1;
            return;
        }
    }
}
int Chessboard::checkLegaleMove(pieceType type)
{
    /*
        Funzione che controlla la validitá delle mosse,
        Controlla a chi tocca muovere i pezzi : Falso = Bianco / Vero = Nero
        Controlla quale pezzo si ha selezionato,
        Controlla se si ha selezionato una mossa valida
    */
    switch (this->m_currentMove)
    {
    case false:
        switch (type)
        {
            // Vuoto
        case EMPTY:
            return 0;

            // Bianco
        case WHITEPAWN:
            return this->m_pawn.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        case WHITEKNIGHT:
            return this->m_knight.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        case WHITEBISHOP:
            return this->m_bishop.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        case WHITEROOK:
            return this->m_rook.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        case WHITEQUEEN:
            return this->m_queen.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        case WHITEKING:
            return this->m_king.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, false);
        }
        break;
        
    case true:
        switch (type)
        {
            // Vuoto
        case EMPTY:
            return 0;

            // Black
        case BLACKPAWN:
            return this->m_pawn.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        case BLACKKNIGHT:
            return this->m_knight.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        case BLACKBISHOP:
            return this->m_bishop.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        case BLACKROOK:
            return this->m_rook.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        case BLACKQUEEN:
            return this->m_queen.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        case BLACKKING:
            return this->m_king.checkLegalMove(this->m_mousePos, this->m_newMousePos, this->m_chessboard, true);
        }
    }
}
void Chessboard::movePiece(int var)
{
    /*
        Funzione che gestisce gli spostamenti dei pezzi
        Var = 0 : La mossa selezionato non era valida ed esce
        Var = 1 : La mossa selezionata era valida, si riproduce un suono in base al tipo di mossa effettuata, e muove i pezzi
    */

    switch (var)
    {
        // Caso in cui la mossa non era valida
    case 0:
        break;

        // Caso in cui la mossa é valida
    case 1:
        if (this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x] == pieceType::EMPTY)
            this->m_soundManager->soundMovePiece.play();
        else 
            this->m_soundManager->soundCapturePiece.play();

        this->m_chessboard[this->m_mousePos.y][this->m_mousePos.x] = pieceType::EMPTY;
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x] = this->m_selectedPiece;

        this->m_currentMove = !this->m_currentMove;
        break;

        // Caso in cui si arrocca a destra
    case 2: 
        this->m_soundManager->soundCastle.play();

        this->m_chessboard[this->m_mousePos.y][this->m_mousePos.x] = pieceType::EMPTY;
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x] = this->m_selectedPiece;
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x - 1] = this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x + 1];
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x + 1] = pieceType::EMPTY;

        this->m_currentMove = !this->m_currentMove;
        break;

        // Caso in cui si arrocca a sinistra
    case 3:
        this->m_soundManager->soundCastle.play();

        this->m_chessboard[this->m_mousePos.y][this->m_mousePos.x] = pieceType::EMPTY;
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x] = this->m_selectedPiece;
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x + 1] = this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x - 2];
        this->m_chessboard[this->m_newMousePos.y][this->m_newMousePos.x - 2] = pieceType::EMPTY;

        this->m_currentMove = !this->m_currentMove;
        break;
    }
    this->checkCastleAbility();
}
// Funzioni dell'update

// Funzioni del render
void Chessboard::renderChessboard()
{
    /*
        Funzione che disegna la scacchiera
    */
    this->m_window->draw(this->m_spriteManager->chessboardSprite);
}
void Chessboard::renderChessPiece()
{
    /*
        Funzione che disegna i pezzi presenti nella scacchiera
        Controlla ogni singola casella della scacchiera 
        Aggiorna la posizione del pezzo trovato e lo disegna subito
    */
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            switch (this->m_chessboard[y][x])
            {
                // Vuoto
            case pieceType::EMPTY:
                break;

                // Bianco
            case pieceType::WHITEPAWN:
                this->m_pawn.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wPawnSprite);
                break;
            case pieceType::WHITEKNIGHT:
                this->m_knight.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wKnightSprite);
                break;
            case pieceType::WHITEBISHOP:
                this->m_bishop.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wBishopSprite);
                break;
            case pieceType::WHITEROOK:
                this->m_rook.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wRookSprite);
                break;
            case pieceType::WHITEQUEEN:
                this->m_queen.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wQueenSprite);
                break;
            case pieceType::WHITEKING:
                this->m_king.render(this->m_window, Vector2i(x, y), this->m_spriteManager->wKingSprite);
                break;

                // Nero
            case pieceType::BLACKPAWN:
                this->m_pawn.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bPawnSprite);
                break;
            case pieceType::BLACKKNIGHT:
                this->m_knight.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bKnightSprite);
                break;
            case pieceType::BLACKBISHOP:
                this->m_bishop.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bBishopSprite);
                break;
            case pieceType::BLACKROOK:
                this->m_rook.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bRookSprite);
                break;
            case pieceType::BLACKQUEEN:
                this->m_queen.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bQueenSprite);
                break;
            case pieceType::BLACKKING:
                this->m_king.render(this->m_window, Vector2i(x, y), this->m_spriteManager->bKingSprite);
                break;
            }
        }
    }
}
