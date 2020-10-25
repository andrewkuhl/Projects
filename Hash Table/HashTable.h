#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;

class Hash {
private:
	int collisions = 0;

	static const int tableSize = 100;

	struct item { // what we are putting into the table
		string name;
		string drink;
		item* next;
	};

	item* HashTable[tableSize];

public: 
	Hash();//constructor
	int hash(string key);//creating key value from string
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void printTable();
	void printCollisions();
	void Find(string name);
	
};



#endif