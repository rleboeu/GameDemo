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

Weapon& Weapon::operator=(Weapon* wep) {
	Weapon* temp = wep;

//	temp->setMagazineCapacity(20);
//	temp->setRateOfFire(5);
//	temp->setReloadSpeed(70);
//	temp->isReloading = false;

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

void Weapon::setMagazineCapacity(int x) {
	magazineCapacity = x;
	magazineCurrent = magazineCapacity;
}

void Weapon::setRateOfFire(int x) {
	rateOfFire = x;
	shootTimer = rateOfFire;
}

void Weapon::setReloadSpeed(int x) {
	reloadSpeed = x;
	reloadTimer = reloadSpeed;
}

void Weapon::setMagazineCurrent(int x) {
	magazineCurrent = x;
}



int Weapon::getMagazineCapacity() {
	return magazineCapacity;
}
int Weapon::getMagazineCurrent() {
	return magazineCurrent;
}

std::string Weapon::getMagazineReport() {
	return std::to_string(magazineCurrent) + " / " + std::to_string(magazineCapacity);
}

int Weapon::getShootTimer() {
	return shootTimer;
}

int Weapon::getRateOfFire() {
	return rateOfFire;

}
int Weapon::getReloadSpeed() {
	return reloadSpeed;
}

int Weapon::getReloadTimer() {
	return reloadTimer;
}

bool Weapon::isBeingReloaded() {
	return isReloading;
}












