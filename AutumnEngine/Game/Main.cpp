#include "../Framework/Application/Application.h"

int main()
{
	srand(time(0));

	// Creates a new instance of "Application" and calls the applications "startApplication" function
	AutumnEngine::Application application = AutumnEngine::Application();
	application.StartApplication();
}