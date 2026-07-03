#include <Application/ImGUI/imgui.h>
#include <Application/ImGUI/imgui_impl_glfw.h>
#include <Application/ImGUI/imgui_impl_opengl3.h>

#include <Application/core/Application.hpp>

#include <Application/core/Camera.h>
#include <Application/core/ElementBufferObject.h>
#include <Application/core/Mesh.h>
#include <Application/core/ShaderClass.h>
#include <Application/core/Texture.h>
#include <Application/core/VertexArrayObject.h>
#include <Application/core/VertexBufferObject.h>

int main()
{
	app::Application_Data Application;
	app::CreateApplication(Application);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(Application.window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	while (!app::WindowNotClosed(Application)) 
	{
		app::SwapBuffers(Application);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Project name GUI window");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	app::Terminate(Application);
	return 0;
}