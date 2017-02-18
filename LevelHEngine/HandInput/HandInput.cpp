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
	if (isxdigit(str[0]) && str[strspn(str, "0123456789abcdefABCDEF")] == 0)
	{
		number = strtol(str, NULL, 16);
		std::cout << "Array index " << number << "\n";
	}
	else
	{
		std::cout << "Not a valid Hex value! setting to 0\n";
		return angles[0];
	}

	if (number > 1023)
	{
		std::cout << "Array index larger than array size! setting to 1023.\n";
		return angles[1023];
	}

	return angles[number];
}