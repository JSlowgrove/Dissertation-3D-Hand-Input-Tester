#pragma once

///The number for look up for conversion (360 / 1023)
#define convNum 360.0f / 1023.0f

/**
@brief The class to handle the data input from the hand.
*/
class HandInput
{
public:
	/**
	@brief Constructs the class.
	*/
	HandInput();

	/**
	@brief Destructs the class.
	*/
	~HandInput();

	/**
	@brief A function to get the angle from the angle array using the data sent from the hand.
	@param str The data recived from the hand.
	@returns The translated angle.
	*/
	float getAngle(const char str[]);
private:
	/// A float array for the input angles
	float angles[1024];
};