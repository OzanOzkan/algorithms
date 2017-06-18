#include "stdafx.h"
#include "ElevatorController.h"


ElevatorController::ElevatorController()
{
}


ElevatorController::~ElevatorController()
{
}

void ElevatorController::addElevator()
{
	Elevator* newElevator = new Elevator();
	newElevator->setID(m_elevators.size());
	m_elevators.insert(newElevator);
}

void ElevatorController::sendRequest(ElevatorRequest newRequest)
{
	// TODO: Check request and apply to a specific elevator.

	for (Elevator* currentElevator : m_elevators)
	{
		if (currentElevator->getElevatorState() == Elevator::ElevatorState::ELEV_STATE_READY) 
		{
			while (currentElevator->getCurrentFloor() != newRequest.destinationFloor)
			{
				if (currentElevator->getCurrentFloor() > newRequest.destinationFloor)
					currentElevator->goDown();
				else
					currentElevator->goUp();
			}
		}
	}
}
