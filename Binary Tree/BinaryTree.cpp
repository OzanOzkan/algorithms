#include "stdafx.h"
#include "BinaryTree.h"

BinaryTree::BinaryTree() : m_rootNode(nullptr)
{
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::Insert(int value)
{
	if (m_rootNode == nullptr)
	{
		m_rootNode = new Node(value);
	}
	else
	{
		Insert(value, m_rootNode);
	}
}

Node * BinaryTree::Search(int value)
{
	return Search(value, m_rootNode);
}

void BinaryTree::Print()
{
	if (m_rootNode != nullptr)
		Print(m_rootNode);
	else
		std::cout << "Binary tree is empty." << std::endl;
}

void BinaryTree::Print(Node* leaf)
{
	std::cout << "Root: " << leaf->getValue() << std::endl;

	if(leaf->getLeftNode() != nullptr)
		std::cout << "Left: " << leaf->getLeftNode()->getValue() << std::endl;

	if (leaf->getRightNode() != nullptr)
		std::cout << "Right: " << leaf->getRightNode()->getValue() << std::endl;

	std::cout << std::endl;

	if (leaf->getLeftNode() != nullptr)
		Print(leaf->getLeftNode());

	if (leaf->getRightNode() != nullptr)
		Print(leaf->getRightNode());
}

Node * BinaryTree::Search(int value, Node * leaf)
{
	if (value == leaf->getValue())
		return leaf;

	if (value < leaf->getValue() && leaf->getLeftNode() != nullptr)
		return Search(value, leaf->getLeftNode());

	if (value > leaf->getValue() && leaf->getRightNode() != nullptr)
		return Search(value, leaf->getRightNode());
}

void BinaryTree::Insert(int value, Node * leaf)
{
	if (value < leaf->getValue())
	{
		if (leaf->getLeftNode() == nullptr)
		{
			leaf->setLeftNode(new Node(value));
		}
		else
		{
			Insert(value, leaf->getLeftNode());
		}
	}
	else
	{
		if (leaf->getRightNode() == nullptr)
		{
			leaf->setRightNode(new Node(value));
		}
		else
		{
			Insert(value, leaf->getRightNode());
		}
	}
}
