#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class SpriteManager
{
public:
	// Game
	// Sprite
	Sprite chessboardSprite;
	Sprite wPawnSprite;
	Sprite bPawnSprite;
	Sprite wKnightSprite;
	Sprite bKnightSprite;
	Sprite wBishopSprite;
	Sprite bBishopSprite;
	Sprite wRookSprite;
	Sprite bRookSprite;
	Sprite wQueenSprite;
	Sprite bQueenSprite;
	Sprite wKingSprite;
	Sprite bKingSprite;

	// Texture

	// Init Game object
	void initGame();

	// Main menu
	// Sprite
	Sprite backgroundSprite;

	// Texture

	// Init Main Menu object
	void initMainMenu();

private:
	// Private Game texture
	Texture m_chessboardTexture;
	Texture m_wPawnTexture;
	Texture m_bPawnTexture;
	Texture m_wKnightTexture;
	Texture m_bKnightTexture;
	Texture m_wBishopTexture;
	Texture m_bBishopTexture;
	Texture m_wRookTexture;
	Texture m_bRookTexture;
	Texture m_wQueenTexture;
	Texture m_bQueenTexture;
	Texture m_wKingTexture;
	Texture m_bKingTexture;

	// Private Main menu texture
	Texture m_backgroundTexture;

};