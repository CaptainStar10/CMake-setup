#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace app
{
	struct Application_Data 
	{
		GLFWwindow* window;
		GLFWmonitor* monitor;

		unsigned int MonitorWidth = 1920, MonitorHeight = 1080;
		unsigned int WindowWidth = 1000, WindowHeight = 600;

		char name[25] = "Application";
	};

	void CreateApplication(app::Application_Data& data);
	void SwapBuffers(app::Application_Data& data);
	void Terminate(app::Application_Data& data);
	bool WindowNotClosed(app::Application_Data& data);
}