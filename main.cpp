#include <iostream>
#include <string.h>
#include "Hash.h"
using namespace std;

int main(int argc, char** argv[]) {

	int index;
	Hash HashTest(5);

	HashTest.AddItem("aaaa", 1);
	HashTest.AddItem("bbbb", 2);
	HashTest.AddItem("cccc", 3);
	HashTest.AddItem("dddd", 4);
	HashTest.AddItem("eeee", 5);
	HashTest.AddItem("ffff", 6);
	HashTest.AddItem("gggg", 7);
	HashTest.AddItem("hhhh", 8);
	HashTest.PrintTable();
	HashTest.PrintItemsInIndex(2);
	system("pause");
}