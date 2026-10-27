#pragma once
#include<iostream>
#include<cstdlib>
class Knight {
private:
	int health, numOfHealthPotions, numOfAttackPotions, armor, criticChance, attackPower, maxhealth;
	bool isDeath, isAttackBuffed, hasRevived;
public:
	Knight() {
		isDeath = false;
		maxhealth = 120;
		health = 120;
		attackPower = 20;
		criticChance = 15;
		armor = 40;
		numOfHealthPotions = 3;
		numOfAttackPotions = 3;
		isAttackBuffed = false;
		hasRevived = false;
	}
	void getAttacked(int damage, bool isMagic = false) {
		if (isMagic == true)
			std::cout << "Büyü saldýrýsý þövalyenin zýrhýný yok saydý!\n";
		if (armor > 0 && isMagic == false) {
			if (damage >= armor) {
				std::cout << "Þövalyenin zýrhý kýrýldý. ";
				std::cout << "Þövalyenin zýrhý " << armor << " kadar hasarý emdi.";
				damage = damage - armor;
			}
			else {
				damage = damage / 2;
				armor = armor - damage;
				std::cout << "Þövalyenin zýrhý " << damage << " kadar hasarý emdi.";
				std::cout << "Þövalyenin " << armor << " zýrhý kaldý. ";
			}
		}
		if ((health - damage) > 0) {
			health = health - damage;
			std::cout << "Þövalye " << damage << " hasar aldý. ";
			std::cout << "Þövalyenin " << health << " caný kaldý.\n";
		}
		else {
			if (hasRevived == true) {
				isDeath = true;
				std::cout << "Þövalye öldü.\n";
			}
			else
				revive();
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
			std::cout <<"Þövalye " << damage * 2 << " Hasar vurdu.\n";
			return damage * 2;
		}
		else {
			std::cout << "Þövalye " << damage << " Hasar vurdu.\n";
			return damage;
		}

	}
	bool getIsDeath() {
		return isDeath;
	}
	void revive() {
		std::cout << "Þanlý þövalye bir kez daha ayaða kalkýyor!! ";
		health = maxhealth / 2;
		std::cout << health << " canla savaþa geri döndü. \n";
		hasRevived = true;
	}
};