#include "id.h"

int main(int argc, char* argv[]){

    ID test1;
    auto ptr = test1.create();
    test1.print(ptr);



    return 0;
}