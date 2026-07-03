#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cerrno>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

struct Shader
{
	unsigned int ID;
	Shader(const char* VertexPath, const char* FragmentPath);
	void Activate();
	void Delete();
};