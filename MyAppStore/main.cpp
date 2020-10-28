#include "given.h"

int main() {

    int numOfCat;
    cin >> numOfCat;
    cin.ignore();
    struct categories app_categories [numOfCat];

    for(int i = 0; i < numOfCat; i++){

        char str[APP_NAME_LEN];
        cin.getline(str, APP_NAME_LEN);

        for(int j = 0; j < APP_NAME_LEN; j++)
            app_categories[i].category[j] = str[j];

        tree *newTree = new tree; //creating tree
        newTree = nullptr;
        app_categories[i].root = newTree;

    }

    for(int i = 0; i< numOfCat; i++){
        cout << app_categories[i].category << endl;
        cout << app_categories[i].root << endl;
    }






    return 0;
}
