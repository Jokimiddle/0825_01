#include <iostream>
#include <algorithm>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Inventory.h"

using namespace std;

class Item;
class Weapon;
class Potion;
// T* pItems_;       // 아이템 객체들을 저장할 동적 배열을 가리키는 포인터입니다. new T[]를 통해 메모리를 할당받습니다.
// int capacity_;    // 인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
// int size_;        // 현재 인벤토리에 저장된 아이템의 실제 개수입니다.

template<typename T>
Inventory<T>::Inventory(int capacity) {
   this->capacity_ = capacity > 0 ? capacity : 1;
   this->size_ = 0;
   this->pItems_ = new T[this->capacity_];
}

template<typename T>
Inventory<T>::~Inventory() {
   delete[] this->pItems_;
   this->pItems_ = nullptr;   // 안전한 코드를 위해, 메모리 해제 후 포인터를 nullptr로 초기화합니다.
}

template<typename T>
Inventory<T>::Inventory(const Inventory<T>& other) {
   this->capacity_ = other.capacity_;
   this->size_ = other.size_;
   this->pItems_ = new T[capacity_];

   for (int i = 0; i < this->size_; ++i)
      pItems_[i] = other.pItems_[i];

   cout << "인벤토리 복사 완료" << endl;
}

template<typename T>
void Inventory<T>::AddItem(const T& item) {
   if (this->size_ < this->capacity_) {
      this->pItems_[this->size_] = item;
      this->size_++;
   }
   else {
      T* temp = this->pItems_;
      
      this->capacity_ *= 2;
      this->pItems_ = new T[this->capacity_];

      for (int i = 0; i < this->size_; ++i)
         this->pItems_[i] = temp[i];

      delete[]temp;
   }
};

template<typename T>
void Inventory<T>::RemoveLastItem() {
   this->size_--;
}

template<typename T>
void Inventory<T>::Resize(int newCapacity) {
   T* temp = this->pItems_;

   this->capacity_ = newCapacity;
   if (this->capacity_ < this->size_)
      this->size_ = this->capacity_;

   this->pItems_ = new T[newCapacity];

   for (int i = 0; i < this->size_; ++i)
      this->pItems_[i] = temp[i];

   delete[] temp;
}

template<typename T>
void Inventory<T>::Assign(const Inventory<T>& other) { 
   if (this == &other) {
      return;
   }
   delete[] this->pItems_;

   this->size_ = other.size_;
   this->capacity_ = other.capacity_;
   this->pItems_ = new T[this->capacity_];

   for (int i = 0; i < this->size_; i++) {
      this->pItems_[i] = other.pItems_[i];
   }
}

template<typename T>
bool Inventory<T>::compareItemsByPrice(const T& a, const T& b) {
   if constexpr (is_pointer_v<T>)
      return a->getPrice() < b->getPrice();
   else
      return a.getPrice() < b.getPrice();
}
template<typename T>
void Inventory<T>::SortItems() {
   sort(this->pItems_, this->pItems_ + this->size_, compareItemsByPrice);
}

template<typename T>
int Inventory<T>::GetSize() const { return this->size_; }

template<typename T>
int Inventory<T>::GetCapacity() const { return this->capacity_; }

template<typename T>
void Inventory<T>::PrintAllItems() const {
   for (int i = 0; i < this->size_; i++) {
      if constexpr (is_pointer_v<T>)
         this->pItems_[i]->printInfo();
      else
         this->pItems_[i].printInfo();
   }
}

template class Inventory<Item>;
template class Inventory<Item*>;
template class Inventory<Weapon>;
template class Inventory<Weapon*>;
template class Inventory<Potion>;
template class Inventory<Potion*>;
