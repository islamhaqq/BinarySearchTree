// DataStructures.cpp : Defines the entry point for the application.
//

#include "DataStructures.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	vector<int> nums = {13,19,3,7,33};
	BinarySearchTree* bst = new BinarySearchTree(nums);

	bst->printInOrder();

	return 0;
}
