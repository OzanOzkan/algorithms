#include "stdafx.h"
#include "Heap.h"


Heap::Heap()
	: m_size(5)
{
	m_minHeap = new int[5];
	m_maxHeap = new int[5];

	for (int i = 0; i < m_size; ++i)
	{
		m_minHeap[i] = -1;
		m_maxHeap[i] = -1;
	}
}


Heap::~Heap()
{
}

void Heap::Push(int value)
{
	if (m_maxHeap[0] == -1)
		m_maxHeap[0] = value;
	else
		Push(0, value);	
}

void Heap::Push(int i, int value)
{
	int leftNode = 2 * i + 1;
	int rightNode = 2 * i + 2;
	int pushedNode = -1;

	if (leftNode < m_size && m_maxHeap[leftNode] == -1)
	{
		m_maxHeap[leftNode] = value;
		pushedNode = leftNode;
	}
	else
		if (rightNode < m_size && m_maxHeap[rightNode] == -1)
		{
			m_maxHeap[rightNode] = value;
			pushedNode = rightNode;
		}
		else
			if (i + 1 < m_size)
			{
				Push(i + 1, value);
			}
			else
			{
				ExpandArray();
				Push(i + 1, value);
			}

	OrganizeMax(pushedNode);
}

void Heap::ExpandArray()
{
	int newSize = m_size * 3;
	int* tempArray = new int[newSize];

	for (int i = 0; i < m_size; ++i)
	{
		tempArray[i] = m_maxHeap[i];
	}

	for(int j = m_size; j < newSize; ++j)
	{
		tempArray[j] = -1;
	}

	delete[](m_maxHeap);
	m_maxHeap = tempArray;
	m_size = newSize;
}

void Heap::MinimizeArray()
{
	int newSize = m_size / 3;
	int* tempArray = new int[newSize];

	for (int i = 0; i < m_size; ++i)
	{
		tempArray[i] = m_maxHeap[i];
	}

	for (int j = m_size; j < newSize; ++j)
	{
		tempArray[j] = -1;
	}

	delete[](m_maxHeap);
	m_maxHeap = tempArray;
	m_size = newSize;
}

int Heap::Pop()
{
	int returnVal = m_maxHeap[0];
	
	int i = 0;

	while (m_maxHeap[i] != -1)
		++i;

	m_maxHeap[0] = m_maxHeap[i-1];
	m_maxHeap[i-1] = -1;

	for(int j=0; j<i; ++j)
		OrganizeMax(j);

	if (i - 1 < m_size / 3)
		MinimizeArray();

	return returnVal;
}

void Heap::Print()
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << " Node: " << i << " Value: " << m_maxHeap[i] << std::endl;
	}
}

void Heap::OrganizeMax(int pushedNode)
{
	if (pushedNode != -1)
	{
		int rootOfPushedNode = floor((pushedNode - 1) / 2);
		int temp = -1;

		if (m_maxHeap[rootOfPushedNode] < m_maxHeap[pushedNode])
		{
			temp = m_maxHeap[rootOfPushedNode];
			m_maxHeap[rootOfPushedNode] = m_maxHeap[pushedNode];
			m_maxHeap[pushedNode] = temp;

			OrganizeMax(rootOfPushedNode);
		}
	}
}
