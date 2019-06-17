#pragma once
#include <Box2D/Box2D.h>

class myContactListener : public b2ContactListener{
public:
	int numFootContacts = 0;
public:
	myContactListener();
	~myContactListener();
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact);
};

