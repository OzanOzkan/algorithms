#pragma once
class Buttons
{
public:
	enum ButtonState
	{
		BTN_ACTIVE = 0,
		BTN_NOT_ACTIVE,
		BTN_ENUM_EXTENSION
	};

	Buttons();
	~Buttons();

private:
	ButtonState m_eButtonState;
};

