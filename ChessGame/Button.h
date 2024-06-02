#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

enum class ButtonState
{
	NormalState = 0,
	MouseOnButton
};

class Button
{
public:
	bool updateMouseCollision(RenderWindow* window);
	void render(RenderWindow* window);

	// Public functions
	Vector2f getPosition();
	Vector2f getSize();
	void setPosition(Vector2f pos);
	void setText(const char* text);

	Button();

private:
	RectangleShape m_button;
	Text m_buttonText;
	Font m_font;

	ButtonState m_buttonState;
};