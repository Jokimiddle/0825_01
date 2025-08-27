#pragma once
#include <iostream>
#include "Item.h"

using namespace std;
class Weapon : public Item {
private:
   int damage;       // 무기 아이템의 피해량을 저장합니다.
public:
   Weapon(string name = "Unnamed", int price = 0, float weight = 0.01, int damage = 1);
   int getDamage() const;
   void setDamage(int newDamage);

   void printInfo() const override;
};
