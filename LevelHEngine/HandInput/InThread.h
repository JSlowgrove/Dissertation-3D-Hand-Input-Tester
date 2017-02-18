#pragma once
#include <thread>
#include "HandInput.h"

class InThread 
{
public:
	InThread(int id, float* inAngle);
	~InThread();
	void flagStop();
	bool checkFinished();
private:
	int id;
	float* angle;
	bool go, finished;
	HandInput* input;
	std::thread thread_;
	void threadMain();
};