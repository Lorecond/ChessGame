#include "SpriteManager.h"

// Game
void SpriteManager::initGame()
{
	// Chessboard
	if (!this->m_chessboardTexture.loadFromFile("Assets/Chessboards/WoodenChessBoard.png"))
		cout << "~ERRORE : WoodenChessBoard.png non e' stato caricato" << endl;
	this->chessboardSprite.setTexture(this->m_chessboardTexture);
	this->chessboardSprite.setScale(Vector2f(2.5, 2.5));
	this->chessboardSprite.setPosition(Vector2f(0, 0));

	// Pawn w / b
	if (!this->m_wPawnTexture.loadFromFile("Assets/ChessPieces/White/Pawn.png"))
		cout << "~ERRORE : White Pawn.png non e' stato caricato" << endl;
	this->wPawnSprite.setTexture(this->m_wPawnTexture);
	this->wPawnSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bPawnTexture.loadFromFile("Assets/ChessPieces/Black/Pawn.png"))
		cout << "~ERRORE : Black Pawn.png non e' stato caricato" << endl;
	this->bPawnSprite.setTexture(this->m_bPawnTexture);
	this->bPawnSprite.setScale(Vector2f(2.5, 2.5));
	// Knight w / b
	if (!this->m_wKnightTexture.loadFromFile("Assets/ChessPieces/White/Knight.png"))
		cout << "~ERRORE : White Knight.png non e' stato caricato" << endl;
	this->wKnightSprite.setTexture(this->m_wKnightTexture);
	this->wKnightSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bKnightTexture.loadFromFile("Assets/ChessPieces/Black/Knight.png"))
		cout << "~ERRORE : Black Knight.png non e' stato caricato" << endl;
	this->bKnightSprite.setTexture(this->m_bKnightTexture);
	this->bKnightSprite.setScale(Vector2f(2.5, 2.5));
	// Bishop w / b
	if (!this->m_wBishopTexture.loadFromFile("Assets/ChessPieces/White/Bishop.png"))
		cout << "~ERRORE : White Bishop.png non e' stato caricato" << endl;
	this->wBishopSprite.setTexture(this->m_wBishopTexture);
	this->wBishopSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bBishopTexture.loadFromFile("Assets/ChessPieces/Black/Bishop.png"))
		cout << "~ERRORE : Black Bishop.png non e' stato caricato" << endl;
	this->bBishopSprite.setTexture(this->m_bBishopTexture);
	this->bBishopSprite.setScale(Vector2f(2.5, 2.5));
	// Rook w / b
	if (!this->m_wRookTexture.loadFromFile("Assets/ChessPieces/White/Rook.png"))
		cout << "~ERRORE : White Rook.png non e' stato caricato" << endl;
	this->wRookSprite.setTexture(this->m_wRookTexture);
	this->wRookSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bRookTexture.loadFromFile("Assets/ChessPieces/Black/Rook.png"))
		cout << "~ERRORE : Black Rook.png non e' stato caricato" << endl;
	this->bRookSprite.setTexture(this->m_bRookTexture);
	this->bRookSprite.setScale(Vector2f(2.5, 2.5));
	// Queen w / b
	if (!this->m_wQueenTexture.loadFromFile("Assets/ChessPieces/White/Queen.png"))
		cout << "~ERRORE : White Queen.png non e' stato caricato" << endl;
	this->wQueenSprite.setTexture(this->m_wQueenTexture);
	this->wQueenSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bQueenTexture.loadFromFile("Assets/ChessPieces/Black/Queen.png"))
		cout << "~ERRORE : Black Queen.png non e' stato caricato" << endl;
	this->bQueenSprite.setTexture(this->m_bQueenTexture);
	this->bQueenSprite.setScale(Vector2f(2.5, 2.5));
	// King w / b
	if (!this->m_wKingTexture.loadFromFile("Assets/ChessPieces/White/King.png"))
		cout << "~ERRORE : White King.png non e' stato caricato" << endl;
	this->wKingSprite.setTexture(this->m_wKingTexture);
	this->wKingSprite.setScale(Vector2f(2.5, 2.5));
	if (!this->m_bKingTexture.loadFromFile("Assets/ChessPieces/Black/King.png"))
		cout << "~ERRORE : Black King.png non e' stato caricato" << endl;
	this->bKingSprite.setTexture(this->m_bKingTexture);
	this->bKingSprite.setScale(Vector2f(2.5, 2.5));
}

// Main menu
void SpriteManager::initMainMenu()
{
	if (!this->m_backgroundTexture.loadFromFile("Assets/Chessboards/WoodenChessBoard.png"))
		cout << "~ERRORE : background.png was not loaded" << endl;
	this->backgroundSprite.setTexture(this->m_backgroundTexture);
	this->backgroundSprite.setScale(Vector2f(2.5, 2.5));
	this->backgroundSprite.setPosition(0.0f, 0.0f);
}