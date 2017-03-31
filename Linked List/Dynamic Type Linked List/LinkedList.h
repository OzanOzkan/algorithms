#pragma once

template <class T>
class MyLinkedList
{
private:
	template <class T>
	struct Node
	{
		T value;
		Node<T>* next;
	};

public:
	MyLinkedList()
		: m_head(nullptr), m_length(0)
	{
	}

	bool AddValue(T value)
	{
		Node<T> *node = new Node<T>();
		node->value = value;
		node->next = m_head;
		m_head = node;

		m_length++;

		return true;
	}

	T GetValue(int index)
	{
		Node<T>* current = nullptr;
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

	int GetLength()
	{
		return m_length;
	}

private:
	Node<T>* m_head;
	int m_length;
};