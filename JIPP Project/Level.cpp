#include "Level.h"

Level::Level()
{
}


Level::~Level()
{
}

void Level::CreateGrassCliffLeft(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassCliffLeft");
}

void Level::CreateGrassCliffMid(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassCliffMid");
}

void Level::CreateGrassCliffRight(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassCliffRight");
}

void Level::CreateSpikes(b2World &myWorld, b2Vec2 position) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *spikesBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[3];
	vertices[0].Set(0.f / SCALE, -23.f / SCALE);
	vertices[1].Set(-32.f / SCALE, 23.f / SCALE);
	vertices[2].Set(32.f / SCALE, 23.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 3);

	b2FixtureDef spikesFixtureDef;
	spikesFixtureDef.density = 0.f;
	spikesFixtureDef.friction = 100.f;
	spikesFixtureDef.shape = &Shape;

	spikesBody->CreateFixture(&spikesFixtureDef);

	spikesBody->SetUserData((void*)"Spikes");
}

void Level::CreateGrassRight(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassRight");
}

void Level::CreateGrassMid(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassMid");
}

void Level::CreateGrassLeft(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassLeft");
}

void Level::CreateGrassLone(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[4];
	vertices[0].Set(-64.f / SCALE, -62.f / SCALE);
	vertices[1].Set(-64.f / SCALE, 64.f / SCALE);
	vertices[2].Set(64.f / SCALE, 64.f / SCALE);
	vertices[3].Set(64.f / SCALE, -62.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 4);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	vertices[0].Set(-61.f / SCALE, -64.f / SCALE);
	vertices[1].Set(-61.f / SCALE, -62.f / SCALE);
	vertices[2].Set(61.f / SCALE, -62.f / SCALE);
	vertices[3].Set(61.f / SCALE, -64.f / SCALE);
	b2PolygonShape frictionShape;
	frictionShape.Set(vertices, 4);

	b2FixtureDef frictionFixt;
	frictionFixt.friction = 0.7f;
	frictionFixt.density = 0.f;
	frictionFixt.shape = &frictionShape;

	groundBody->CreateFixture(&groundFixtureDef);
	groundBody->CreateFixture(&frictionFixt);
	groundBody->SetUserData((void*)"GrassLone");
}

void Level::CreateGrassJoinHillLeft(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassJoinHillLeft");
}

void Level::CreateGrassJoinHillLeft2(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassJoinHillLeft2");
}

void Level::CreateGrassJoinHillRight(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassJoinHillRight");
}

void Level::CreateGrassJoinHillRight2(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassJoinHillRight2");
}

void Level::CreateGrassHillLeft(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[3];
	vertices[0].Set(64.f / SCALE, -64.f / SCALE);
	vertices[1].Set(-64.f / SCALE, 64.f / SCALE);
	vertices[2].Set(64.f / SCALE, 64.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 3);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassHillLeft");
}

void Level::CreateGrassHillLeft2(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassHillLeft2");
}

void Level::CreateGrassHillRight(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[3];
	vertices[0].Set(-64.f / SCALE, -64.f / SCALE);
	vertices[1].Set(-64.f / SCALE, 64.f / SCALE);
	vertices[2].Set(64.f / SCALE, 64.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 3);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassHillRight");
}

void Level::CreateGrassHillRight2(b2World & myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.7f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"GrassHillRight2");
}

void Level::CreateDirt(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"Dirt");
}

void Level::CreateCoin(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_kinematicBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *coinBody = myWorld.CreateBody(&bodyDef);
	coinBody->SetGravityScale(0.f);

	b2PolygonShape Shape;
	Shape.SetAsBox(32.f / SCALE, 32.f / SCALE);

	b2FixtureDef myFixtureDef;
	myFixtureDef.friction = 0.f;
	myFixtureDef.density = 0.f;
	myFixtureDef.shape = &Shape;
	myFixtureDef.filter.groupIndex = -1;

	coinBody->CreateFixture(&myFixtureDef);

	coinBody->SetUserData((void*)"Coin");
}

void Level::CreateDirtDown(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(64.f / SCALE, 64.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"DirtDown");
}

void Level::CreateAsset40(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[3];
	vertices[0].Set(64.f / SCALE, -64.f / SCALE);
	vertices[1].Set(-64.f / SCALE, -64.f / SCALE);
	vertices[2].Set(64.f / SCALE, 64.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 3);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"Asset 40");
}

void Level::CreateAsset41(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2Vec2 vertices[3];
	vertices[0].Set(64.f / SCALE, -64.f / SCALE);
	vertices[1].Set(-64.f / SCALE, -64.f / SCALE);
	vertices[2].Set(-64.f / SCALE, 64.f / SCALE);
	b2PolygonShape Shape;
	Shape.Set(vertices, 3);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);

	groundBody->SetUserData((void*)"Asset 41");
}

void Level::CreateMace(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *groundBody = myWorld.CreateBody(&bodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(63.f / SCALE, 63.f / SCALE);

	b2FixtureDef groundFixtureDef;
	groundFixtureDef.friction = 0.f;
	groundFixtureDef.density = 0.f;
	groundFixtureDef.shape = &Shape;

	groundBody->CreateFixture(&groundFixtureDef);
	groundBody->SetGravityScale(-1.f);
	groundBody->SetUserData((void*)"Mace");
}

void Level::CreateSaw(b2World& myWorld, b2Vec2 position)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_kinematicBody;
	bodyDef.position = b2Vec2(position.x / SCALE, position.y / SCALE);
	b2Body *sawBody = myWorld.CreateBody(&bodyDef);

	b2CircleShape sawShape;
	sawShape.m_radius = 64.f / SCALE;

	b2FixtureDef sawFixtureDef;
	sawFixtureDef.friction = 100.f;
	sawFixtureDef.density = 0.f;
	sawFixtureDef.shape = &sawShape;

	sawBody->SetAngularVelocity(-10.f);

	sawBody->CreateFixture(&sawFixtureDef);
	sawBody->SetUserData((void*)"Saw");
}

void Level_1::CreateLevel(b2World & myWorld) {
	CreateSpikes(myWorld, b2Vec2(500.f, 641.f));
	CreateSpikes(myWorld, b2Vec2(564.f, 641.f));
	CreateSpikes(myWorld, b2Vec2(628.f, 641.f));

	CreateGrassLeft(myWorld, b2Vec2(0.f, 728.f));
	for (float i = 128; i <= 1024.f; i += 128.f) {
		CreateGrassMid(myWorld, b2Vec2(i, 728.f));
	}
	for (float i = 2304; i <= 9216.f; i += 128.f) {
		if (i >= 3456.f && i <= 3712.f) {
			for (float j = 3456.f; j < 3840.f; j += 64.f) {
				CreateSpikes(myWorld, b2Vec2(j - 32.f, 641.f));
			}
		}
		else CreateGrassMid(myWorld, b2Vec2(i, 600));
	}
	for (float i = -1184; i < -64.f; i += 64.f) {
		CreateSpikes(myWorld, b2Vec2(i, 769.f));
	}
	for (float i = -1536; i <= 9216.f; i += 128.f) {
		if(i < -1152) CreateDirt(myWorld, b2Vec2(i, 728.f));
		if(i < 0.f)  CreateGrassMid(myWorld, b2Vec2(i, 856.f));
		else CreateDirt(myWorld, b2Vec2(i, 856.f));
	}
	for (float i = 1408; i <= 9216.f; i += 128) {
		if (i >= 3456.f && i <= 3712.f)
			for (float j = 3456.f; j < 3840.f; j += 64.f) {
			CreateGrassMid(myWorld, b2Vec2(i, 728.f));
		}
		else CreateDirt(myWorld, b2Vec2(i, 728.f));
	}
	for (float i = 1536; i <= 2048; i += 128) {
		CreateDirt(myWorld, b2Vec2(i, 600));
	}
	for (float i = 1664; i <= 1920; i += 128) {
		CreateDirt(myWorld, b2Vec2(i, 472.f));
	}
	CreateGrassJoinHillLeft(myWorld, b2Vec2(1664.f, 344.f));
	CreateGrassMid(myWorld, b2Vec2(1792.f, 344.f));
	CreateGrassJoinHillRight(myWorld, b2Vec2(1920, 344.f));
	for (float i = -1536; i <= 2944.f; i += 128.f) {
		CreateDirtDown(myWorld, b2Vec2(i, 984.f));
	}
	CreateGrassJoinHillRight2(myWorld, b2Vec2(1152.f, 728.f));
	for (int i = 0; i < 3; i++) {
		CreateGrassHillLeft(myWorld, b2Vec2(1280.f + (i * 128.f), 600.f - (i * 128.f)));
		CreateGrassHillLeft2(myWorld, b2Vec2(1280.f + (i * 128.f), 728.f - (i * 128.f)));
	}
	for (int i = 1; i >= 0; i--) {
		CreateGrassHillRight(myWorld, b2Vec2(2048.f + (i * 128.f), 344.f + (i * 128.f)));
		CreateGrassHillRight2(myWorld, b2Vec2(2048.f + (i * 128.f), 472.f + (i * 128.f)));
	}
	CreateCoin(myWorld, b2Vec2(2304.f, 88.f));
	CreateGrassLone(myWorld, b2Vec2(2304.f, 216.f));

	for (float i = 3968; i <= 9088.f; i += 128.f) {
		CreateDirt(myWorld, b2Vec2(i, -424.f));
		if (i >= 4096.f && i <= 8960.f) CreateDirt(myWorld, b2Vec2(i, -296.f));
		if (i >= 4224.f && i <= 8832.f) CreateDirt(myWorld, b2Vec2(i, -168.f));
		if (i >= 4352.f && i <= 8704.f && i != 4480.f) CreateDirt(myWorld, b2Vec2(i, -40.f));
		if (i >= 4608.f && i <= 8576.f) CreateDirtDown(myWorld, b2Vec2(i, 88.f));
	}
	for (int i = 0; i < 5; i++) {
		CreateAsset40(myWorld, b2Vec2(3840.f + i * 128.f, -424.f + i * 128.f));
	}
	for (int i = 0; i < 5; i++) {
		CreateAsset41(myWorld, b2Vec2(8704 + (i * 128), 88 - (i * 128)));
	}
	CreateMace(myWorld, b2Vec2(4480, -40));
	CreateSaw(myWorld, b2Vec2(5248, 536));
	//CreateSaw(myWorld, b2Vec2(5376, 536));
}
