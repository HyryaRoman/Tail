#pragma once

#include <glad/gl.h>
#include <GLFW/glfw3.h>

class Window {
public:
	Window(GLFWwindow* windowPointer);
	~Window();
	void Run();
	static Window* createWindow(int width, int height, const char* title);
	static void destroyWindow(Window* window);
private:
	GLFWwindow* m_windowPointer = nullptr;
	static void error_callback(int error, const char* desc);
};