#pragma once

#include "SpriteManager.h"
#include "SoundManager.h"

class GameMode
{
public:
	// Events
	virtual void handleEvents(Event& eve);
	// Update
	virtual void update();
	// Render
	virtual void render();
};
