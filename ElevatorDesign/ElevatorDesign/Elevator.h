#pragma once
class Elevator
{
public:
	enum ElevatorState
	{
		ELEV_STATE_READY = 0,
		ELEV_STATE_UNAVAILABLE,
		ELEV_STATE_ENROUTE,
		ELEV_STATE_EMERGENCY,
		ELEV_STATE_DOORS_OPEN,
		ELEV_STATE_DOORS_CLOSED,
		ELEV_STATE_ENUM_EXTENSION
	};

	Elevator();
	~Elevator();

	void setElevatorState(ElevatorState newState) { m_elevatorState = newState; }
	ElevatorState getElevatorState() { return m_elevatorState; }

	int getCurrentFloor() { return m_currentFloor; }

	void setID(int newID) { m_elevatorID = newID; }

	void goUp();
	void goDown();
	void openDoor();
	void closeDoor();

private:
	int m_elevatorID;
	ElevatorState m_elevatorState;
	int m_currentFloor;
};

