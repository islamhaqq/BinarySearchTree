#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	struct Node* left;
	struct Node* right;
	int data;

	Node(int data_);

	Node(int data_, Node* left_, Node* right_);
};

class BinarySearchTree {
	Node* _root;

public:
	BinarySearchTree();

	BinarySearchTree(int num);

	BinarySearchTree(vector<int> nums);

	static Node* insertToNode(int num, Node* node);

	static void printPreOrderOfNode(Node* node);

	static void printInOrderOfNode(Node* node);

	static void printPostOrderOfNode(Node* node);

	static vector<int> getInOrderOfNode(Node* node);

	static vector<int> getPreOrderOfNode(Node* node);

	static vector<int> getPostOrderOfNode(Node* node);

	void insert(int num);

	vector<int> getSorted();

	vector<int> getPreOrder();

	vector<int> getInOrder();

	vector<int> getPostOrder();

	void printPreOrder();

	void printInOrder();

	void printPostOrder();
};
