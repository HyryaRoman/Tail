#include "Window.h"
#include "Log.h"

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

Window::Window() {

}

Window::~Window() {

}

void Window::Run() {
	while (!glfwWindowShouldClose(this->m_windowPointer)) {
		this->ProcessInput();

		// Render
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		glfwSwapBuffers(this->m_windowPointer);
		glfwPollEvents();
	}
}

void Window::ProcessInput() {

}

void Window::error_callback(int error, const char* desc) {
	TAIL_ERROR(desc);
}