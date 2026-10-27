#include<iostream>
#include<locale.h>
#include<time.h>
#include<cstdlib.>
#include"Knight.h"
#include"Mage.h"
#include"Assassin.h"

using namespace std;
int main() {
	Knight knight;
	Mage mage;
	Assassin assassin;
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	mage.getAttacked(knight.attack());
	knight.getAttacked(mage.attack(), true);
	assassin.getAttacked(knight.attack());
	
	return 0;
}