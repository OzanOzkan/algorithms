#pragma once

class MyLinkedList
{
private:
	struct Node
	{
		int value;
		Node* next;
	};

public:
	MyLinkedList();
	virtual bool          AddValue(int value);
	virtual int           GetValue(int index);
	virtual int           GetLength();

private:
	Node* m_head;
	int m_length;
};