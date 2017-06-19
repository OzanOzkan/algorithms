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

bool ElevatorController::sendRequest(ElevatorRequest newRequest)
{
	// TODO: Check request and apply to a specific elevator.
	if (newRequest.destinationFloor >= MIN_FLOOR_NUM && newRequest.destinationFloor <= MAX_FLOOR_NUM)
	{
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
				return true;
			}
			else
				return false;
		}
	}
	else
	{
		return false;
	}
}

int ElevatorController::getElevatorCurrentFloor(int elevatorID)
{
	for (Elevator* currentElevator : m_elevators)
	{
		if (currentElevator->getID() != elevatorID)
			continue;
		else
			return currentElevator->getCurrentFloor();
	}
}
