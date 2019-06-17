#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Box2D\Box2D.h>
#include "Entity.h"
#include "myContactListener.h"
#include "Level.h"
#include "Animation.h"
#include "RenderEngine.h"

//PROGRAMMER NOTE
//Fixture is a definition of a shape. Shape alone doesn't define anything, it is defined by fixtures and body definition (includes i.e. type, 
//position), it can be built by one or more fixtures which constructs a shape. Fixtures can be part of visible shape which is impacted 
//by physics but it can as well have fixtures not visible working as sensors to detect if body touches something or not.

int main()
{
	sf::Music backgroundMusic;
	if (!backgroundMusic.openFromFile("Audio\\menu.ogg")) {
		return -1;
	}
	backgroundMusic.play();
		
	RenderEngine renderEngine;

	
	Level_1 currentLevel;
	Player player(renderEngine.myWorld);
	currentLevel.CreateLevel(renderEngine.myWorld);
	sf::Clock clock;
	float deltaTime = 0.f;
	bool isDead = false;
	while (renderEngine.Window.isOpen())
	{
		sf::Event event;
		
		if (player.isDead(renderEngine.myWorld) == true) {
			isDead = true;
			player.Stop(renderEngine.myWorld);
		}
			
		if (!isDead) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				renderEngine.Window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					player.Move(renderEngine.myWorld, 2, 20.f);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					player.Move(renderEngine.myWorld, 1, -20.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				player.Move(renderEngine.myWorld, 2, 13.f);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				player.Move(renderEngine.myWorld, 1, -13.f);
			}
			if (renderEngine.Window.pollEvent(event)) {
				if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Space))
				{
					if (player.isOnGround(renderEngine.myWorld, renderEngine.contactListener.numFootContacts) == true)
						player.Jump(renderEngine.myWorld);
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
					player.shoot(renderEngine.myWorld, player.direction);
				}
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				renderEngine.Window.close();
		}
		bool isJumping = player.isOnGround(renderEngine.myWorld, renderEngine.contactListener.numFootContacts) - 1;
		renderEngine.view.setCenter(player.GetPosition().x, player.GetPosition().y - 250.f);
		deltaTime = clock.restart().asSeconds();
		renderEngine.Render(deltaTime, isJumping, isDead);
		
		renderEngine.Window.display();
	}

	return 0;
}