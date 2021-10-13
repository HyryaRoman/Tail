#include "Tail.h"

#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

int main() {
	Tail* tail = new Tail();
	tail->Run();
	delete tail;
}