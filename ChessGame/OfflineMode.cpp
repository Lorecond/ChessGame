#include "OfflineMode.h"

// Events
void OfflineMode::handleEvents(Event& eve)
{
	this->m_chessboard->updateInput(eve);
}
// Update
void OfflineMode::update()
{
	this->m_chessboard->update();
}
// Render
void OfflineMode::render()
{
	this->m_chessboard->render();
}

/// //////////////////////////////////////////////////////////////////////
OfflineMode::OfflineMode(RenderWindow* window, SpriteManager* spriteManager, SoundManager* soundManager)
	: m_window(window), m_spritemanager(spriteManager), m_soundManager(soundManager)
{
	this->m_chessboard = new Chessboard(this->m_window, this->m_spritemanager, this->m_soundManager);
}
OfflineMode::~OfflineMode()
{
	delete this->m_chessboard;
}
/// //////////////////////////////////////////////////////////////////////