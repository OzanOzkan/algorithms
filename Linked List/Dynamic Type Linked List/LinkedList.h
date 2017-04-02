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

	bool PushFront(T value)
	{
		Node<T> *node = new Node<T>();

		node->value = value;

		if (m_head != nullptr)
		{
			node->next = m_head;
		}

		m_head = node;
		m_length++;

		return true;
	}

	bool PushBack(T value)
	{
		Node<T> *node = new Node<T>();

		node->value = value;
		node->next = nullptr;

		if(m_head != nullptr)
		{
			Node<T> *currentNode = m_head;

			do
			{
				if (currentNode->next == nullptr)
				{
					currentNode->next = node;
					break;
				}

			} while ((currentNode = currentNode->next) != nullptr);
		}
		else
		{
			m_head = node;
		}

		m_length++;

		return true;
	}

	T GetValue(int index)
	{
		Node<T>* current = m_head;
		int indexCount = 0;

		if (m_length > 0)
		{
			do
			{
				if (indexCount == index)
				{
					return current->value;
				}

				indexCount++;

			} while ((current = current->next) != nullptr);
		}
	}

	int GetLength()
	{
		return m_length;
	}

private:
	Node<T>* m_head;
	int m_length;
};