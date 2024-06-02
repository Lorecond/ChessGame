#pragma once

#include "GameMode.h"
#include "Chessboard.h"

class OfflineMode :
    public GameMode
{
public:
    // Events
    void handleEvents(Event& eve) override;
    // Update
    void update() override;
    // Render
    void render() override;

    OfflineMode(RenderWindow* window, SpriteManager* spriteManager, SoundManager* soundManager);
    ~OfflineMode();

private:
    // Puntatori
    RenderWindow* m_window;
    SpriteManager* m_spritemanager;
    SoundManager* m_soundManager;

    // Scacchiera
    Chessboard* m_chessboard;
};

