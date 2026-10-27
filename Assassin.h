#pragma once
#include<iostream>
#include<cstdlib>
class Assassin {
private:
	int maxhealth, numOfHealthPotions, numOfAttackPotions, armor, criticChance, attackPower, dodgeChance, health;
	bool isDeath, isAttackBuffed;
public:
	Assassin() {
		isDeath = false;
		maxhealth = 100;
		health = 100;
		attackPower = 25;
		criticChance = 30;
		armor = 15;
		numOfHealthPotions = 3;
		numOfAttackPotions = 3;
		dodgeChance = 10;
		isAttackBuffed = false;
	}
	void getAttacked(int damage, bool isMagic = false) {
		int dodge = 1 + rand() % 100;
		if (dodge <= dodgeChance) {
			std::cout << "Suikastçý saldýrýdan sýyrýldý. Hasar almaktan kurtuldu. Suikastçýnýn " << health << " caný var.\n";
			return;
		}
		if (isMagic == true)
			std::cout << "Büyü saldýrýsý suikastçýnýn zýrhýný yok saydý!\n";
		if (armor > 0 && isMagic == false) {
			if (damage >= armor) {
				std::cout << "Suikastçýnýn zýrhý kýrýldý. ";
				std::cout << "Suikastçýnýn zýrhý " << armor << " kadar hasarý emdi.";
				damage = damage - armor;
			}
			else {
				damage = damage / 2;
				armor = armor - damage;
				std::cout << "Suikastçýnýn zýrhý " << damage << " kadar hasarý emdi.";
				std::cout << "Suikastçýnýn " << armor << " zýrhý kaldý. ";
			}
		}
		if ((health - damage) > 0) {
			health = health - damage;
			std::cout << "Suikastçý " << damage << " hasar aldý. ";
			std::cout << "Suikastçýnýn " << health << " caný kaldý.\n";
		}
		else {
			isDeath = true;
			std::cout << "Suikastçý öldü.\n";
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
			std::cout << "Suikastçý " << damage * 2 << " Hasar vurdu.\n";
			return damage * 2;
		}
		else {
			std::cout << "Suikastçý " << damage << " Hasar vurdu.\n";
			return damage;

		}

	}
	bool getIsDeath() {
		return isDeath;
	}
};