//
// Created by Andrew on 10/28/2020.
//

#ifndef MYAPPSTORE_GIVEN_H
#define MYAPPSTORE_GIVEN_H

#include <iostream>
#include <string>
using namespace std;

#define CAT_NAME_LEN 25
#define APP_NAME_LEN 50
#define VERSION_LEN 10
#define UNIT_SIZE 3





    struct app_info {
        char category[CAT_NAME_LEN]; // Name of category
        char app_name[APP_NAME_LEN]; // Name of the application
        char version[VERSION_LEN]; // Version number
        float size; // Size of the application
        char units[UNIT_SIZE]; // GB or MB
        float price; // Price in $ of the application
    };
    struct categories {
        char category[CAT_NAME_LEN]; // Name of category
        struct tree *root; // Pointer to root of search tree for this category
    };
    struct tree { // A binary search tree
        struct app_info record; // Information about the application
        struct tree *left; // Pointer to the left subtree
        struct tree *right; // Pointer to the right subtree
    };
    struct hash_table_entry {
        char app_name[APP_NAME_LEN]; // Name of the application
        struct tree *app_node; // Pointer to node in tree containing the application information
        struct hash_table_entry *next; // Pointer to next entry in the chain
    };












#endif //MYAPPSTORE_GIVEN_H
