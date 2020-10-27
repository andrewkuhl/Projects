#include "id.h"

int ID::getID(){

    srand((unsigned)time(0)); //using time to seed

    // random int 1-1000
    int id = (rand() % 1000) + 1;

    return id;
}

ID::person* ID::create(){
    int id = getID();

    string name;
    cout << "Name: ";
    cin >> name;

    int age;
    cout << "\nAge: ";
    cin >> age;

    return createPrivate(id, name, age);

}

ID::person* ID::createPrivate(int id, string name, int age){

    person* n = new person;
	n->name = name;
	n->age = age;
	n->id = id;

	return n;

}

void ID::print(person* ptr){

    printPrivate(ptr);

}
void ID::printPrivate(person* ptr){

    cout << "---------------" << endl;
    cout << "ID: " << ptr->id << endl;
    cout << "NAME: " << ptr->name << endl;
    cout << "AGE: " << ptr->age << endl;
    cout << "---------------" << endl;

}