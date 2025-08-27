#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
template<typename T>
class Inventory {
private:
   T *pItems_;       // 아이템 객체들을 저장할 동적 배열을 가리키는 포인터입니다. new T[]를 통해 메모리를 할당받습니다.
   int capacity_;    // 인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
   int size_;        // 현재 인벤토리에 저장된 아이템의 실제 개수입니다.
public:
   Inventory(int capacity = 10);
   ~Inventory();
   Inventory(const Inventory<T>& other);
   void AddItem(const T& item);
   void RemoveLastItem();
   void Resize(int newCapacity);
   void Assign(const Inventory<T>& other);
   static bool compareItemsByPrice(const T& a, const T& b);
   void SortItems();
   int GetSize() const;
   int GetCapacity() const;
   void PrintAllItems() const;
};