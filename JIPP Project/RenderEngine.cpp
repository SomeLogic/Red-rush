#include "RenderEngine.h"

/** We need this to easily convert between pixel and real-world coordinates*/
static const float SCALE = 30.f;

RenderEngine::RenderEngine() :
	myWorld(b2Vec2(0.f, 70.f)),
	view(sf::View(sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f))),
	playerMoveAnim(PlayerMoveAnimation(&playerMoveTexture)),
	playerIdleAnim(PlayerIdleAnimation(&playerIdleTexture)),
	playerDeathAnim(PlayerDeathAnimation(&playerDeathTexture)),
	coinAnim(CoinAnimation(&coinTexture))
{
	Window.create(sf::VideoMode(1920, 1080), "Adventure Time", sf::Style::Fullscreen);
	//Window.create(sf::VideoMode(1600, 900), "Adventure Time");
	Window.setKeyRepeatEnabled(false);
	Window.setVerticalSyncEnabled(true);
	Window.setFramerateLimit(0);
	Window.setMouseCursorVisible(false);

	myWorld.SetContactListener(&contactListener);

	/** Prepare textures */
	std::string tilesPath = "Textures\\Platform Game Assets\\Tiles\\png\\128x128";
	/*		ENVIRONMENT		*/
	//CLIFFS
	GrassCliffLeftTexture.loadFromFile(tilesPath + "\\GrassCliffLeft.png");
	GrassCliffMidTexture.loadFromFile(tilesPath + "\\GrassCliffMid.png");
	GrassCliffRightTexture.loadFromFile(tilesPath + "\\GrassCliffRight.png");
	grassCliffMid.setTexture(GrassCliffMidTexture);
	grassCliffLeft.setTexture(GrassCliffLeftTexture);
	grassCliffRight.setTexture(GrassCliffRightTexture);
	
	//NORMAL GRASS
	GrassLeftTexture.loadFromFile(tilesPath + "\\GrassLeft.png");
	GrassMidTexture.loadFromFile(tilesPath + "\\GrassMid.png");
	GrassRightTexture.loadFromFile(tilesPath + "\\GrassRight.png");
	grassLoneTexture.loadFromFile(tilesPath + "\\Grass.png");
	grassMid.setTexture(GrassMidTexture);
	grassLeft.setTexture(GrassLeftTexture);
	grassRight.setTexture(GrassRightTexture);
	grassLone.setTexture(grassLoneTexture);

	//GRASS TO JOINS HILLS
	grassJoinHillLeftTexture.loadFromFile(tilesPath + "\\GrassJoinHillLeft.png");
	grassJoinHillLeft2Texture.loadFromFile(tilesPath + "\\GrassJoinHillLeft2.png");
	grassJoinHillRightTexture.loadFromFile(tilesPath + "\\GrassJoinHillRight.png");
	grassJoinHillRight2Texture.loadFromFile(tilesPath + "\\GrassJoinHillRight2.png");
	grassJoinHillLeft.setTexture(grassJoinHillLeftTexture);
	grassJoinHillLeft2.setTexture(grassJoinHillLeft2Texture);
	grassJoinHillRight.setTexture(grassJoinHillRightTexture);
	grassJoinHillRight2.setTexture(grassJoinHillRight2Texture);

	//HILLS
	grassHillLeftTexture.loadFromFile(tilesPath + "\\GrassHillLeft.png");
	grassHillLeft2Texture.loadFromFile(tilesPath + "\\GrassHillLeft2.png");
	grassHillRightTexture.loadFromFile(tilesPath + "\\GrassHillRight.png");
	grassHillRight2Texture.loadFromFile(tilesPath + "\\GrassHillRight2.png");
	grassHillLeft.setTexture(grassHillLeftTexture);
	grassHillLeft2.setTexture(grassHillLeft2Texture);
	grassHillRight.setTexture(grassHillRightTexture);
	grassHillRight2.setTexture(grassHillRight2Texture);

	//DIRTS
	DirtTexture.loadFromFile(tilesPath + "\\Dirt.png");
	DirtDownTexture.loadFromFile(tilesPath + "\\DirtDown.png");
	asset40Texture.loadFromFile(tilesPath + "\\Asset 40.png");
	asset41Texture.loadFromFile(tilesPath + "\\Asset 41.png");
	asset40.setTexture(asset40Texture);
	asset41.setTexture(asset41Texture);
	dirt.setTexture(DirtTexture);
	dirtDown.setTexture(DirtDownTexture);

	/*		PLAYER		*/
	playerMoveTexture.loadFromFile("Textures\\Platform Game Assets\\Character Animation\\Run\\1x.png");
	playerJumpTexture.loadFromFile("Textures\\Platform Game Assets\\Character Animation\\Jump\\1x.png");
	playerIdleTexture.loadFromFile("Textures\\Platform Game Assets\\Character Animation\\Idle\\1x.png");
	playerDeathTexture.loadFromFile("Textures\\Platform Game Assets\\Character Animation\\Idle\\Blink\\1x.png");
	playerSprite.setTexture(playerMoveTexture);

	/*		OBJECTS		*/
	bgTexture.loadFromFile("Textures\\Platform Game Assets\\Background\\png\\2048x1536\\Background\\Background.png");
	coinTexture.loadFromFile("Textures\\Platform Game Assets\\Coin Animation\\png\\1024x128.png");
	bgTexture.setRepeated(true);
	background.setTexture(bgTexture);
	coin.setTexture(coinTexture);

	//ENEMIES
	MaceTexture.loadFromFile("Textures\\Platform Game Assets\\Enemies\\png\\128x128\\Mac 128.png");
	SpikeTexture.loadFromFile("Textures\\Platform Game Assets\\Enemies\\png\\64x64\\Spike_Up.png");
	SawTexture.loadFromFile("Textures\\Platform Game Assets\\Enemies\\png\\128x128\\Saw.png");
	Mace.setTexture(MaceTexture);
	spikes.setTexture(SpikeTexture);
	Saw.setTexture(SawTexture);

	/*		GAME OVER		*/
	gameOverTexture.loadFromFile("Textures\\GameOver.png");
	gameOver.setTexture(gameOverTexture);
}

RenderEngine::~RenderEngine()
{
}

void RenderEngine::Render(float deltaTime, bool isJumping, bool isDead) {
	myWorld.Step(timeStep, velocityIterations, positionIterations);
	Window.setView(view);

	background.setTextureRect(sf::IntRect(0, 0, 21600, 2048));
	background.setOrigin(2048.f, 1360.f);
	background.setPosition(-1024.f, 768.f);
	Window.draw(background);
	for (auto bodyIt = myWorld.GetBodyList(); bodyIt != 0; bodyIt = bodyIt->GetNext()) {
		if (bodyIt->GetUserData() == "Coin") {
			coinAnim.Update(deltaTime);
			coin.setTextureRect(coinAnim.uvRect);
			coin.setOrigin({ 64.f / 2, 128.f / 2 });
			coin.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			coin.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(coin);
		}
		else if (bodyIt->GetUserData() == "Saw") {
			Saw.setOrigin({ 128.f / 2, 128.f / 2 });
			Saw.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			Saw.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(Saw);
		}
		else if (bodyIt->GetUserData() == "Mace") {
			Mace.setOrigin({ 128.f / 2, 128.f / 2 });
			Mace.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			Mace.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(Mace);
		}
		else if (bodyIt->GetUserData() == "Asset 40") {
			asset40.setOrigin({ 128.f / 2, 128.f / 2 });
			asset40.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			asset40.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(asset40);
		}
		else if (bodyIt->GetUserData() == "Asset 41") {
			asset41.setOrigin({ 128.f / 2, 128.f / 2 });
			asset41.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			asset41.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(asset41);
		}		
		else if (bodyIt->GetUserData() == "GrassLeft") {
			grassLeft.setOrigin({ 128.f / 2, 128.f / 2 });
			grassLeft.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassLeft.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassLeft);
		}
		else if (bodyIt->GetUserData() == "GrassMid") {
			grassMid.setOrigin({ 128.f / 2, 128.f / 2 });
			grassMid.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassMid.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassMid);
		}
		else if (bodyIt->GetUserData() == "GrassRight") {
			grassRight.setOrigin({ 128.f / 2, 128.f / 2 });
			grassRight.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassRight.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassRight);
		}
		else if (bodyIt->GetUserData() == "GrassLone") {
			grassLone.setOrigin({ 128.f / 2, 128.f / 2 });
			grassLone.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassLone.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassLone);
		}
		else if (bodyIt->GetUserData() == "Dirt") {
			dirt.setOrigin({ 128.f / 2, 128.f / 2 });
			dirt.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			dirt.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(dirt);
		}
		else if (bodyIt->GetUserData() == "DirtDown") {
			dirtDown.setOrigin({ 128.f / 2, 128.f / 2 });
			dirtDown.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			dirtDown.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(dirtDown);
		}
		else if (bodyIt->GetUserData() == "GrassJoinHillLeft") {
			grassJoinHillLeft.setOrigin({ 128.f / 2, 128.f / 2 });
			grassJoinHillLeft.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassJoinHillLeft.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassJoinHillLeft);
		}
		else if (bodyIt->GetUserData() == "GrassJoinHillLeft2") {
			grassJoinHillLeft2.setOrigin({ 128.f / 2, 128.f / 2 });
			grassJoinHillLeft2.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassJoinHillLeft2.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassJoinHillLeft2);
		}
		else if (bodyIt->GetUserData() == "GrassJoinHillRight") {
			grassJoinHillRight.setOrigin({ 128.f / 2, 128.f / 2 });
			grassJoinHillRight.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassJoinHillRight.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassJoinHillRight);
		}
		else if (bodyIt->GetUserData() == "GrassJoinHillRight2") {
			grassJoinHillRight2.setOrigin({ 128.f / 2, 128.f / 2 });
			grassJoinHillRight2.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassJoinHillRight2.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassJoinHillRight2);
		}
		else if (bodyIt->GetUserData() == "GrassHillLeft") {
			grassHillLeft.setOrigin({ 128.f / 2, 128.f / 2 });
			grassHillLeft.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassHillLeft.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassHillLeft);
		}
		else if (bodyIt->GetUserData() == "GrassHillLeft2") {
			grassHillLeft2.setOrigin({ 128.f / 2, 128.f / 2 });
			grassHillLeft2.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassHillLeft2.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassHillLeft2);
		}
		else if (bodyIt->GetUserData() == "GrassHillRight") {
			grassHillRight.setOrigin({ 128.f / 2, 128.f / 2 });
			grassHillRight.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassHillRight.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassHillRight);
		}
		else if (bodyIt->GetUserData() == "GrassHillRight2") {
			grassHillRight2.setOrigin({ 128.f / 2, 128.f / 2 });
			grassHillRight2.setPosition(bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE);
			grassHillRight2.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(grassHillRight2);
		}
		//RENDERING PLAYER
		else if (bodyIt->GetUserData() == "Player Right" || bodyIt->GetUserData() == "Player Left") {
			b2Vec2 velocity = bodyIt->GetLinearVelocity();
			float add = 0;
			if (isDead) {
				if(playerDeathAnim.Update(deltaTime)) deathStep++;
				playerSprite.setTexture(playerDeathTexture);
				playerSprite.setTextureRect(playerDeathAnim.uvRect);
				playerSprite.setOrigin({ 100.f / 2, 100.f / 2 });
				if (deathStep == 0) {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE });
					playerSprite.setRotation(180 / b2_pi * bodyIt->GetAngle());
				}
				else if (deathStep == 1) {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y * SCALE) + 10.f });
					if (bodyIt->GetUserData() == "Player Right")
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) + 25);
					else
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) - 25);
				}
				else if (deathStep == 2) {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y * SCALE) + 10.f });
					if (bodyIt->GetUserData() == "Player Right")
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) + 50);
					else
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) - 50);
				}
				else if (deathStep == 3) {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y * SCALE) + 10.f });
					if (bodyIt->GetUserData() == "Player Right")
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) + 75);
					else
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) - 75);
				}
				else if (deathStep >= 4 && deathStep <= 20) {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y * SCALE) + 10.f });
					if (bodyIt->GetUserData() == "Player Right")
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) + 90);
					else
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) - 90);
				}
				else {
					playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y * SCALE) + 10.f });
					if (bodyIt->GetUserData() == "Player Right")
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) + 90);
					else
						playerSprite.setRotation((180 / b2_pi * bodyIt->GetAngle()) - 90);

					gameOver.setPosition((bodyIt->GetPosition().x * SCALE) - 545.f / 2, (bodyIt->GetPosition().y * SCALE) - 350.f);
					gameOver.setScale(0.5, 0.5);
					Window.draw(gameOver);
				}
				
			}
			else
			{
				deathStep = 0;
				if (isJumping == 1) {
					if (velocity.y <= 0.f) {
						playerSprite.setTexture(playerJumpTexture);
						playerSprite.setTextureRect({ 19, 7, 100, 100 });
					}
					else if (velocity.y > -0.f) {
						playerSprite.setTexture(playerJumpTexture);
						playerSprite.setTextureRect({ 134, 7, 100, 100 });
					}
				}
				else if (velocity.x == 0) {
					add = 0.6;
					playerIdleAnim.Update(deltaTime);
					playerSprite.setTexture(playerIdleTexture);
					playerSprite.setTextureRect(playerIdleAnim.uvRect);
				}
				else if (abs(velocity.x) > 16.f) {
					playerMoveAnim.setSwitchTime(0.02f);
					playerMoveAnim.Update(deltaTime);
					playerSprite.setTexture(playerMoveTexture);
					playerSprite.setTextureRect(playerMoveAnim.uvRect);
				}
				else {
					playerMoveAnim.setSwitchTime(0.04f);
					playerMoveAnim.Update(deltaTime);
					playerSprite.setTexture(playerMoveTexture);
					playerSprite.setTextureRect(playerMoveAnim.uvRect);
				}
				if (bodyIt->GetUserData() == "Player Left")
					playerSprite.setScale(sf::Vector2f({ -1, 1 }));
				else
					playerSprite.setScale(sf::Vector2f({ 1, 1 }));

				playerSprite.setOrigin({ 68.f / 2, 74.f / 2 });
				playerSprite.setPosition({ bodyIt->GetPosition().x * SCALE, (bodyIt->GetPosition().y + add) * SCALE });
				playerSprite.setRotation(180 / b2_pi * bodyIt->GetAngle());
			}
			Window.draw(playerSprite);
		}
		//RENDERING SPIKES
		else if (bodyIt->GetUserData() == "Spikes") {
			spikes.setOrigin({ 64.f / 2, 46.f / 2 });
			spikes.setPosition({ bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE });
			spikes.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(spikes);
		}
		else if (bodyIt->GetUserData() == "Bullet") {
			sf::CircleShape bullet(5.f, 20);
			bullet.setFillColor(sf::Color::Black);
			bullet.setOrigin({ 5.f / 2, 5.f / 2 });
			bullet.setPosition({ bodyIt->GetPosition().x * SCALE, bodyIt->GetPosition().y * SCALE });
			bullet.setRotation(180 / b2_pi * bodyIt->GetAngle());
			Window.draw(bullet);
		}
	}
}