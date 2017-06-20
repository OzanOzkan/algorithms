#include "stdafx.h"
#include "Elevator.h"

Elevator::Elevator()
	: m_elevatorState(ELEV_STATE_READY)
	, m_currentFloor(0)
{
}


Elevator::~Elevator()
{
}

void Elevator::goUp()
{
	// TODO

	m_elevatorState = ELEV_STATE_ENROUTE;
	m_currentFloor++;
	m_elevatorState = ELEV_STATE_READY;
}

void Elevator::goDown()
{
	// TODO

	m_elevatorState = ELEV_STATE_ENROUTE;
	m_currentFloor--;
	m_elevatorState = ELEV_STATE_READY;
}

void Elevator::openDoor()
{
	if (m_elevatorState == ELEV_STATE_DOORS_CLOSED && m_elevatorState == ELEV_STATE_READY)
		m_elevatorState = ELEV_STATE_DOORS_OPEN;
}

void Elevator::closeDoor()
{
	if (m_elevatorState == ELEV_STATE_DOORS_OPEN && m_elevatorState == ELEV_STATE_READY)
		m_elevatorState = ELEV_STATE_DOORS_CLOSED;
}

bool Elevator::initButtons(int buttonCount)
{
	for (int i = 0; i < buttonCount; ++i)
	{
		ElevatorButton* pElevatorButton = new ElevatorButton();
		pElevatorButton->setButtonNumber(i);
		m_elevatorButtons.push_back(pElevatorButton);
	}

	return false;
}
