#include "BinarySearchTree.h"

Node::Node(int data_) {
	data = data_;
    left = NULL;
    right = NULL;
}

Node::Node(int data_, Node* left_, Node* right_) {
	data = data_;
	left = left_;
	right = right_;
}

BinarySearchTree::BinarySearchTree() {
    _root = NULL;
}

BinarySearchTree::BinarySearchTree(int num) {
    _root = new Node(num);
}

BinarySearchTree::BinarySearchTree(vector<int> nums) {
    for (int num : nums) {
        insert(num);
    }
}

Node* BinarySearchTree::insertToNode(int num, Node* node) {
    if (!node) {
        node = new Node(num);
        return node;
    }
    else if (num > node->data) {
        if (!node->right) {
            node->right = BinarySearchTree::insertToNode(num, node->right);
        }
        else {
            BinarySearchTree::insertToNode(num, node->right);
        }
    }
    else if (num < node->data) {
        if (!node->left) {
			node->left = BinarySearchTree::insertToNode(num, node->left);

        }
        else {
			BinarySearchTree::insertToNode(num, node->left);
        }
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
    insertToNode(num, _root);
}

vector<int> BinarySearchTree::getSorted() {
    return BinarySearchTree::getInOrderOfNode(_root);
}

void BinarySearchTree::printInOrder() {
    printInOrderOfNode(_root);
}
