#pragma once
#include <Application/core/Application.hpp>
#include <Application/core/Camera.h>
#include "Block.hpp"

typedef Application::Key Key;

namespace app
{
	class ApplicationContent
	{
		public:
			VertexArrayObject VAO;
			Shader shader;
			Texture dirt;
			Camera* camera;

			void InitializeContent(ApplicationData data)
			{
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_POLYGON_MODE);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

				this->data = data;

				//Pt Sud => z > 0

				GLfloat vertices[] =
				{
					//Nord
					 0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					 0.5f,-0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					-0.5f,-0.5f,-0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					-0.5f, 0.5f,-0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,

					//Sud
					 0.5f, 0.5f, 0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					 0.5f,-0.5f, 0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					-0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					-0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f, 

					//Vest
					-0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					-0.5f,-0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					-0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					-0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,

					//Est
					 0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					 0.5f,-0.5f,-0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					 0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					 0.5f, 0.5f, 0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,

					 //Sus
					 0.5f, 0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					 0.5f, 0.5f, 0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					-0.5f, 0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					-0.5f, 0.5f,-0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,

					//Jos
					 0.5f,-0.5f,-0.5f,		1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
					 0.5f,-0.5f, 0.5f,		0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
					-0.5f,-0.5f, 0.5f,		0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
					-0.5f,-0.5f,-0.5f,		1.0f, 1.0f, 1.0f,		0.0f, 1.0f,
				};
				GLuint indices[] =
				{
					//Nord
					0,1,3,
					1,2,3,

					//Sud
					5,6,7,
					4,5,7,

					//Vest
					8,9,11,
					9,10,11,

					//Est
					12,13,15,
					13,14,15,

					//Sus
					16,17,19,
					17,18,19,

					//Jos
					20,21,23,
					21,22,23
				};

				VAO.Bind();
				VertexBufferObject VBO(sizeof(vertices), vertices);
				VBO.Bind();
				ElementBufferObject EBO(sizeof(indices), indices);
				EBO.Bind();

				VAO.Link(VBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)(0 * sizeof(float)));
				VAO.Link(VBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
				VAO.Link(VBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

				VBO.Unbind();
				VAO.Unbind();

				shader.OpenFiles("./resources/VertexShader.glsl", "./resources/FragmentShader.glsl");

				dirt.CreateTexture("./resources/dirt.png");
				dirt.Bind();
				dirt.TextureUnit(shader, "tex");
				dirt.Unbind();

				camera = new Camera(data.WindowWidth, data.WindowHeight, glm::vec3(0, 0, 1));
			}

			void UpdateContent()
			{
				camera->Inputs(data.window);
				camera->Matrix(90.0f, 0.1f, 100.0f, shader.ID, "camera");

				shader.Activate();
				dirt.Bind();
				VAO.Bind();
				glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

				if(glfwGetKey(data.window, Key::Key_P) == GLFW_PRESS)
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				if (glfwGetKey(data.window, Key::Key_L) == GLFW_PRESS)
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}

			void DeleteContent()
			{
				VAO.Delete();
				shader.Delete();
				delete camera;
			}

		private:
			ApplicationData data;
	};
}