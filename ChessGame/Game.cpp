#include "Game.h"

const bool Game::running() const
{
	return this->m_window->isOpen();
}

// Update
void Game::update()
{
	this->handleEvents();

	this->m_currentGameMode->update();
}
// Render
void Game::render()
{
	this->m_window->clear(Color::Green);

	//Draw
	this->m_currentGameMode->render();

	this->m_window->display();
}

/// //////////////////////////////////////////////////////////////////////
Game::Game()
{
	/*
		initializers
	*/

	// Window
	this->initWindow();

	// Assets
	this->initAssets();

	// Main Menu
	this->initMainMenu();
}
Game::~Game()
{
	/*
		Delete everythings stored in the heap
	*/

	// Window
	delete this->m_window;
	// Assets
	delete this->m_spritemanager;
	delete this->m_soundManager;
	// Game Mode
	delete this->m_currentGameMode;
	// Main Menu
	delete this->m_mainMenu;
}
/// //////////////////////////////////////////////////////////////////////

// Window
void Game::initWindow()
{
	this->m_videoMode.height = 720;
	this->m_videoMode.width = 720;

	this->m_window = new RenderWindow(this->m_videoMode, "GameEngine", Style::Close);
	this->m_window->setFramerateLimit(60);
}
// Assets
void Game::initAssets()
{
	/*
		Creates the assets used for the game and initialize them
	*/
	this->m_spritemanager = new SpriteManager;
	this->m_soundManager = new SoundManager;

	this->m_spritemanager->initGame();
	this->m_soundManager->initGame();
}
// Main menu
void Game::initMainMenu()
{
	/*
		Delete the current Game Mode and starts the Main Menu and check wich Game Mode has been selected and delete the Main Menu
	*/
	delete this->m_currentGameMode;

	this->m_mainMenu = new MainMenu(this->m_window, &this->m_event);

	switch (this->m_mainMenu->runMainMenu())
	{
	case 0: // None
		break;

	case 1: // Offline Mode
		this->m_currentGameMode = new OfflineMode(this->m_window, this->m_spritemanager, this->m_soundManager);
		break;

	default:
		break;
	}

	delete this->m_mainMenu;
}

// Update functions
void Game::handleEvents()
{
	while (this->m_window->pollEvent(this->m_event))
	{
		/*
			Look if it need to shut down the window
		*/
		switch (this->m_event.type)
		{
		case Event::Closed:
			this->m_window->close();
			break;
		case Event::KeyPressed:
			if (this->m_event.key.code == Keyboard::Escape)
				this->m_window->close();
			break;
		}

		this->m_currentGameMode->handleEvents(this->m_event);
	}
}

// Render functions
