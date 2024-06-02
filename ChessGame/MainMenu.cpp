#include "MainMenu.h"

// Public functions
int MainMenu::runMainMenu()
{
	/*
		Start the Main Menu loop
	*/
	while (this->m_window->isOpen() && this->m_exitMainMenu == 0)
	{
		// Update
		this->update();

		// Render
		this->render();
	}
	return this->m_exitMainMenu;
}

/// //////////////////////////////////////////////////////////////////////
MainMenu::MainMenu(RenderWindow* window, Event* event)
	: m_window(window), m_event(event)
{
	/*
		Initialize all the Main Menu variables
	*/
	this->m_exitMainMenu = 0;
	this->m_mainMenuState = MainMenuState::MainMenu;

	this->initButtons();
	this->initAssets();
}
MainMenu::~MainMenu()
{
	/*
		Delete everythings stored in the heap
	*/
	// Assets
	delete this->m_spriteManager;
	delete this->m_soundManager;
	// Buttons
	delete[] this->m_mainMenuButtons;
	delete[] this->m_settingsMenuButtons;
}
/// /////////////////////////////////////////////////////////////////////

// Assets
void MainMenu::initAssets()
{
	this->m_spriteManager = new SpriteManager;
	this->m_soundManager = new SoundManager;

	this->m_spriteManager->initMainMenu();
	this->m_soundManager->initMainMenu();
}
// Buttons
void MainMenu::initButtons()
{
	/*
		Initialize the buttons for all the Menu
	*/
	this->m_numberOfMainMenuButtons = 1;
	this->m_numberOfSettingMenuButtons = 0;
	this->m_mainMenuButtons = new Button[this->m_numberOfMainMenuButtons];
	this->m_settingsMenuButtons = new Button[this->m_numberOfSettingMenuButtons];

	this->m_mainMenuButtons[0].setText("Play");
	this->m_mainMenuButtons[0].setPosition(Vector2f(360 - (this->m_mainMenuButtons[0].getSize().x / 2), 200));
}

// MainMenu loop
void MainMenu::handleEvents()
{
	while (this->m_window->pollEvent(*this->m_event))
	{
		/*
			Look if it need to shut down the window
		*/
		switch (this->m_event->type)
		{
		case Event::Closed:
			this->m_window->close();
			break;
		case Event::KeyPressed:
			if (this->m_event->key.code == Keyboard::Escape)
				this->m_window->close();
			break;
		}

		/*
			Looks for inputs
			Mouse, keyboard ...
		*/
		switch (this->m_event->type)
		{
		case Event::KeyPressed:
			break;
		}
	}
}
void MainMenu::update()
{
	this->handleEvents();

	switch (this->m_mainMenuState)
	{
	case MainMenuState::MainMenu:
		this->updateMainMenu();
		break;

	case MainMenuState::SettingsMenu:
		this->updateSettingMenu();
		break;
	}
}
void MainMenu::render()
{
	this->m_window->clear(Color::Black);

	//Draw
	// Background
	this->m_window->draw(this->m_spriteManager->backgroundSprite);

	switch (this->m_mainMenuState)
	{
	case MainMenuState::MainMenu:
		this->renderMainMenu();
		break;

	case MainMenuState::SettingsMenu:
		this->renderSettingMenu();
		break;
	}

	this->m_window->display();
}

// Private functions
void MainMenu::exitMainMenu(int code)
{
	this->m_exitMainMenu = code;
}

// Main Menu
void MainMenu::updateMainMenu()
{
	/*
		Updates only the Main Menu buttons
	*/
	for (int i = 0; i < this->m_numberOfMainMenuButtons; i++)
	{
		if (this->m_mainMenuButtons[i].updateMouseCollision(this->m_window))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				switch (i)
				{
				case 0:
					this->exitMainMenu(1);
					break;

				default:
					this->m_mainMenuState = MainMenuState::MainMenu;
					break;
				}
			}
		}
	}
}
void MainMenu::renderMainMenu()
{
	/*
		Renders only the Main Menu buttons
	*/
	for (int i = 0; i < this->m_numberOfMainMenuButtons; i++)
	{
		this->m_mainMenuButtons[i].render(this->m_window);
	}
}

// Settings Menu
void MainMenu::updateSettingMenu()
{
	/*
		Updates only the Settings Menu buttons
	*/
	for (int i = 0; i < this->m_numberOfSettingMenuButtons; i++)
	{
		if (this->m_settingsMenuButtons[i].updateMouseCollision(this->m_window))
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				switch (i)
				{
				case 0:
					this->m_mainMenuState = MainMenuState::MainMenu;

				default:
					this->m_mainMenuState = MainMenuState::MainMenu;
					break;
				}
			}
		}
	}
}
void MainMenu::renderSettingMenu()
{
	/*
		Renders only the Settings Menu buttons
	*/
	for (int i = 0; i < this->m_numberOfSettingMenuButtons; i++)
	{
		this->m_settingsMenuButtons->render(this->m_window);
	}
}