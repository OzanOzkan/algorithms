#include "stdafx.h"
#include "LinkedList.h"

MyLinkedList::MyLinkedList()
	: m_head(nullptr), m_length(0)
{
}

bool MyLinkedList::AddValue(int value)
{
	Node *node = new Node();
	node->value = value;
	node->next = m_head;
	m_head = node;

	m_length++;

	return true;
}

int MyLinkedList::GetValue(int index)
{
	Node* current = nullptr;
	int indexCount = 0;

	if (m_head != nullptr)
	{
		do {

			if (index == 0)
			{
				return m_head->value;
			}
			else if (indexCount > index)
			{
				return current->value;
			}

			indexCount++;

		} while ((current = m_head->next) != nullptr);
	}

	return 0;
}

int MyLinkedList::GetLength()
{
	return m_length;
}
