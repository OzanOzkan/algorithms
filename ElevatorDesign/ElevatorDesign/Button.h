#pragma once

class Button
{
public:
	enum ButtonState
	{
		BTN_ACTIVE = 0,
		BTN_NOT_ACTIVE,
		BTN_ENUM_EXTENSION
	};

	Button();
	~Button();

private:
	ButtonState m_eButtonState;
};

