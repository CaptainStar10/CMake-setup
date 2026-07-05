#include <Application/core/Application.hpp>

#include "header/Game.hpp"

int main()
{
	Application _Application{};
	app::ApplicationContent _Application_Content{};
	_Application_Content.InitializeContent(_Application.data);

	while (!glfwWindowShouldClose(_Application.data.window)) 
	{
		glfwSwapBuffers(_Application.data.window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		_Application_Content.UpdateContent();

		_Application.ProcessInput();
	}
	_Application_Content.DeleteContent();
	_Application.~Application();
	return 0;
}
