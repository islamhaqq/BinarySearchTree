#include "BinarySearchTree.h"

Node::Node(int data_)
{
    data = data_;
    left = NULL;
    right = NULL;
}

Node::Node(int data_, Node* left_, Node* right_)
{
    data = data_;
    left = left_;
    right = right_;
}

BinarySearchTree::BinarySearchTree()
{
    _root = NULL;
}

BinarySearchTree::BinarySearchTree(int num)
{
    _root = new Node(num);
}

BinarySearchTree::BinarySearchTree(vector<int> nums)
{
    _root = NULL;
    for (int num : nums) {
        insert(num);
    }
}

Node* BinarySearchTree::insertToNode(int num, Node* root)
{
    if (!root) {
        return new Node(num);
    }
    else if (num > root->data) {
        root->right = BinarySearchTree::insertToNode(num, root->right);
    }
    else if (num < root->data) {
		root->left = BinarySearchTree::insertToNode(num, root->left);
    }
    return root;
}

void BinarySearchTree::printPreOrderOfNode(Node* node)
{
	if (!node) {
		return;
	}

    cout << node->data << endl;

	printInOrderOfNode(node->left);

	printInOrderOfNode(node->right);

}

void BinarySearchTree::printInOrderOfNode(Node* node)
{
    if (!node) {
        return;
    }

    printInOrderOfNode(node->left);

    cout << node->data << endl;

    printInOrderOfNode(node->right);
}

void BinarySearchTree::printPostOrderOfNode(Node* node)
{
	if (!node) {
		return;
	}

	printInOrderOfNode(node->left);

	printInOrderOfNode(node->right);

	cout << node->data << endl;
}

vector<int> BinarySearchTree::getInOrderOfNode(Node* node)
{
    vector<int> output = {};
    if (!node) {
        return output;
    }

    vector<int> left = BinarySearchTree::getInOrderOfNode(node->left);
    output.insert(output.end(), left.begin(), left.end());

    output.push_back(node->data);

    vector<int> right = BinarySearchTree::getInOrderOfNode(node->right);
    output.insert(output.end(), right.begin(), right.end());

    return output;
}

std::vector<int> BinarySearchTree::getPreOrderOfNode(Node* node)
{
	vector<int> output;

    output.push_back(node->data);

	vector<int> left = getPreOrderOfNode(node->left);
	output.insert(output.end(), left.begin(), left.end());

	vector<int> right = getPreOrderOfNode(node->right);
	output.insert(output.end(), right.begin(), right.end());

	return output;
}

std::vector<int> BinarySearchTree::getPostOrderOfNode(Node* node)
{
    vector<int> output;
    
	vector<int> left = getPreOrderOfNode(node->left);
	output.insert(output.end(), left.begin(), left.end());

	vector<int> right = getPreOrderOfNode(node->right);
	output.insert(output.end(), right.begin(), right.end());

	output.push_back(node->data);

    return output;
}

void BinarySearchTree::insert(int num)
{
    if (!_root)
    {
        _root = insertToNode(num, _root);
    }
    else
    {
        insertToNode(num, _root);
    }
}

vector<int> BinarySearchTree::getSorted()
{
    return BinarySearchTree::getInOrderOfNode(_root);
}

std::vector<int> BinarySearchTree::getPreOrder()
{
    return getPreOrderOfNode(_root);
}

std::vector<int> BinarySearchTree::getInOrder()
{
    return getInOrderOfNode(_root);
}

std::vector<int> BinarySearchTree::getPostOrder()
{
    return getPostOrderOfNode(_root);
}

void BinarySearchTree::printPreOrder()
{
    printPreOrderOfNode(_root);
}

void BinarySearchTree::printInOrder()
{
    printInOrderOfNode(_root);
}

void BinarySearchTree::printPostOrder()
{
    printPostOrderOfNode(_root);
}
