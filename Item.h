#pragma once
#include <iostream>

using namespace std;
class Item {
private:
   string name;      // 아이템의 문자열 이름입니다.
   int price;        // 아이템의 가격입니다.
   float weight;     // 아이템의 무게를 저장합니다.
public:
   Item(string name = "Unnamed", int price = 0, float weight = 0.01);

   string getName() const;
   int getPrice() const;
   float getWeight() const;

   void setName(string newName);
   void setPrice(int newPrice);
   void setWeight(float newWeight);

   virtual void printInfo() const;
};