#pragma once
#include <iostream>
#include "Item.h"

using namespace std;
class Potion : public Item {
private:
   int heal;       // 포션 아이템의 회복량을 저장합니다.
public:
   Potion(string name = "Unnamed", int price = 0, float weight = 0.01, int heal = 1);
   int getHeal() const;
   void setHeal(int newHeal);

   void printInfo() const override;
};
