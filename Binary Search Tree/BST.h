#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

class BST {

private:

	struct node {

		int key;
		node* left;
		node* right;
	};

	node* root;
	void AddLeafPrivate(int key, node* ptr);
	void PrintTreePrivate(node* ptr);
	node* ReturnNodePrivate(int key, node* ptr);
	int FindSmallestPrivate(node* ptr);
	void RemoveNodePrivate(int key, node* parent);
	void RemoveRootMatch();
	void RemoveMatch(node* parent, node* match, bool left);
	node* CreateLeaf(int key);
	node* ReturnNode(int key);
	void RemoveSubtree(node* ptr);

public:

	BST(); //constructor
	~BST();//deconstructor
	void AddLeaf(int key);
	void PrintTree();
	int ReturnRootKey();
	void PrintChildren(int key);
	int FindSmallest();
	void RemoveNode(int key);

};

#endif