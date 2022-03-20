// DataStructures.cpp : Defines the entry point for the application.
//

#include "DataStructures.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	/*BinarySearchTree* bst = new BinarySearchTree(5);
	bst->insert(6);
	bst->insert(4);
	bst->printInOrder();
	*/
	//Node* root = new Node(5, new Node(2, NULL, new Node(3)), new Node(9));
	Node* root = new Node(10);
	//BinarySearchTree::insertToNode(11, root);
	//BinarySearchTree::insertToNode(7, root);
	cout << root->data << endl;
	vector<int> out = BinarySearchTree::getInOrderOfNode(root);
	for (int& num : out) {
		cout << num << endl;
	}

	return 0;
}
