#include "Window.h"
#include "Log.h"
#include "Input/InputLayer.h"

Window* Window::createWindow(int width, int height, const char* title) {
	// Initializate glfw
	TAIL_TRACE("Initiating GLFW");
	if (!glfwInit()) {
		TAIL_CRITICAL("Failed to initializate GLFW!");
		return nullptr;
	}

	// Set error callback
	glfwSetErrorCallback(Window::error_callback);

	// Set minimum OpenGL version to 3.0
	TAIL_TRACE("Minimum version OpenGL 3.0");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	// Create GLFW window
	TAIL_TRACE("Creating GLFW window");
	auto* m_windowPointer = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!m_windowPointer) {
		TAIL_CRITICAL("Failed to create GLFW window!");
		return nullptr;
	}

	// Load OpenGL with GLAD
	TAIL_TRACE("Initiating OpenGL with GLAD");
	glfwMakeContextCurrent(m_windowPointer);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);

	// Create Window object
	Window* window = new Window(m_windowPointer);

	return window;
}

void Window::destroyWindow(Window* window) {
	TAIL_TRACE("Destroying GLFW window");
	glfwDestroyWindow(window->m_windowPointer);
	TAIL_TRACE("Terminating GLFW");
	glfwTerminate();
}

Window::Window(GLFWwindow* windowPointer) {
	m_windowPointer = windowPointer;
	InputLayer::setCallbacks(m_windowPointer);
}

Window::~Window() {

}

void Window::Run() {
	while (!glfwWindowShouldClose(this->m_windowPointer)) {
		// Render
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		glfwSwapBuffers(this->m_windowPointer);
		glfwPollEvents();
	}
}

void Window::error_callback(int error, const char* desc) {
	TAIL_ERROR(desc);
}