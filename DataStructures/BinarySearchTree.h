#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;

	Node(int data_);

	Node(int data_, Node* left_, Node* right_);
};

class BinarySearchTree {
	Node* _root;

	void _insertToNode(int num, Node* node);

public:
	BinarySearchTree();

	BinarySearchTree(int num);

	BinarySearchTree(vector<int> nums);

	static void insertToNode(int num, Node* node);

	static void printInOrderOfNode(Node* node);

	static vector<int> getInOrderOfNode(Node* node);

	void insert(int num);

	vector<int> getSorted();

	void printInOrder();
};
