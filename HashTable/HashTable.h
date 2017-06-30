#pragma once
// HashTable
// Ozan Ozkan - 30/06/2017

#include <string>

using namespace std;

class HashTable {
public:
	HashTable(int tableSize);
	void Push(string key, int value);
	int Get(string value);

private:
	struct HashEntry {
	public:
		HashEntry(string key, int value) { m_key = key; m_value = value; m_nextEntry = nullptr; }
		
		string getKey() { return m_key; }
		int getValue() { return m_value; }
		
		void setNextEntry(HashEntry* value) { m_nextEntry = value; }
		HashEntry* getNextEntry() { return m_nextEntry; }

	private:
		string m_key;
		int m_value;
		HashEntry* m_nextEntry;
	};

	int Hash(string value);

	int m_tableSize;
	HashEntry** m_hashTable;

};