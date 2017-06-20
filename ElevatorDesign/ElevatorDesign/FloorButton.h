#pragma once
#include "Button.h"

class FloorButton :
	public Button
{
public:
	enum ButtonType
	{
		FLOOR_BTN_TYPE_UP = 0,
		FLOOR_BTN_TYPE_DOWN,
		FLOOR_BNT_TYPE_ENUM_EXTENSION
	};

	FloorButton();
	~FloorButton();

private:
	int m_iButtonID;
	int m_iFloorNumber;
	ButtonType m_eButtonType;
};

