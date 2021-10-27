#pragma once
#include <GLFW/glfw3.h>

class InputLayer {
public:
	static void setCallbacks(GLFWwindow* window);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
	static void cursorEnterCallback(GLFWwindow* window, int entered);
	static void scroolCallback(GLFWwindow* window, double xoffset, double yoffset);
	static void dropCallback(GLFWwindow* window, int path_count, const char* paths[]);
};