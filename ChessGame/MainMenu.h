#pragma once

#include "SpriteManager.h"
#include "SoundManager.h"
#include "Button.h"

enum class MainMenuState
{
	MainMenu = 0,
	SettingsMenu
};

class MainMenu
{
public:
	// Run the Main Menu
	int runMainMenu();

	MainMenu(RenderWindow* window, Event* event);
	~MainMenu();

private:
	// Window
	RenderWindow* m_window;
	Event* m_event;
	// Assets
	SpriteManager* m_spriteManager;
	SoundManager* m_soundManager;
	void initAssets();
	// Buttons
	int m_numberOfMainMenuButtons;
	int m_numberOfSettingMenuButtons;
	Button* m_mainMenuButtons;
	Button* m_settingsMenuButtons;
	void initButtons();

	// Menu variables
	bool m_exitMainMenu;
	MainMenuState  m_mainMenuState;

	// MainMenu loop
	void handleEvents();
	void update();
	void render();

	// Exit from the Main Menu
	void exitMainMenu(int code);

	// Main menu
	void updateMainMenu();
	void renderMainMenu();

	// Setting menu
	void updateSettingMenu();
	void renderSettingMenu();
};