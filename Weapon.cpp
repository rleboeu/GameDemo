/*
 * Weapon.cpp
 *
 *  Created on: Apr 7, 2020
 *      Author: nopath
 */

#include "Weapon.h"

Weapon::Weapon() {
	magazineCapacity = 20;
	magazineCurrent = magazineCapacity;
	rateOfFire = 10;
	shootTimer = rateOfFire;

	reloadSpeed = 70;
	reloadTimer = reloadSpeed;
	isReloading = false;
}

Weapon::Weapon(int magSize, int fireRate, int reloadTime) {
	magazineCapacity = magSize;
	magazineCurrent = magazineCapacity;
	rateOfFire = fireRate;
	shootTimer = rateOfFire;

	reloadSpeed = reloadTime;
	reloadTimer = reloadSpeed;

	isReloading = false;
}

Weapon& Weapon::operator=(Weapon* wep) {
	Weapon* temp = wep;

	temp->magazineCapacity = 20;
	temp->magazineCurrent = magazineCapacity;
	temp->rateOfFire = 10;
	temp->shootTimer = rateOfFire;

	temp->reloadSpeed = 70;
	temp->reloadTimer = reloadSpeed;
	temp->isReloading = false;

	return *temp;
}

Weapon::~Weapon() {
	// stub
}

void Weapon::fire(sf::Vector2f mousePosWindow, sf::Sprite& player, sf::Texture& bulletTexture) {
	if (magazineCurrent > 0 && isReloading == false) {
		sf::Vector2f playerCenter = player.getPosition();
		sf::Vector2f aimDir = mousePosWindow - playerCenter;
		sf::Vector2f aimDirNorm = aimDir / (float)(std::sqrt(std::pow(aimDir.x, 2) + std::pow(aimDir.y, 2)));

		if (shootTimer < rateOfFire)
			shootTimer++;

		if (shootTimer >= rateOfFire) {
			Projectile p(player, aimDirNorm, bulletTexture);
			activeBullets.push_back(p);
			magazineCurrent--;
			shootTimer = 0;
		}
	} else {
		isReloading = true;
	}
}

void Weapon::reload() {
	if (isReloading == false)
		isReloading = true;
}

void Weapon::tickReload() {
	if (isReloading) {
		reloadTimer--;
	}

	if (reloadTimer == 0) {
		magazineCurrent = magazineCapacity;
		reloadTimer = reloadSpeed;
		isReloading = false;
	}
}

void Weapon::removeTrespassingBullets() {
	for (size_t i = 0; i < activeBullets.size(); i++) {
		if (activeBullets.at(i).checkBounds() == false) {
			activeBullets.erase(activeBullets.begin() + i);
		} else {
			activeBullets.at(i).update();
		}
	}
}

std::string Weapon::getMagazineReport() {
	return std::to_string(magazineCurrent) + " / " + std::to_string(magazineCapacity);
}

bool Weapon::isBeingReloaded() {
	return isReloading;
}












