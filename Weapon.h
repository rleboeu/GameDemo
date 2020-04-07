/*
 * Weapon.h
 *
 *  Created on: Apr 7, 2020
 *      Author: nopath
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <SFML/Graphics.hpp>
#include <vector>



#include "Projectile.h"

class Weapon {
public:
	Weapon();
	Weapon(int, int, int);
	Weapon& operator=(Weapon*);
	virtual ~Weapon();

	std::vector<Projectile> activeBullets;

	void fire(sf::Vector2f, sf::Sprite&, sf::Texture&);
	void reload();
	void tickReload();
	void removeTrespassingBullets();

	std::string getMagazineReport();

	bool isBeingReloaded();

private:
	int magazineCapacity;
	int magazineCurrent;
	int shootTimer;
	int rateOfFire;

	int reloadTimer;
	int reloadSpeed;
	bool isReloading;

};

#endif /* WEAPON_H_ */
