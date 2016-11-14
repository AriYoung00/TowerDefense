#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

enum EventType {
	MonsterEvent,
	TileEvent,
	GUIEvent,
	TowerEvent
};

class Event {
	public:
	virtual EventType type(const Event *event) const =0;
	virtual void handle();
	// other generic event-related functions go here. Haven't decided 100% how to structure it yet.
};


#endif
