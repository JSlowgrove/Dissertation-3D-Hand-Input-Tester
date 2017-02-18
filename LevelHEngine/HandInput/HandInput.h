#pragma once

///The number for look up conversion (360 / 1023)
#define convNum 360.0f / 1023.0f

class HandInput
{
public:
	HandInput();
	~HandInput();
	float getAngle(const char str[]);
private:
	float angles[1024];
};