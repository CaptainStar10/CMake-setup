#include "core/Application.hpp"

//###############################################################
//					Application initialization
//###############################################################

void FrameBufferCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Application::Application()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	this->data.window = glfwCreateWindow(this->data.WindowWidth, this->data.WindowHeight, this->data.name, NULL, NULL);
	this->data.monitor = glfwGetPrimaryMonitor();

	if (this->data.window == NULL)
	{
		std::cout << "Failed to create GLFW window!\n";
		glfwTerminate();
		return;
	}
	if (this->data.monitor == NULL)
		std::cout << "Failed to create GLFW monitor!\n";

	glfwMakeContextCurrent(this->data.window);
	glfwSetFramebufferSizeCallback(this->data.window, FrameBufferCallback);
	gladLoadGL();
}

Application::~Application()
{
	glfwDestroyWindow(this->data.window);
	glfwTerminate();
}


//###############################################################
//							Application
//###############################################################


void Application::ProcessInput()
{
	if (glfwGetKey(this->data.window, Key::Key_F11) == GLFW_PRESS)
	{
		if (this->data.fullscreen == false)
			glfwSetWindowMonitor(this->data.window, this->data.monitor, 0, 0, this->data.MonitorWidth, this->data.MonitorHeight, 120);
		if (this->data.fullscreen == true)
			glfwSetWindowMonitor(this->data.window, 0, 0, 0, this->data.MonitorWidth, this->data.MonitorHeight, 120);
		this->data.fullscreen = !this->data.fullscreen;
	}
	if (glfwGetKey(this->data.window, Key::Key_P) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(this->data.window, Key::Key_L) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}
