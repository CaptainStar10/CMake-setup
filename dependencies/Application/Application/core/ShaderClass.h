#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cerrno>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	unsigned int ID;
	Shader() = default;
	Shader(const char* VertexPath, const char* FragmentPath);
	void OpenFiles(const char* VertexPath, const char* FragmentPath);
	void Activate();
	void Delete();

protected:
	void GetPath(const char* VertexPath, const char* FragmentPath);
};
