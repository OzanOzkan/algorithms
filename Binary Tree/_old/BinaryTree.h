#pragma once

// Binary Tree
// Ozan Ozkan - 23/04/2017

#include <iostream>

class MyBinaryTree {
protected:
	struct Node
	{
	public:
		int value;
		Node* leftNode;
		Node* rightNode;

		Node(int value)
			: leftNode(nullptr)
			, rightNode(nullptr)
		{
			this->value = value;
		};
	};

public:
	Node* rootNode;

public:
	MyBinaryTree()
		: rootNode(nullptr)
	{};

	void addNode(int value)
	{
		Node* newNode = new Node(value);

		if (rootNode == nullptr)
		{
			rootNode = newNode;
		}
		else
		{
			Node* focusNode = rootNode;
			Node* parentNode;
			
			while (true)
			{
				parentNode = focusNode;

				if (value < focusNode->value)
				{
					focusNode = focusNode->leftNode;

					if (focusNode == nullptr)
					{
						parentNode->leftNode = newNode;
						return;
					}
				}
				else
				{
					focusNode = focusNode->rightNode;

					if (focusNode == nullptr)
					{
						parentNode->rightNode = newNode;
						return;
					}
				}
			}
		}
	};

	void inOrderTraverseTree(Node* focusNode)
	{
		if (focusNode != nullptr)
		{
			inOrderTraverseTree(focusNode->leftNode);

			std::cout << focusNode->value << std::endl;

			inOrderTraverseTree(focusNode->rightNode);
		}
	};

};