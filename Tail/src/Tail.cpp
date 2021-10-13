#include "Tail.h"
#include "Log.h"

Tail::Tail() {
	Log::Init();
	m_window = Window::createWindow(750, 500, "Tail");
	if (!m_window) {
		TAIL_CRITICAL("Failed to create 'Tail' window!");
		// Throw exepcion
	}
}

Tail::~Tail() {
	Window::destroyWindow(m_window);
}

void Tail::Run() {
	TAIL_INFO("Starting Tail");
	m_window->Run();
}