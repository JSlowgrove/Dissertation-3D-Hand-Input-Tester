#include "InThread.h"
#include <string>
#include <iostream>

InThread::InThread(int id, float* inAngle) : id(id), angle(inAngle)
{
	//initalise the varaibles
	input = new HandInput();
	go = true;
	finished = false;

	//start the thread
	thread_ = std::thread(&InThread::threadMain, this);
}

InThread::~InThread()
{
	//delete the input pointer
	delete input;
	//stop the thread
	thread_.join();
}

void InThread::threadMain()
{
	//loop throught the thread to allow data input from the user in the console.
	while (go)
	{
		std::cout << "Enter 10 bit hex value (max 3FF).\n";

		std::string in;
		std::cin >> in;

		//set the angle of the object to the newly calcualated angle.
		*angle = input->getAngle(in.c_str());

		std::cout << "Angle is " << *angle << ".\n\n";
	}
	//set the thread to be finished
	finished = true;
}

void InThread::flagStop()
{
	//tell the loop to stop
	go = false;
}

bool InThread::checkFinished()
{
	return finished;
}