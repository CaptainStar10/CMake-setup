#pragma once
#include <map>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

struct ApplicationData
{
	GLFWwindow* window;
	GLFWmonitor* monitor;

	bool fullscreen = false;

	unsigned int MonitorWidth = 1920, MonitorHeight = 1080;
	int WindowWidth = 1000, WindowHeight = 600;

	char name[25] = "Midnight Stream";

	GLfloat deltaTime = 1.0f;
};

class Application
{
	public:
		ApplicationData data;

		Application();
		~Application();

		void ProcessInput();

		enum Key
		{
			Key_A = GLFW_KEY_A,
			Key_B = GLFW_KEY_B,
			Key_C = GLFW_KEY_C,
			Key_D = GLFW_KEY_D,
			Key_E = GLFW_KEY_E,
			Key_F = GLFW_KEY_F,
			Key_G = GLFW_KEY_G,
			Key_H = GLFW_KEY_H,
			Key_I = GLFW_KEY_I,
			Key_J = GLFW_KEY_J,
			Key_K = GLFW_KEY_K,
			Key_L = GLFW_KEY_L,
			Key_M = GLFW_KEY_M,
			Key_N = GLFW_KEY_N,
			Key_O = GLFW_KEY_O,
			Key_P = GLFW_KEY_P,
			Key_Q = GLFW_KEY_Q,
			Key_R = GLFW_KEY_R,
			Key_S = GLFW_KEY_S,
			Key_T = GLFW_KEY_T,
			Key_U = GLFW_KEY_U,
			Key_V = GLFW_KEY_V,
			Key_W = GLFW_KEY_W,
			Key_X = GLFW_KEY_X,
			Key_Y = GLFW_KEY_Y,
			Key_Z = GLFW_KEY_Z,

			Key_F1 = GLFW_KEY_F1,
			Key_F2 = GLFW_KEY_F2,
			Key_F3 = GLFW_KEY_F3,
			Key_F4 = GLFW_KEY_F4,
			Key_F5 = GLFW_KEY_F5,
			Key_F6 = GLFW_KEY_F6,
			Key_F7 = GLFW_KEY_F7,
			Key_F8 = GLFW_KEY_F8,
			Key_F9 = GLFW_KEY_F9,
			Key_F10 = GLFW_KEY_F10,
			Key_F11 = GLFW_KEY_F11,
			Key_F12 = GLFW_KEY_F12,

			Key_1 = GLFW_KEY_1,
			Key_2 = GLFW_KEY_2,
			Key_3 = GLFW_KEY_3,
			Key_4 = GLFW_KEY_4,
			Key_5 = GLFW_KEY_5,
			Key_6 = GLFW_KEY_6,
			Key_7 = GLFW_KEY_7,
			Key_8 = GLFW_KEY_8,
			Key_9 = GLFW_KEY_9,
			Key_0 = GLFW_KEY_0,

			Key_Escape = GLFW_KEY_ESCAPE,
			Key_Space = GLFW_KEY_SPACE,
			Key_LeftShift = GLFW_KEY_LEFT_SHIFT,
			Key_RightShift = GLFW_KEY_RIGHT_SHIFT,
			Key_LeftControl = GLFW_KEY_LEFT_CONTROL,
			Key_RightControl = GLFW_KEY_RIGHT_CONTROL,
		};
		enum MouseButton
		{
			LeftButton = GLFW_MOUSE_BUTTON_LEFT,
			MiddleButton = GLFW_MOUSE_BUTTON_MIDDLE,
			RightButton = GLFW_MOUSE_BUTTON_RIGHT,
		};
		enum ControlerButtons
		{

		};
};
