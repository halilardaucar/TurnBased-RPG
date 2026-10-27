#pragma once
#include<iostream>
#include<cstdlib>
class Mage {
private:
	int health, numOfHealthPotions, numOfAttackPotions, armor, criticChance, attackPower, maxhealth;
	bool isDeath, isAttackBuffed;
public:
	Mage() {
		isDeath = false;
		maxhealth = 80;
		health = 80;
		attackPower = 20;
		criticChance = 20;
		armor = 10;
		numOfHealthPotions = 3;
		numOfAttackPotions = 3;
		isAttackBuffed = false;
	}
	void getAttacked(int damage, bool isMagic = false) {
		if (isMagic == true)
			std::cout << "Büyü saldýrýsý büyücünün zýrhýný yok saydý!\n";
		if (armor > 0 && isMagic == false) {
			if (damage >= armor) {
				std::cout << "Büyücünün zýrhý kýrýldý. ";
				std::cout << "Büyücünün zýrhý " << armor << " kadar hasarý emdi.";
				damage = damage - armor;
			}
			else {
				damage = damage / 2;
				armor = armor - damage;
				std::cout << "Büyücünün zýrhý " << damage << " kadar hasarý emdi.";
				std::cout << "Büyücünün " << armor << " zýrhý kaldý. ";
			}
		}
		if ((health - damage) > 0) {
			health = health - damage;
			std::cout << "Büyücü " << damage << " hasar aldý. ";
			std::cout << "Büyücünün " << health << " caný kaldý.\n";
		}
		else {
			isDeath = true;
			std::cout << "Büyücü öldü.\n";
		}
	}
	void useHealthPotions() {
		if (numOfHealthPotions == 0) {
			std::cout << "Can Ýksiri Kalmadý.\n";
			return;
		}

		if ((health + 30) > maxhealth)
			health = maxhealth;
		else
			health += 30;
		numOfHealthPotions--;
		std::cout << "Can iksiri kullanýldý. Can 30 arttý:\n";
	}
	void useAttackPotions() {
		if (numOfAttackPotions == 0) {
			std::cout << "Saldýrý Ýksiri Kalmadý.\n";
			return;
		}
		isAttackBuffed = true;
		std::cout << "Saldýrý iksiri kullanýldý. Saldýrý gücü 10 arttý.\n";
		numOfAttackPotions--;
	}
	int attack() {
		int damage = attackPower;
		if (isAttackBuffed == true) {
			damage += 10;
			isAttackBuffed = false;
		}
		int crit = 1 + rand() % 100;
		if (crit <= criticChance) {
			std::cout << "Kritik Hasar!! ";
			std::cout << "Büyücü " << damage * 2 << " Hasar vurdu.\n";
			return damage * 2;
		}
		else {
			std::cout << "Büyücü " << damage << " Hasar vurdu.\n";
			return damage;

		}

	}
	bool getIsDeath() {
		return isDeath;
	}
};