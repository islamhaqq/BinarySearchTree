// DataStructures.cpp : Defines the entry point for the application.
//

#include "DataStructures.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	BinarySearchTree* bst = new BinarySearchTree(13);
	bst->insert(19);
	bst->insert(3);
	bst->insert(7);
	bst->insert(33);

	bst->printPostOrder();

	return 0;
}
