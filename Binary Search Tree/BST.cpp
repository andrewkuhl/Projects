#include "BST.h"

BST::BST(){//constructor

	root = NULL;
}

BST::node* BST::CreateLeaf(int key) {

	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void BST::AddLeaf(int key) {

	AddLeafPrivate(key, root);//so we are able to call private func from main
}

void BST::AddLeafPrivate(int key, node* ptr) {

	if (root == NULL) { //creates new leaf if empty
		
		root = CreateLeaf(key);
	}
	else if (key < ptr->key) {

		if (ptr->left != NULL)//if not empty traverse left 
			AddLeafPrivate(key, ptr->left);
		else 
			ptr->left = CreateLeaf(key); //if empty create leaf
	}
	else if (key > ptr->key) { //if key is bigger

		if (ptr->right != NULL)
			AddLeafPrivate(key, ptr->right); //if not empty traverse right
		else
			ptr->right = CreateLeaf(key);//if empty create leaf
	}
	else {

		cout << "key: " << key << " has already been added" << endl;

	}


}

void BST::PrintTree() {

	PrintTreePrivate(root);

}

void BST::PrintTreePrivate(node* ptr) {

	if (root != NULL) {

		if (ptr->left != NULL)
			PrintTreePrivate(ptr->left);

		cout << ptr->key << " ";

		if (ptr->right != NULL)
			PrintTreePrivate(ptr->right);
		
	}
	else
		cout << "[tree empty]" << endl;

	
}

BST::node* BST::ReturnNode(int key) {

	return ReturnNodePrivate(key, root);

}

BST::node* BST::ReturnNodePrivate(int key, node* ptr) {

	if (ptr != NULL) {

		if (ptr->key == key)
			return ptr;

		else {

			if (key < ptr->key)
				return ReturnNodePrivate(key, ptr->left);

			else
				return ReturnNodePrivate(key, ptr->right);

		}
	}
	else
		return NULL;

}

int BST::ReturnRootKey() {

	if (root != NULL)
		return root->key;

	else
		return -1000;

}

void BST::PrintChildren(int key) {

	node* ptr = ReturnNode(key);

	if (ptr != NULL) {

		cout << "Parent Node = " << ptr->key << endl;

		ptr->left == NULL ?
			cout << "left child = NULL" << endl :
			cout << "left child = " << ptr->left->key << endl; 

		ptr->right == NULL ?
			cout << "right child = NULL" << endl :
			cout << "right child = " << ptr->right->key << endl;

	}
	else
		cout << "key " << key << " does not exist" << endl;
}

int BST::FindSmallest() {

	return FindSmallestPrivate(root);

}

int BST::FindSmallestPrivate(node* ptr) {

	if (root == NULL) {
	
		cout << "[tree empty]" << endl;
		return -1000;

	}
	else {

		if (ptr->left != NULL)
			return FindSmallestPrivate(ptr->left);
		
		else
			return ptr->key;
	}
}

void BST::RemoveNode(int key) {

	return RemoveNodePrivate(key, root);

}

void BST::RemoveNodePrivate(int key, node* parent) {

	if (root != NULL) {

		if (root->key == key)
			RemoveRootMatch();

		else {

			if (key < parent->key && parent->left != NULL) {

				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);

			}
			else if (key > parent->key && parent->right != NULL) {

				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);

			}
			else
				cout << "[key not found]" << endl;

		}
	}
	else
		cout << "[tree empty]" << endl;
}

void BST::RemoveRootMatch() {

	if (root != NULL) {

		node* delptr = root;
		int rootKey = root->key;
		int smallRight; //smallest key in right subtree

		//root has 0 children
		if (root->left == NULL && root->right == NULL) {

			root = NULL;
			delete delptr;

		}
		//root has 1 child on the right
		else if (root->left == NULL && root->right != NULL) {

			root = root->right;
			delptr->right = NULL;
			delete delptr;
			cout << "[old root " << rootKey << " deleted]" << endl;
			cout << "[new root is " << root->key << "]" << endl;

		}
		//root has 1 child on the left
		else if (root->left != NULL && root->right == NULL) {

			root = root->left;
			delptr->left = NULL;
			delete delptr;
			cout << "[old root " << rootKey << " deleted]" << endl;
			cout << "[new root is " << root->key << "]" << endl;

		}
		//root has two children
		else {

			smallRight = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallRight, root);
			root->key = smallRight;
			cout << "[old root " << rootKey << " deleted]" << endl;
			cout << "[new root is " << root->key << "]" << endl;

		}
	}
	else
		cout << "[tree empty]" << endl;

}
void BST::RemoveMatch(node* parent, node* match, bool left) {

	if (root != NULL) {

		node* delptr;
		int matchKey = match->key;
		int smallRight;

		//match has 0 children
		if (match->left == NULL && match->right == NULL) {

			delptr = match;

			left == true ?
				parent->left = NULL :
				parent->right = NULL;

			delete delptr;
			cout << "[" << matchKey << " removed]" << endl;

		}
		//match has one child
		else if (match->left == NULL && match->right != NULL) {

			left == true ?
				parent->left = match->right :
				parent->right = match->right;
			match->right = NULL;
			delptr = match;
			delete delptr;
			cout << "[" << matchKey << " removed]" << endl;

		}
		else if (match->left != NULL && match->right == NULL) {

			left == true ?
				parent->left = match->left :
				parent->right = match->left;
			match->left = NULL;
			delptr = match;
			delete delptr;
			cout << "[" << matchKey << " removed]" << endl;

		}
		//node has two children
		else {

			smallRight = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallRight, match);
			match->key = smallRight;
		}

	}
	else
		cout << "[tree empty]" << endl;

}

BST::~BST() {

	RemoveSubtree(root);

}

void BST::RemoveSubtree(node* ptr) {

	if (ptr != NULL) {

		if (ptr->left != NULL) {
			RemoveSubtree(ptr->left);
		}
		if (ptr->right != NULL) {
			RemoveSubtree(ptr->right);
		}
		cout << "[deleting " << ptr->key << "]" << endl;
		delete ptr;

	}
	

}