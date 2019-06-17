#include "myContactListener.h"

myContactListener::myContactListener()
{
}


myContactListener::~myContactListener()
{
}

void myContactListener::BeginContact(b2Contact* contact) {
	//check if fixture A was the foot sensor
	void* fixtureUserData = contact->GetFixtureA()->GetUserData();
	if (fixtureUserData == "Feet Sensor")
		numFootContacts++;
	//check if fixture B was the foot sensor
	fixtureUserData = contact->GetFixtureB()->GetUserData();
	if (fixtureUserData == "Feet Sensor")
		numFootContacts++;
}

void myContactListener::EndContact(b2Contact* contact) {
	//check if fixture A was the foot sensor
	void* fixtureUserData = contact->GetFixtureA()->GetUserData();
	if (fixtureUserData == "Feet Sensor")
		numFootContacts--;
	//check if fixture B was the foot sensor
	fixtureUserData = contact->GetFixtureB()->GetUserData();
	if (fixtureUserData == "Feet Sensor")
		numFootContacts--;
}