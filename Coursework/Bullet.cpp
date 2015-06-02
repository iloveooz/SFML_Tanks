#include "Bullet.h"
#include <iostream>
#define OUTSIDE_AREA bulletPos.x > 1920 || bulletPos.x < 0 || bulletPos.y < 0 || bulletPos.y > 1080


Bullet::Bullet(sf::Texture &texture, sf::Vector2f gunPos, float angle, float level, sf::Vector2f tankEnemyPos)
{
	bullet.setTexture(texture);
	bulletTexture.setSmooth(true);
	bullet.setTextureRect(sf::IntRect(435, 1925, 34, 34));
	bullet.setOrigin(17, 17);

	muzzleFlash.setTexture(texture);
	muzzleFlash.setTextureRect(sf::IntRect(469, 1925, 200, 200));
	muzzleFlash.setOrigin(100, 100);
	muzzleFlash.setScale(0.5, 0.5);

	angle = angle * 3.14 / 180;
	bullet.setPosition(gunPos.x + 115 * sin(angle), gunPos.y - 115 * cos(angle));

	dx = (1 + (level / 2)) * sin(angle);
	dy = -(1 + (level / 2)) * cos(angle);

	this->tankEnemyPos = tankEnemyPos;
	this->gunPos = gunPos;
	this->angle = angle;
}


Bullet::~Bullet()
{
}

void Bullet::update(float deltaTime)
{
	sf::Vector2f bulletPos = bullet.getPosition();

	if (bulletPos.x - 55 < tankEnemyPos.x && bulletPos.x + 55 > tankEnemyPos.x && bulletPos.y + 55 > tankEnemyPos.y && bulletPos.y - 55 < tankEnemyPos.y) {
		hit = true;
	}

	muzzleFlash.setPosition(gunPos.x + 115 * sin(angle), gunPos.y - 115 * cos(angle));
	bullet.move(dx * deltaTime, dy * deltaTime);
	delayTime -= deltaTime;


	if (OUTSIDE_AREA) life = false;
}

sf::Vector2f Bullet::getPosition()
{
	return bullet.getPosition();
}

void Bullet::draw(sf::RenderWindow &window)
{
		window.draw(bullet);
		if (delayTime > 0) {
			window.draw(muzzleFlash);
		}
}
