#pragma once
#include <Box2D/Box2D.h>
#include <string>

/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

class Level
{
public:
	Level();
	~Level();
	void CreateGrassCliffLeft(b2World& myWorld, b2Vec2 position);
	void CreateGrassCliffMid(b2World& myWorld, b2Vec2 position);
	void CreateGrassCliffRight(b2World& myWorld, b2Vec2 position);
	void CreateGrassRight(b2World& myWorld, b2Vec2 position);
	void CreateGrassMid(b2World& myWorld, b2Vec2 position);
	void CreateGrassLeft(b2World& myWorld, b2Vec2 position);
	void CreateGrassLone(b2World& myWorld, b2Vec2 position);
	void CreateGrassJoinHillLeft(b2World& myWorld, b2Vec2 position);
	void CreateGrassJoinHillLeft2(b2World& myWorld, b2Vec2 position);
	void CreateGrassJoinHillRight(b2World& myWorld, b2Vec2 position);
	void CreateGrassJoinHillRight2(b2World& myWorld, b2Vec2 position);
	void CreateGrassHillLeft(b2World& myWorld, b2Vec2 position);
	void CreateGrassHillLeft2(b2World& myWorld, b2Vec2 position);
	void CreateGrassHillRight(b2World& myWorld, b2Vec2 position);
	void CreateGrassHillRight2(b2World& myWorld, b2Vec2 position);
	void CreateDirt(b2World& myWorld, b2Vec2 position);
	void CreateDirtDown(b2World& myWorld, b2Vec2 position);
	void CreateSpikes(b2World& myWorld, b2Vec2 position);
	void CreateCoin(b2World& myWorld, b2Vec2 position);
	void CreateAsset40(b2World& myWorld, b2Vec2 position);
	void CreateAsset41(b2World& myWorld, b2Vec2 position);
	void CreateMace(b2World& myWorld, b2Vec2 position);
	void CreateSaw(b2World& myWorld, b2Vec2 position);
};

class Level_1 : public Level {
public:
	void CreateLevel(b2World& myWorld);
};

