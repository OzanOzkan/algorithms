#include "stdafx.h"
#include "HashTable.h"

HashTable::HashTable(int tableSize)
: m_tableSize(tableSize)
{
	m_hashTable = new HashEntry*[tableSize];

	for (int i=0; i < m_tableSize; ++i)
	{
		m_hashTable[i] = nullptr;
	}
}

void HashTable::Push(string key, int value)
{
	int hash = Hash(key);

	if(m_hashTable[hash] == nullptr)
		m_hashTable[hash] = new HashEntry(key, value);
	else
	{
		HashEntry* tempEntry = m_hashTable[hash];

		if (tempEntry->getNextEntry() != nullptr)
		{
			while (tempEntry->getNextEntry() != nullptr)
			{
				tempEntry = tempEntry->getNextEntry();
			}
		}

		tempEntry->setNextEntry(new HashEntry(key, value));
	}
}

int HashTable::Get(string key)
{
	int hash = Hash(key);

	if (m_hashTable[hash]->getKey() == key)
		return m_hashTable[hash]->getValue();
	else
	{
		HashEntry* tempEntry = m_hashTable[hash];
		
		while (tempEntry->getKey() != key)
		{
			tempEntry = tempEntry->getNextEntry();
		}

		if (tempEntry->getKey() == key)
			return tempEntry->getValue();
		else
			return -1;
	}
}

int HashTable::Hash(string key)
{
	int tempValue = 0;

	for (char c : key)
	{
		tempValue += (int)c;
	}

	return tempValue % m_tableSize;
}