#pragma once

#include "MainMenu.h"
#include "SpriteManager.h"
#include "SoundManager.h"
#include "OfflineMode.h"

enum class GameState
{
	RUNNING = 0,
	MENU
};

class Game
{
public:
	const bool running() const;

	// Update
	void update();
	// Render
	void render();

	Game();
	virtual ~Game();

private:
	// Window
	RenderWindow* m_window;
	VideoMode m_videoMode;
	Event m_event;
	void initWindow();

	// Assets
	SpriteManager* m_spritemanager;
	SoundManager* m_soundManager;
	void initAssets();

	// Main Menu
	MainMenu* m_mainMenu;
	void initMainMenu();

	// Game Mode
	GameMode* m_currentGameMode;

	// Update functions
	void handleEvents();

	// Render functions
};