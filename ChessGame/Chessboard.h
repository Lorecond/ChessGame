#pragma once

#include "SpriteManager.h"
#include "SoundManager.h"

#include "King.h"
#include "Queen.h" 
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

class Chessboard
{
public:
	// Events
	void updateInput(Event& eve);
	// Update
	virtual void update();
	// Render
	virtual void render();

	Chessboard(RenderWindow* window, SpriteManager* spriteManager, SoundManager* soundManager);
	virtual ~Chessboard();

private:
	// Puntatori
	RenderWindow* m_window;
	SpriteManager* m_spriteManager;
	SoundManager* m_soundManager;

	// Scacchiera e pezzi
	vector<vector<pieceType>> m_chessboard;
	King m_king;
	Queen m_queen;
	Rook m_rook;
	Bishop m_bishop;
	Knight m_knight;
	Pawn m_pawn;
	
	// Variabili 
	bool m_currentMove;
	Vector2i m_canCastle;
	pieceType m_selectedPiece;
	Vector2i m_mousePos;
	Vector2i m_newMousePos;

	// Inizializzatori
	void initVariables();
	void initChessboard();

	// Funzioni degli eventi
	void checkCastleAbility();
	int checkLegaleMove(pieceType type);
	void movePiece(int var);

	// Funzioni dell'update
	
	// Funzioni del render
	void renderChessboard();
	void renderChessPiece();
};