#pragma once

#include <thread>
#include "HandInput.h"

/**
@brief The class to handle the data input thread.
*/
class InThread 
{
public:
	/**
	@brief Constructs the thread class.
	@param id The ID of the thread to run
	@param inAngle A pointer to the angle variable to modify with the thread.
	*/
	InThread(int id, float* inAngle);

	/**
	@brief Destructs the thread.
	*/
	~InThread();

	/**
	@brief A function to flag the thread to stop.
	*/
	void flagStop();

	/**
	@brief A function to check if the thread has stopped.
	@returns If the thread has finished.
	*/
	bool checkFinished();

private:
	///The ID of the thread
	int id;
	///A pointer to the angle variable to use with the thread
	float* angle;
	///Booleans for the running thread
	bool go, finished;
	///A pointer to the hand input
	HandInput* input;
	///The actual thread variable
	std::thread thread_;

	/**
	@brief The function that the thread runs.
	*/
	void threadMain();
};