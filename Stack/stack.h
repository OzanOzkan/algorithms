#pragma once
// Stack
// Ozan Ozkan - 22/04/2017

template <class T>
class MyStack {
private:
	T* elements;
	int size;
	int elementcount;

public:
	MyStack(int size)
	{
		elements = new T[size];
		this->size = size;
		this->elementcount = -1;
	};

	~MyStack()
	{
		delete[] elements;
	}

	void Push(T element)
	{
		if (elementcount != size)
		{
			elementcount++;
			elements[elementcount] = element;
		}
	};

	T Pop()
	{
		if (elementcount >= 0)
		{
			T temp = elements[elementcount];
			this->elementcount--;

			return temp;
		}
	};
};