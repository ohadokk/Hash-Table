#include <cstdlib>
#include <iostream>
#include <string.h>
using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash {
private:
	int TableSize;
	
	struct Item
	{
		string Name;
		int Id;
		Item* next;
	};
	Item* HashTable[];
	

public:
	Hash(int size);
	int HashFunction(string key);
	void AddItem(string name, int Id);
	int NumberOfItemsInIndex(int Index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindNameInTable(string name);
};

#endif
