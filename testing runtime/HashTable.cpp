#include "HashTable.h"
Hash::Hash() {
	//initializing our items in the hash table
	for (int i = 0; i < tableSize; i++) {
		HashTable[i]= new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}

}
void Hash::printCollisions() {
	cout << collisions << endl;
}
int Hash::hash(string key) {
	int hash = 0;
	int index;
	
	//adding up the asciis of the whole string to be our key
	for (int i = 0; i < key.length(); i++)
		hash += (int)key[i];

	index = hash % tableSize; // ascii total mod 100
	
	return index;
}

void Hash::AddItem(string name, string drink) {
	int index = hash(name);

	//if index isnt taken
	if (HashTable[index]->name == "empty") {
		HashTable[index]->name = name;
		HashTable[index]->drink = drink;
	}
	else {//if index is taken
		collisions++;
		item* ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;
		while (ptr->next != NULL) {//searching for empty space
			ptr = ptr->next;
		}
		ptr->next = n;//add new item to empty space
	}
}

int Hash::NumberOfItemsInIndex(int index) {
	int count = 0;

	if (HashTable[index]->name == "empty") {
		return count;
	}
	else {
		count++;
		item* ptr = HashTable[index];
		while (ptr->next != NULL) {
			count++;
			ptr = ptr->next;
		}
	}
	return count;
}

void Hash::printTable() {
	int number;
	for (int i = 0; i < tableSize; i++) {
		item* ptr = HashTable[i];
		if (HashTable[i]->name != "empty") {
			cout << "------------------\n";
			cout << "index = " << i << endl;
			cout << "name = " << HashTable[i]->name << endl;
			cout << "drink = " << HashTable[i]->drink << endl;
			cout << "------------------\n";
		}
		if (NumberOfItemsInIndex(i) > 1) {
			while (ptr->next != NULL) {
				ptr = ptr->next;
				cout << "------------------\n";
				cout << "index = " << i << endl;
				cout << "name = " << ptr->name << endl;
				cout << "drink = " << ptr->drink << endl;
				cout << "------------------\n";
				
			}
		}
	}
	
}
