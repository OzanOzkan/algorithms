#pragma once
#include "Button.h"

class ElevatorButton :
	public Button
{
public:
	ElevatorButton();
	~ElevatorButton();

	int getButtonNumber() { return m_buttonNumber; }
	void setButtonNumber(int buttonNumber) { m_buttonNumber = buttonNumber; }
	void setButtonState(ButtonState newButtonState) { m_buttonState = newButtonState; }

private:
	int m_buttonNumber;
	ButtonState m_buttonState;
};

