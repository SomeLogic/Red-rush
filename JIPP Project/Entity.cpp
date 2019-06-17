#include "Entity.h"
/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

Entity::Entity()
{
}


Entity::~Entity()
{
}

Player::Player(b2World& myWorld) {
	//CREATING PLAYER OBJECT IN B2WORLD
	b2BodyDef playerDef;
	playerDef.type = b2_dynamicBody;
	playerDef.position = b2Vec2({ 150.f / SCALE , 500.f / SCALE });

	playerBody = myWorld.CreateBody(&playerDef);
	b2Vec2 vertices[6];
	vertices[0].Set(68.f / 2 / SCALE, -74.f / 2 / SCALE);
	vertices[1].Set(-68.f / 2 / SCALE, -74.f / 2 / SCALE);
	vertices[2].Set(-68.f / 2 / SCALE, 73.f / 2 / SCALE);
	vertices[3].Set(-66.f / 2 / SCALE, 74.f / 2 / SCALE);
	vertices[4].Set(66.f / 2 / SCALE, 74.f / 2 / SCALE);
	vertices[5].Set(68.f / 2 / SCALE, 73.f / 2 / SCALE);

	//Body Shape
	b2PolygonShape shape;
	shape.Set(vertices, 6);

	//Body Fixture
	b2FixtureDef myFixture;
	myFixture.density = 1.f;
	myFixture.friction = 0.7f;
	myFixture.shape = &shape;

	//This is made to avoid collision with bullets
	myFixture.filter.groupIndex = -1;
	playerBody->CreateFixture(&myFixture);

	//Feet Shape
	shape.SetAsBox(68.f / 2 / SCALE, 2.f / 2 / SCALE, b2Vec2(0.f, 74.f / 2 / SCALE), 0);
	//Feet Fixutre
	b2FixtureDef feetFixt1;
	feetFixt1.isSensor = true;
	feetFixt1.shape = &shape;

	b2Fixture* footSensorFixture = playerBody->CreateFixture(&feetFixt1);
	footSensorFixture->SetUserData((void*)"Feet Sensor");


	playerBody->SetUserData((void*)"Player Right");
	playerBody->SetFixedRotation(true);
}

Player::~Player() {}

void Player::Move(b2World &myWorld, int direction, float velocity_x) {
	b2Vec2 velocity = playerBody->GetLinearVelocity();
	switch (direction) {
	case 1: velocity.x = velocity_x;
		this->direction = left;
		playerBody->SetUserData((void*)"Player Left"); break;
	case 2: velocity.x = velocity_x;
		this->direction = right;
		playerBody->SetUserData((void*)"Player Right"); break;
	default: velocity = b2Vec2{ 0.f, 0.f };
	}
	playerBody->SetLinearVelocity(velocity);
}

void Player::Jump(b2World & myWorld) {
	playerBody->SetLinearVelocity(b2Vec2(playerBody->GetLinearVelocity().x, -28.f));
}

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(playerBody->GetPosition().x * SCALE, playerBody->GetPosition().y * SCALE);
}

bool Player::isOnGround(b2World & myWorld, const int numFootContacts) {
	if (numFootContacts < 1)
		return false;
	return true;
}

bool Player::isDead(b2World & myWorld)
{
	for (auto contact = myWorld.GetContactList(); contact != 0; contact = contact->GetNext()) {
		if (contact->GetFixtureA()->GetBody()->GetUserData() == "Spikes" || contact->GetFixtureB()->GetBody()->GetUserData() == "Spikes") {
			return true;
		}
		if (contact->GetFixtureA()->GetBody()->GetUserData() == "Saw" || contact->GetFixtureB()->GetBody()->GetUserData() == "Saw") {
			return true;
		}
	}
	return false;
}

void Player::shoot(b2World & myWorld, const int direction) {
	b2BodyDef bulletDef;
	bulletDef.type = b2_kinematicBody;
	if (direction == left)
		bulletDef.position = b2Vec2({ playerBody->GetPosition().x - 1.f, playerBody->GetPosition().y });
	else
		bulletDef.position = b2Vec2({ playerBody->GetPosition().x + 1.f, playerBody->GetPosition().y });

	b2Body* bulletBody;
	bulletBody = myWorld.CreateBody(&bulletDef);
	bulletBody->SetGravityScale(0.f);
	//Body Shape
	b2CircleShape bulletShape;
	bulletShape.m_radius = 0.5f;
	//Body Fixture
	b2FixtureDef myFixture;
	myFixture.density = 1.f;
	myFixture.shape = &bulletShape;

	//This is made to avoid collision with player
	myFixture.filter.groupIndex = -1;

	bulletBody->CreateFixture(&myFixture);
	bulletBody->SetUserData((void*)"Bullet");
	(direction == left) ? bulletBody->SetLinearVelocity(b2Vec2(-25.f, 0.f)) :
		bulletBody->SetLinearVelocity(b2Vec2(25.f, 0.f));
}

void Player::Stop(b2World & myWorld)
{
	playerBody->SetLinearVelocity(b2Vec2(0.f, playerBody->GetLinearVelocity().y));
}
