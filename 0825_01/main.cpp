#include <iostream>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Inventory.h"
#include <cmath>

class Item;
class Weapon;
class Potion;
template<typename T>
class Inventory;

using namespace std;

void print_inv(Inventory<Item*>* actor) {
	cout << "플레이어 인벤토리 크기: " << actor->GetSize() << "/" << actor->GetCapacity() << endl;
}
int main() {
	Inventory<Item*> *player_inv = new Inventory<Item*>(3);	// 플레이어 인벤토리 생성
	cout << "◎플레이어 인벤토리 생성" << endl;
	print_inv(player_inv);
	// cout.precision(2);
	cout << "------------------------------------------------------" << endl;

	player_inv->AddItem(new Item("통나무", 3, 2.0));
	player_inv->AddItem(new Weapon("검", 100, 10.0, 15));
	player_inv->AddItem(new Potion("물약", 50, 0.5, 50));
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;
	
	cout << "◎최대 인벤토리에서 아이템 추가(AddItem)" << endl;
	player_inv->AddItem(new Item("통나무", 3, 2.0));
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;

	cout << "◎인벤토리에서 마지막 아이템 삭제(RemoveLastItem)" << endl;
	player_inv->RemoveLastItem();
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;

	cout << "◎인벤토리 크기 직접변경(Resize): 1" << endl;
	player_inv->Resize(1);
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;

	cout << "◎인벤토리 로드하기(대입)" << endl;
	Inventory<Item*>* save_inv = new Inventory<Item*>(2);
	save_inv->AddItem(new Item("금화", 100000, 5.0));
	save_inv->AddItem(new Item("금화", 100000, 5.0));
	player_inv = save_inv;
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;

	cout << "◎인벤토리 로드하기(Assign)" << endl;
	Inventory<Item*>* save_inv_2 = new Inventory<Item*>(5);
	save_inv_2->AddItem(new Weapon("단검", 60, 5.0, 7));
	save_inv_2->AddItem(new Item("통나무", 3, 2.0));
	save_inv_2->AddItem(new Item("금화", 100000, 5.0));
	save_inv_2->AddItem(new Potion("물약", 50, 0.5, 50));
	save_inv_2->AddItem(new Potion("물약", 50, 0.5, 50));
	player_inv->Assign(*save_inv_2);
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;

	cout << "◎인벤토리 아이템 가격기준 정렬(SortItems)" << endl;
	player_inv->SortItems();
	player_inv->PrintAllItems();
	print_inv(player_inv);
	cout << "------------------------------------------------------" << endl;
	return 0;
}
