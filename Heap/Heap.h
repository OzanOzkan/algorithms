#pragma once

// Heap (with Array)
// Ozan Ozkan - 06/07/2017

#include <iostream>

class Heap
{
public:
	Heap();
	~Heap();

	void Push(int value);
	void Print();
	int Pop();

private:
	void OrganizeMax(int pushedNode);
	void Push(int i, int value);
	void ExpandArray();
	void MinimizeArray();

private:
	int* m_minHeap;
	int* m_maxHeap;
	int m_size;
};

