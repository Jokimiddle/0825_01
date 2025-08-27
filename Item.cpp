#include <iostream>
#include "Item.h"

using namespace std;

//   string name;      // 아이템의 문자열 이름입니다.
//   int price;        // 아이템의 가격입니다.
//   float weight;     // 아이템의 무게를 저장합니다.
class Item;

Item::Item(string name, int price, float weight) {
   this->name = name;
   this->price = price;
   this->weight = weight;
}

string Item::getName() const { return this->name; }
int Item::getPrice() const { return this->price; }
float Item::getWeight() const { return this->weight; }

void Item::setName(string newName) { this->name = newName; };
void Item::setPrice(int newPrice) { this->price = newPrice; }
void Item::setWeight(float newWeight) { this->weight = newWeight; }

void Item::printInfo() const {
   cout << "[이름: " << this->getName() << ", 가격: " << this->getPrice() << "G, 무게: " << this->getWeight() << "kg]" << endl;
}