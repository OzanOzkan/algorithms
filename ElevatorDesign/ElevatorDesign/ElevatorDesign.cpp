// ElevatorDesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ElevatorController.h"
#include <iostream>

int main()
{
	int a;

	ElevatorController* elevatorController = new ElevatorController();
	elevatorController->addElevator();

	std::cout << "Elevator Current Floor: " 
		<< elevatorController->getElevatorCurrentFloor(0) << std::endl;

	ElevatorRequest newRequest;
	newRequest.destinationFloor = 10;
	newRequest.requestType = ElevatorRequest::ELEV_REQUEST_SET_DESTINATION;

	if (elevatorController->sendRequest(newRequest))
	{
		std::cout << "Request sent to elevator." << std::endl;

		std::cout << "Elevator Current Floor: " 
			<< elevatorController->getElevatorCurrentFloor(0) << std::endl;
	}

	std::cin >> a;

    return 0;
}

