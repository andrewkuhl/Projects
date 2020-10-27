#ifndef ID_H
#define ID_H

#include <iostream>
using namespace std;
#include <string>
#include <ctime> 

class ID {

private:

    struct person {

        int id;
        string name;
        int age;

    };

    person* createPrivate(int id, string name, int age);
    void printPrivate(person* ptr);

public: 

    void print(person* ptr);
    person* create();
    int getID();
};

#endif 