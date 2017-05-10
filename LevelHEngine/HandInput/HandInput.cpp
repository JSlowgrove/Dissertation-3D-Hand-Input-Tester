#include "HandInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>

HandInput::HandInput()
{
	//initalise the angles array
	for (unsigned int i = 0; i < 1024; i++)
	{
		//calculate the angles to fill the array with
		angles[i] = i * convNum;
	}
}

HandInput::~HandInput()
{
}

float HandInput::getAngle(const char str[])
{
	std::cout << "Passed in Hex " << &str[0] << "\n";
	long int number;

	//convert the data recieve into a hex value and make sure it is valid
	if (isxdigit(str[0]) && str[strspn(str, "0123456789abcdefABCDEF")] == 0)
	{
		number = strtol(str, NULL, 16);
		std::cout << "Array index " << number << "\n";
	}
	else
	{
		//if the number is invalid, output an error but not a crash
		std::cout << "Not a valid Hex value! setting to 0\n";
		return angles[0];
	}

	//make sure the number is not larger than 1023, if so output an error but not a crash
	if (number > 1023)
	{
		std::cout << "Array index larger than array size! setting to 1023.\n";
		return angles[1023];
	}

	return angles[number];
}