/*
 * Projectile.cpp
 *
 *  Created on: Apr 5, 2020
 *      Author: nopath
 */

#include "Projectile.h"
//
//Projectile::Projectile() {
//	BulletTexture.loadFromFile("Resources/Textures/bullet.png");
//	Bullet.setTexture(BulletTexture);
//	isFired = true;
//}
//
////static void Projectile::SetDirection(sf::Sprite Reference)
////{
////	float TargetRotation = Reference.getRotation();
////	Bullet.setRotation(static_cast<float>(std::fmod(TargetRotation, 360.)));
////	float BulletRotation = Bullet.getRotation();
////	if (BulletRotation < 0)
////		Bullet.setRotation(BulletRotation + 360.f);
////}
////
////static void Projectile::SetSpeed(float SpeedMultiplier)
////{
////	float BulletX = Bullet.getPosition().x;
////	float BulletY = Bullet.getPosition().y;
////
////	Bullet.setPosition(BulletX * SpeedMultiplier, BulletY * SpeedMultiplier);
////}
