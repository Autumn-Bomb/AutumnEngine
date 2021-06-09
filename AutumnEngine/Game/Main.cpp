#include "../Framework/Application.h"

int main()
{
	srand(time(NULL));

	// Creates a new instance of "Application" and calls the applications "startApplication" function
	AutumnEngine::Application application = AutumnEngine::Application();
	application.StartApplication();
}