#pragma once

// Trie Data Structure
// Ozan Ozkan - 10/07/2017

#include <map>
#include <string>

using namespace std;

struct TrieNode {
public:
	TrieNode() : m_endOfWord(false) {};
	
	void destroyNode();
	void addLink(char c);
	TrieNode* getLink(char c);
	void removeLink(char c);
	int getLinkCount();
	bool isEndOfWord();
	void setEndOfWord(bool value);

private:
	map<char, TrieNode*> m_CharLinks;
	bool m_endOfWord;
};

class Trie
{
public:
	Trie();
	~Trie();

	void addWord(string word);
	bool isWordExists(string word);
	bool isPrefixExists(string prefix);
	bool deleteWord(string word);

private:
	bool deleteWord(string word, TrieNode* node, int index);

private:
	TrieNode* m_rootNode;
};

