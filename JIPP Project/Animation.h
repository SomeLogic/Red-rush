#pragma once
#include <SFML/Graphics.hpp>

class Animation {
public:
	Animation();
	~Animation();

	virtual void Update(float deltaTime) = 0;
public:
	sf::IntRect uvRect;
private:
	std::vector<sf::IntRect> frames;
	int currentImage = 0;

	float totalTime;
	float switchTime;
};

class PlayerMoveAnimation : public Animation {
public:
	PlayerMoveAnimation(sf::Texture* Texture);
	virtual void Update(float deltaTime);
	void setSwitchTime(float switchTime);
public:
	sf::IntRect uvRect;
private:
	std::vector<sf::IntRect> frames;
	int currentImage = 0;

	float totalTime;
	float switchTime = 10.f;
};

class PlayerIdleAnimation : public Animation {
public:
	PlayerIdleAnimation(sf::Texture* Texture);
	virtual void Update(float deltaTime);
public:
	sf::IntRect uvRect;
private:
	std::vector<sf::IntRect> frames;
	int currentImage = 0;

	float totalTime;
	float switchTime = .1f;
};

class PlayerDeathAnimation {//: public Animation {
public:
	PlayerDeathAnimation(sf::Texture* Texture);
	bool Update(float deltaTime);
public:
	sf::IntRect uvRect;
private:
	std::vector<sf::IntRect> frames;
	int currentImage = 0;

	float totalTime;
	float switchTime = .02f;
};

class CoinAnimation : public Animation {
public:
	CoinAnimation(sf::Texture* Texture);
	virtual void Update(float deltaTime);
public:
	sf::IntRect uvRect;
private:
	std::vector<sf::IntRect> frames;
	int currentImage = 0;

	float totalTime;
	float switchTime = .05f;
};