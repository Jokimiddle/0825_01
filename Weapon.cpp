#include <iostream>
#include "Item.h"
#include "Weapon.h"
using namespace std;

class Item;
class Weapon;
// int damage;       // 무기 아이템의 피해량을 저장합니다.
Weapon::Weapon(string name, int price, float weight, int damage) : Item(name, price, weight), damage(damage) {
	this->damage = damage > 0 ? damage : 1;
}

int Weapon::getDamage() const { return this->damage; }

void Weapon::setDamage(int newDamage) {
	this->damage = newDamage > 0 ? newDamage : 1;
}

void Weapon::printInfo() const {
	cout << "[이름: " << this->getName() << ", 가격: " << this->getPrice() << "G, 무게: " << 
		this->getWeight() << "kg, 피해량: " << this->damage << "]" << endl;
}