#pragma once
#include "Elevator.h"
#include "FloorButton.h"
#include <set>
#include <vector>

const int MAX_FLOOR_NUM = 16;
const int MIN_FLOOR_NUM = -1;

struct ElevatorRequest {
	enum RequestType
	{
		ELEV_REQUEST_CALL_IN = 0,
		ELEV_REQUEST_SET_DESTINATION,
		ELEV_REQUEST_OPEN_DOORS,
		ELEV_REQUEST_CLOSE_DOORS,
		ELEV_REQUEST_ENUM_EXTENSION
	};

	int destinationFloor;
	RequestType requestType;
};

class ElevatorController
{
public:
	ElevatorController();
	~ElevatorController();

	void addElevator();
	bool sendRequest(ElevatorRequest newRequest);
	int getElevatorCurrentFloor(int elevatorID);

private:
	// Used 'typedef' in following declarations for learning purposes.
	// TODO: Perhaps I should use 'map' instead of 'set' in order to get O1 access.
	typedef std::set<Elevator*> Elevators;
	Elevators m_elevators;

	typedef std::vector<FloorButton*> FloorButtons;
	FloorButtons m_floorButtons;
};

