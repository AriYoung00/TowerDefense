#include "Events/eventmanager.h"

// I'm not sure an event manager is necessary. It doesn't seem to have any purpose other than calling
// handle() on events it receives, which we could do in the run loop without adding another layer of
// abstraction.

void EventManager::handle(Event &event) {
	event.handle();
}
