#pragma once
#include "Elevator.h"
#include <set>

#define MAX_FLOOR_NUM = 16
#define MIN_FLOOR_NUM = -1

struct ElevatorRequest {
	enum RequestType
	{
		ELEV_REQUEST_CALL_IN = 0,
		ELEV_REQUEST_SET_DESTINATION,
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
	void sendRequest(ElevatorRequest newRequest);

private:
	std::set<Elevator*> m_elevators;
};

