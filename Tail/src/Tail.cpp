#include "Tail.h"
#include "Log.h"

Tail::Tail() {
	Tail::s_Instance = this;

	// Initiate spdlog
	Log::Init();
	TAIL_INFO("Initiating Tail");
	m_window = Window::createWindow(750, 500, "Tail");

	if (!m_window) {
		TAIL_CRITICAL("Failed to create window!");
		// Throw exepcion
	}
}

Tail::~Tail() {
	TAIL_INFO("Finishing up");
	Window::destroyWindow(m_window);

	Tail::s_Instance = nullptr;
}

void Tail::Run() {
	TAIL_INFO("Running Tail");
	m_window->Run();
}