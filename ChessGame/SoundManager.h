#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

class SoundManager
{
public:
	// Game
	// Sound
	Sound soundMovePiece;
	Sound soundCapturePiece;
	Sound soundCastle;

	// Buffer

	// Init Game object
	void initGame();

	// Main menu
	// Sound

	// Buffer

	// Init Main Menu object
	void initMainMenu();

private:
	// Private Game Buffer
	SoundBuffer m_movePiecebuffer;
	SoundBuffer m_capturePiecebuffer;
	SoundBuffer m_castlebuffer;

	// Private Main menu Buffer

};

