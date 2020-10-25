#include "BST.h"


int main() {

	//test values
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	
	BST tree;

	cout << "[printing tree]" << endl;
	tree.PrintTree();
	

	for (int i = 0; i < 16; i++)
		tree.AddLeaf(TreeKeys[i]);
	
	cout << "[printing tree]" << endl;
	tree.PrintTree();

	cout << "\n[printing node]" << endl;
	tree.PrintChildren(tree.ReturnRootKey());

	cout << "\n[finding smallest]" << endl;
	cout << tree.FindSmallest() << endl;

	
	int n=0;
	
	
	


	
	return 0;
}

