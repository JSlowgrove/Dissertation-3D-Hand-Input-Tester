#include "InThread.h"
#include <string>
#include <iostream>

InThread::InThread(int id, float* inAngle) : id(id), angle(inAngle)
{
	input = new HandInput();
	go = true;
	finished = false;
	thread_ = std::thread(&InThread::threadMain, this);
}

InThread::~InThread()
{
	delete input;
	thread_.join();
}

void InThread::threadMain()
{
	while (go)
	{
		std::cout << "Enter 10 bit hex value (max 3FF).\n";

		std::string in;
		std::cin >> in;

		*angle = input->getAngle(in.c_str());

		std::cout << "Angle is " << *angle << ".\n\n";
	}
	finished = true;
}

void InThread::flagStop()
{
	go = false;
}

bool InThread::checkFinished()
{
	return finished;
}