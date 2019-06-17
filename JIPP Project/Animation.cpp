#include "Animation.h"

Animation::Animation(){}

Animation::~Animation() {}


////////////////WALKING OR RUNNING
PlayerMoveAnimation::PlayerMoveAnimation(sf::Texture * Texture)
{
	totalTime = 0.f;
	frames.push_back({ 44, 23, 100, 100 });
	frames.push_back({ 129, 23, 100, 100 });
	frames.push_back({ 214, 23, 100, 100 });
	frames.push_back({ 299, 23, 100, 100 });
	frames.push_back({ 384, 23, 100, 100 });
	frames.push_back({ 469, 23, 100, 100 });
	frames.push_back({ 556, 23, 100, 100 });
	frames.push_back({ 647, 23, 100, 100 });
	frames.push_back({ 750, 23, 100, 100 });
	frames.push_back({ 864, 23, 100, 100 });
	frames.push_back({ 124, 125, 100, 100 });
	frames.push_back({ 239, 125, 100, 100 });
	frames.push_back({ 350, 125, 100, 100 });
	frames.push_back({ 453, 125, 100, 100 });
	frames.push_back({ 547, 125, 100, 100 });
	frames.push_back({ 633, 125, 100, 100 });
	frames.push_back({ 718, 125, 100, 100 });
	frames.push_back({ 803, 125, 100, 100 });
}

void PlayerMoveAnimation::Update(float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage++;
		if (currentImage > 17)
			currentImage = 0;
	}
	uvRect = frames.at(currentImage);
}

void PlayerMoveAnimation::setSwitchTime(float switchTime)
{
	this->switchTime = switchTime;
}

///////////////WALKING OR RUNNING
PlayerIdleAnimation::PlayerIdleAnimation(sf::Texture * Texture)
{
	totalTime = 0.f;
	frames.push_back({ 26, 26, 78, 100 });
	frames.push_back({ 107, 26, 78, 100 });
	frames.push_back({ 189, 26, 78, 100 });
	frames.push_back({ 270, 26, 78, 100 });
	frames.push_back({ 351, 26, 78, 100 });
	frames.push_back({ 433, 26, 78, 100 });
	frames.push_back({ 514, 26, 78, 100 });
	frames.push_back({ 596, 26, 78, 100 });
	frames.push_back({ 677, 26, 78, 100 });
	frames.push_back({ 758, 26, 78, 100 });
	frames.push_back({ 840, 26, 78, 100 });
	frames.push_back({ 921, 26, 78, 100 });
}

void PlayerIdleAnimation::Update(float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage++;
		if (currentImage > 11)
			currentImage = 0;
	}
	uvRect = frames.at(currentImage);
}

///////////////DEATH
PlayerDeathAnimation::PlayerDeathAnimation(sf::Texture * Texture)
{
	totalTime = 0.f;
	frames.push_back({  30, 9, 100, 100 });
	frames.push_back({ 117, 9, 100, 100 });
	frames.push_back({ 203, 9, 100, 100 });
	frames.push_back({ 289, 9, 100, 100 });
	frames.push_back({ 376, 9, 100, 100 });
}

bool PlayerDeathAnimation::Update(float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage++;
		if (currentImage > 4)
			currentImage = 4;
		return true;
	}
	uvRect = frames.at(currentImage);
	return false;
}

CoinAnimation::CoinAnimation(sf::Texture * Texture)
{
	totalTime = 0.f;
	frames.push_back({34, 0, 64, 128});
	frames.push_back({116, 0, 64, 128});
	frames.push_back({191, 0, 64, 128});
	frames.push_back({261, 0, 64, 128});
	frames.push_back({324, 0, 64, 128});
	frames.push_back({381, 0, 64, 128});
	frames.push_back({433, 0, 64, 128});
	frames.push_back({484, 0, 60, 128});
	frames.push_back({528, 0, 54, 128});
	frames.push_back({566, 0, 60, 128});
	frames.push_back({612, 0, 64, 128});
	frames.push_back({665, 0, 64, 128});
	frames.push_back({722, 0, 64, 128});
	frames.push_back({785, 0, 64, 128});
	frames.push_back({854, 0, 64, 128});
	frames.push_back({930, 0, 64, 128});
}

void CoinAnimation::Update(float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage++;
		if (currentImage > 15)
			currentImage = 0;
	}
	uvRect = frames.at(currentImage);
}
