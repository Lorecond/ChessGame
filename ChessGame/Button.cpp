#include "Button.h"

bool Button::updateMouseCollision(RenderWindow* window)
{
	if (this->m_button.getGlobalBounds().contains(Vector2f(Mouse::getPosition(*window))))
	{
		this->m_buttonState = ButtonState::MouseOnButton;
		return true;
	}
	else
		this->m_buttonState = ButtonState::NormalState;

	return false;
}
void Button::render(RenderWindow* window)
{
	if (this->m_buttonState == ButtonState::NormalState)
		this->m_button.setOutlineThickness(0.0f);
	else
		this->m_button.setOutlineThickness(1.0f);

	window->draw(this->m_button);
	window->draw(this->m_buttonText);
}

// Public functions
Vector2f Button::getPosition()
{
	return this->m_button.getPosition();
}
Vector2f Button::getSize()
{
	return this->m_button.getSize();
}
void Button::setPosition(Vector2f pos)
{
	this->m_button.setPosition(pos);
	this->m_buttonText.setPosition(pos);
}
void Button::setText(const char* text)
{
	// Update the text of the button
	this->m_buttonText.setString(text);
	// Update the button based on the new text
	this->m_button.setSize(Vector2f(this->m_buttonText.getGlobalBounds().width + 5, this->m_buttonText.getGlobalBounds().height * 2));
}

/// //////////////////////////////////////////////////////////////////////
Button::Button()
{
	this->m_buttonState = ButtonState::NormalState;

	// Set default text
	this->m_font.loadFromFile("Assets/Fonts/Roboto-Black.ttf");
	this->m_buttonText.setFont(this->m_font);
	this->m_buttonText.setCharacterSize(32);
	this->m_buttonText.setFillColor(Color::Black);
	// Set default button
	this->m_button.setFillColor(Color::White);
	this->m_button.setOutlineColor(Color::Red);

	// Set default setting for the button
	this->setText("BUTTON");
	this->setPosition(Vector2f(200, 100));
}
/// //////////////////////////////////////////////////////////////////////