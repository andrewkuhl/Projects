#include "HashTable.h"


int main(int argc, char** argv) {
	
	Hash HashObj;
	HashObj.AddItem("Andrew", "1");
	HashObj.AddItem("Ryan", "1");
	HashObj.AddItem("Andrew", "2");
	HashObj.AddItem("Andrew", "3");
	HashObj.AddItem("Andrew", "4");
	HashObj.AddItem("Andrew", "5");
	HashObj.AddItem("Leo", "1");
	HashObj.AddItem("Chandler", "1");
	HashObj.AddItem("Brandon", "1");

	
	string name = "";
	while (name != "exit") {
		cout << " search: ";
		cin >> name;
		if (name != "exit")
			HashObj.Find(name);
	}

	return 0;
}