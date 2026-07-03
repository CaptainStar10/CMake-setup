#include "core/Application.hpp"

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void app::CreateApplication(app::Application_Data& data)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	data.window = glfwCreateWindow(data.WindowWidth, data.WindowHeight, data.name, NULL, NULL);
	data.monitor = glfwGetPrimaryMonitor();

	glfwMakeContextCurrent(data.window);
	glfwSetFramebufferSizeCallback(data.window, FrameBufferSizeCallback);
	gladLoadGL();
	glEnable(GL_DEPTH_TEST);
}

void app::SwapBuffers(app::Application_Data& data)
{
	glfwSwapBuffers(data.window);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void app::Terminate(app::Application_Data& data)
{
	glfwDestroyWindow(data.window);
	glfwTerminate();
}

bool app::WindowNotClosed(app::Application_Data& data)
{
	return glfwWindowShouldClose(data.window);
}