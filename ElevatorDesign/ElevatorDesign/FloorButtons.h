#pragma once
#include "Buttons.h"
class FloorButtons :
	public Buttons
{
public:
	enum ButtonType
	{
		FLOOR_BTN_TYPE_UP = 0,
		FLOOR_BTN_TYPE_DOWN,
		FLOOR_BNT_TYPE_ENUM_EXTENSION
	};

	FloorButtons();
	~FloorButtons();

private:
	int m_iButtonID;
	int m_iFloorNumber;
	ButtonType m_eButtonType;
};

