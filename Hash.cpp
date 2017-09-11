#include <iostream>
#include <string.h>
#include "Hash.h"
using namespace std;


Hash::Hash(int size) {
	TableSize = size;
	HashTable[size];
	for (int i = 0; i < size; i++) {
		HashTable[i] = new Item;
		HashTable[i]->Id = NULL;
		HashTable[i]->Name ="NULL";
		HashTable[i]->next = NULL;
	}
}

int Hash::HashFunction(string key) {
	int HashVar = 0;
	int Count;

	Count = key.length();
	for (int i = 0; i < Count; i++) {
		HashVar += (int)key[i];
	}
	return HashVar % TableSize;
}
void Hash::AddItem(string name, int Id) {
	int Index = HashFunction(name);

	if (HashTable[Index]->Id == NULL) {
		HashTable[Index]->Name = name;
		HashTable[Index]->Id = Id;
		HashTable[Index]->next = NULL;
	}
	else
	{
		Item* ptr = HashTable[Index];
		Item* newItem = new Item;
		newItem->Name = name;
		newItem->Id = Id;
		newItem->next = NULL;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = newItem;
		
	}
}
int Hash::NumberOfItemsInIndex(int index) {
	int Count = 0;
	if (HashTable[index]->Id == NULL) {
		return Count;
	}
	Count++;
	Item* ptr = HashTable[index];
	while (ptr->next != NULL) {
		Count++;
		ptr = ptr->next;
	}
	return Count;
}

void Hash::PrintTable() {
	int Number;
	for (int i = 0; i < TableSize; i++) {
		Number = NumberOfItemsInIndex(i);
		cout << "________________________\n";
		cout << "index=" << i << endl;
		cout << "first id=" << HashTable[i]->Id << endl;
		cout << "first name="<< (HashTable[i]->Name).c_str() <<endl;
		cout << "number of item in index " << Number<<endl;
		cout << "________________________\n";

	}
}
void Hash::PrintItemsInIndex(int index) {
	Item* ptr = HashTable[index];
	if (ptr->Id == NULL) {
		cout << "index is empty";
	}
	else
	{
		cout << "index " << index << " contains:\n";
		while (ptr != NULL) {
			cout << "+++++++++++++\n";
			cout << "Id:" << ptr->Id << endl;
			cout << "Name:" << (ptr->Name).c_str() << endl;
			cout << "+++++++++++++\n";
			ptr = ptr->next;
		}
	}
}

void Hash::FindNameInTable(string name) {

	int index = HashFunction(name);
	bool foundName = false;
	int id;

	Item* ptr = HashTable[index];
	while (ptr != NULL) {
		if (ptr->Name == name) {
			foundName == true;
			cout << "id of name: " << name.c_str() << "is " << ptr->Id<<"found in index "<< index <<endl;
		}
		ptr = ptr->next;
	}
}