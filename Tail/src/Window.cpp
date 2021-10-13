#include "Window.h"
#include "Log.h"
#include "imgui.h"
#include "ImGui/ImGuiOpenGLRenderer.h"

// Static functions
Window* Window::createWindow(int width, int height, const char* title) {
	// Initializate glfw
	if (!glfwInit()) {
		TAIL_CRITICAL("Failed to initializate GLFW!");
		return nullptr;
	}

	// Set error callback
	glfwSetErrorCallback(Window::error_callback);

	// Set minimum OpenGL version to 3.0
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Create Window object
	Window* window = new Window();

	// Create GLFW window
	window->m_windowPointer = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window->m_windowPointer) {
		TAIL_CRITICAL("Failed to create GLFW window!");
		delete window;
		return nullptr;
	}

	// Load OpenGL with GLAD
	glfwMakeContextCurrent(window->m_windowPointer);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	return window;
}

void Window::destroyWindow(Window* window) {
	glfwDestroyWindow(window->m_windowPointer);
	glfwTerminate();
}

void Window::error_callback(int error, const char* desc) {
	TAIL_ERROR(desc);
}

// Class implementation
Window::Window() {

}

Window::~Window() {

}

void Window::Run() {
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2(750, 500);
	io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;

	ImGui_ImplOpenGL3_Init("#version 130");


	bool show = false;
	while (!glfwWindowShouldClose(this->m_windowPointer)) {
		this->ProcessInput();

		// ImGui stuff

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		if (show) {
			ImGui::ShowDemoWindow(&show);
		}

		{
			ImGui::Begin("My little window");

			ImGui::Text("Hello world!");
			ImGui::Checkbox("Show demo window", &show);

			ImGui::SliderAngle("X", &x);
			ImGui::SameLine();
			ImGui::SliderAngle("Y", &y);
			ImGui::SameLine();
			ImGui::SliderAngle("Z", &z);

			ImGui::Text("Rotation X = %.3f Y = %.3f Z = %.3f", x, y, z);
			ImGui::End();
		}

		glViewport(0, 0, 750, 500);
		ImGui::EndFrame();
		ImGui::Render();

		// Render

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(this->m_windowPointer);
		glfwPollEvents();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui::DestroyContext();
}

void Window::ProcessInput() {

}