#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Entity.h"
#include "myContactListener.h"

enum Direction { right = 1, left = 2 };

class Entity
{
private:
	int health;
public:
	b2Body* entityBody;
	Direction direction;
public:
	Entity();
	~Entity();
	virtual void Move(b2World & myWorld, int direction, float velocity) = 0;
	virtual void Jump(b2World & myWorld) = 0;
	virtual sf::Vector2f GetPosition() = 0;
};

class Player : public Entity
{
private:
	b2Body *playerBody;
public:
	Direction direction;
	int health = 10;

public:
	Player(b2World& myWorld);
	~Player();
	virtual void Move(b2World & myWorld, int direction, float velocity);
	virtual void Jump(b2World & myWorld);
	virtual sf::Vector2f GetPosition();
	bool isOnGround(b2World& myWorld, const int numFootContacts);
	bool isDead(b2World& myWorld);
	void shoot(b2World& myWorld, const int direction);
	void Stop(b2World& myWorld);
};
