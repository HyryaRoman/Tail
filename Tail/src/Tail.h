#pragma once

#include "Window.h"

class Tail {
public:
	Tail();
	~Tail();
	void Run();
private:
	Window* m_window;
};

