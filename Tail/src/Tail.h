#pragma once

#include "Window/Window.h"

class Tail {
public:
	Tail();
	~Tail();
	void Run();
private:
	Window* m_window;
	Tail* s_Instance;
};

