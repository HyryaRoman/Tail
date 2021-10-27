#include "InputLayer.h"
#include "Log.h"

void InputLayer::setCallbacks(GLFWwindow* window) {
	glfwSetKeyCallback(window, InputLayer::keyCallback);
	glfwSetMouseButtonCallback(window, InputLayer::mouseButtonCallback);
	glfwSetCursorPosCallback(window, InputLayer::cursorPositionCallback);
	glfwSetCursorEnterCallback(window, InputLayer::cursorEnterCallback);
	glfwSetScrollCallback(window, InputLayer::scroolCallback);
	glfwSetDropCallback(window, InputLayer::dropCallback);
}

void InputLayer::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	
}

void InputLayer::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {

}

void InputLayer::cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {

}

void InputLayer::cursorEnterCallback(GLFWwindow* window, int entered) {

}

void InputLayer::scroolCallback(GLFWwindow* window, double xoffset, double yoffset) {

}

void InputLayer::dropCallback(GLFWwindow* window, int path_count, const char* paths[]) {

}