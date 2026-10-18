#include<iostream>
#include<locale.h>
#include<time.h>
class Knight {
private:
	int health, numOfHealthPotions, numOfAttackPotions, armor, criticChance, crit, attackPower;
	bool isDeath, isAttackBuffed;
public:
	Knight() {
		isDeath = false;
		health = 100;
		attackPower = 15;
		criticChance = 10;
		armor = 50;
		numOfHealthPotions = 3;
		numOfAttackPotions = 3;
		isAttackBuffed = false;
	}
	void getAttacked(int damage) {
		if (armor > 0) {
			damage = damage / 2;
			armor = armor - damage;
		}
		if ((health - damage) > 0)
			health = health - damage;
		else
			isDeath = true;
	}
	void useHealthPotions() {
		if (numOfHealthPotions == 0) {
			cout << "Can İksiri Kalmadı.";
			return;
		}

		if ((health + 30) > 100)
			health = 100;
		else
			health += 30;
		numOfHealthPotions--;
	}
	void useAttackPotions() {
		if (numOfAttackPotions == 0) {
			cout << "Saldırı İksiri Kalmadı.";
			return;
		}
		isAttackBuffed = true;
		numOfAttackPotions--;
	}
	int attack() {
		int damage = attackPower;
		if (isAttackBuffed == true) {
			damage += 10;
			isAttackBuffed = false;
		}
		crit = 1 + rand() % 100;
		if (crit <= criticChance) {
			cout << "Kritik Hasar!!";
			return damage * 2;
		}
		else
			return damage;

	}
	bool getIsDeath() {
		return isDeath;
	}
};

using namespace std;
int main() {
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));



	return 0;
}
