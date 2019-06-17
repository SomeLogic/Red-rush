#pragma once
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "myContactListener.h"
#include "Animation.h"

class RenderEngine
{
public:
	b2World myWorld;
	sf::RenderWindow Window;
	myContactListener contactListener;
	sf::View view;
private:
	//Textures must exist while we're using them somewhere
	/*		OBJECTS		*/
	sf::Sprite playerSprite, spikes, coin;
	sf::Texture playerMoveTexture, playerJumpTexture, playerIdleTexture, playerDeathTexture, SpikeTexture, coinTexture;

	//ENEMIES
	sf::Sprite Mace, Saw;
	sf::Texture MaceTexture, SawTexture;

	/*		ENVIRONMENT		*/
	//CLIFFS
	sf::Sprite grassCliffLeft, grassCliffMid, grassCliffRight;
	sf::Texture GrassCliffLeftTexture, GrassCliffMidTexture, GrassCliffRightTexture;
	
	//NORMAL GRASS
	sf::Sprite grassLeft, grassMid, grassRight, grassLone;
	sf::Texture GrassLeftTexture, GrassMidTexture, GrassRightTexture, grassLoneTexture;

	//GRASS TO JOIN HILLS
	sf::Sprite grassJoinHillLeft, grassJoinHillRight, grassJoinHillLeft2, grassJoinHillRight2;
	sf::Texture grassJoinHillLeftTexture, grassJoinHillRightTexture, grassJoinHillLeft2Texture, grassJoinHillRight2Texture;

	//HILLS
	sf::Sprite grassHillLeft, grassHillLeft2, grassHillRight, grassHillRight2;
	sf::Texture grassHillLeftTexture, grassHillLeft2Texture, grassHillRightTexture, grassHillRight2Texture;


	//DIRTS
	sf::Sprite dirt, dirtDown, asset40, asset41;
	sf::Texture DirtTexture, DirtDownTexture, asset40Texture, asset41Texture;;

	/*		BACKGROUND		*/
	sf::Sprite background;
	sf::Texture bgTexture;

	/*		GAME OVER		*/
	sf::Sprite gameOver;
	sf::Texture gameOverTexture;

	/*		WORLD PARAMETERS	 */
	const float timeStep = 1.f / 60.f;
	int velocityIterations = 10;
	int positionIterations = 3;

	PlayerMoveAnimation playerMoveAnim;
	PlayerIdleAnimation playerIdleAnim;
	PlayerDeathAnimation playerDeathAnim;
	CoinAnimation coinAnim;

	int deathStep = 0;
public:
	RenderEngine();
	~RenderEngine();
	void Render(float deltaTime, bool isJumping, bool isDead);
};

