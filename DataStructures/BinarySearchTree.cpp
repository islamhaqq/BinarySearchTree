#include "BinarySearchTree.h"

Node::Node(int data_) {
	data = data_;
}

Node::Node(int data_, Node* left_, Node* right_) {
	data = data_;
	left = left_;
	right = right_;
}

void BinarySearchTree::_insertToNode(int num, Node* node) {
    if (!node) {
        node = new Node(num);
    }
    else if (num > node->data) {
        _insertToNode(num, node->right);
    }
    else if (num < node->data) {
        _insertToNode(num, node->left);
    }
}

BinarySearchTree::BinarySearchTree() {}

BinarySearchTree::BinarySearchTree(int num) {
    _root = new Node(num);
}

BinarySearchTree::BinarySearchTree(vector<int> nums) {
    for (int num : nums) {
        insert(num);
    }
}

void BinarySearchTree::insertToNode(int num, Node* node) {
    // inserting a num to a node is just
    // inserting to the left node if it is smaller
    // inserting to the right node if it is bigger
    // and doing nothing if it is the same
    if (!node) {
        node = new Node(num);
    }
    else if (num > node->data) {
        cout << "inserted before: " << node->right << endl;
        BinarySearchTree::insertToNode(num, node->right);
        //node->right = new Node(num);
        cout << "inserted successfully: " << node->right << endl;
    }
    else if (num < node->data) {
        cout << "inserting " << num << " to the left of " << node->data << endl;
        BinarySearchTree::insertToNode(num, node->left);
    }
}

void BinarySearchTree::printInOrderOfNode(Node* node) {
    if (!node) {
        return;
    }

    printInOrderOfNode(node->left);

    cout << node->data << endl;

    printInOrderOfNode(node->right);
}

vector<int> BinarySearchTree::getInOrderOfNode(Node* node) {
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

void BinarySearchTree::insert(int num) {
    _insertToNode(num, _root);
}

vector<int> BinarySearchTree::getSorted() {
    return BinarySearchTree::getInOrderOfNode(_root);
}

void BinarySearchTree::printInOrder() {
    printInOrderOfNode(_root);
}
