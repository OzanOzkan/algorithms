// ITOA
// Ozan Ozkan - 08/04/2017

#include "stdafx.h"
#include <iostream>

class ItoStr
{
public:
	ItoStr()
	{
	}

	void itostr(int number, char* returnVal)
	{
		int reminder;
		int i = 0;

		while (number != 0)
		{
			reminder = number % 10;
			if (reminder > 9)
				returnVal[i++] = (reminder - 10) + 'a';
			else
				returnVal[i++] = reminder + '0';
			;
			number = number / 10;
		}

		returnVal[i] = '\0';

		reverse(returnVal, i);
	}

private:
	void reverse(char input[], int length)
	{
		int i = 0;
		char tempVal[100];
		
		while (i < length)
		{
			tempVal[i] = input[(length-1) - i];
			i++;
		}

		tempVal[i] = '\0';

		input = tempVal;
	}
};