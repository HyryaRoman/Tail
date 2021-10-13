#include "Tail.h"
#include "Log.h"

Tail::Tail() {
	Log::Init();
}

Tail::~Tail() {

}

void Tail::Run() {
	TAIL_INFO("Starting Tail");
}