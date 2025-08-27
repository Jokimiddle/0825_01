#include <iostream>
#include "Item.h"
#include "Potion.h"
using namespace std;

class Item;
class Potion;
// int heal;       // 포션 아이템의 회복량을 저장합니다.
Potion::Potion(string name, int price, float weight, int heal) : Item(name, price, weight), heal(heal) {
	this->heal = heal > 0 ? heal : 1;
}

int Potion::getHeal() const { return this->heal; }

void Potion::setHeal(int newHeal) {
	this->heal = newHeal > 0 ? newHeal : 1;
}

void Potion::printInfo() const {
	cout << "[이름: " << this->getName() << ", 가격: " << this->getPrice() << "G, 무게: " <<
		this->getWeight() << "kg, 회복량: " << this->heal << "]" << endl;
}