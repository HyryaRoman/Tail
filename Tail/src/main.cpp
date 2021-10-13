#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* desc) {
	fprintf(stderr, "Error: %s\n", desc);
}

int main() {
	if (!glfwInit()) {
		std::cerr << "Failed to initializate glfw!" << std::endl;
		return -1;
	}
	glfwSetErrorCallback(error_callback);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(750, 500, "Tail", NULL, NULL);
	if (!window) {
		std::cerr << "Failed to create window!" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}