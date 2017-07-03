#pragma once

// Binary Tree 
// Ozan Ozkan - 03/07/2017

#include <iostream>

struct Node
{
public:
	Node() : m_value(-1), m_leftNode(nullptr), m_rightNode(nullptr) {}
	Node(int value): m_value(value), m_leftNode(nullptr), m_rightNode(nullptr) {}

	void setLeftNode(Node* node) { m_leftNode = node; }
	void setRightNode(Node* node) { m_rightNode = node; }
	Node* getRightNode() { return m_rightNode; }
	Node* getLeftNode() { return m_leftNode; }

	int getValue() { return m_value; }
	void setValue(int value) { m_value = value; }

private:
	int m_value;
	Node* m_leftNode;
	Node* m_rightNode;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void Insert(int value);
	Node* Search(int value);
	void Print();

private:
	void Insert(int value, Node* leaf);
	void Print(Node* leaf);
	Node* Search(int value, Node* leaf);

	Node* m_rootNode;
};

