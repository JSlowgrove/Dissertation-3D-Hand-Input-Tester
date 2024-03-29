//DISCLAIMER - THIS WAS NOT BUILT FOR THE DISSERTATION

#include <windows.h>
#include "Core/Application.h"
#include "Core/Logging.h"

///Forces the game to run on the NIVDIA GPU, if one is available.
///http://developer.download.nvidia.com/devzone/devcenter/gamegraphics/files/OptimusRenderingPolicies.pdf
extern "C"
{
	_declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
}

int main(int argc, char *argv[])
{
	///Log the time and date the program started
	Logging::logI("Program Started: " + Logging::getCurrentDateAndTime());

	///Initialise the application instance 
	Application::init("C++ 3D Based Data Simulation", Vec2(60, 60), Vec2(640, 480), false, 60.0f);

	///Run the application
	Application::run(argc, argv);

	///Destroy the application
	Application::destroy();

	return 0;
}
