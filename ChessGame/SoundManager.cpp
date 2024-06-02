#include "SoundManager.h"

// Game
void SoundManager::initGame()
{
    if (!this->m_movePiecebuffer.loadFromFile("Assets/Sounds/Move.mp3"))
        cout << "~ERRORE : Move.mp3 was not loaded" << endl;
    this->soundMovePiece.setBuffer(this->m_movePiecebuffer);

    if (!this->m_capturePiecebuffer.loadFromFile("Assets/Sounds/Capture.mp3"))
        cout << "~ERRORE : Capture.mp3 was not loaded" << endl;
    this->soundCapturePiece.setBuffer(this->m_capturePiecebuffer);

    if (!this->m_castlebuffer.loadFromFile("Assets/Sounds/Castle.mp3"))
        cout << "~ERRORE : Castle.mp3 was not loaded" << endl;
    this->soundCastle.setBuffer(this->m_castlebuffer);
}

// Main Menu
void SoundManager::initMainMenu()
{
	if (false)
		cout << "~ERRORE : was not loaded" << endl;
}
