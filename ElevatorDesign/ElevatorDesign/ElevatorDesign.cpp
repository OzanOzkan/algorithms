// ElevatorDesign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ElevatorController.h"
#include <iostream>

int main()
{
	ElevatorController* elevatorController = new ElevatorController();
	elevatorController->addElevator();

    return 0;
}

