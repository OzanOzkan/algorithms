#include "stdafx.h"
#include "Trie.h"


Trie::Trie() 
{
	m_rootNode = new TrieNode();
}


Trie::~Trie()
{
}

void Trie::addWord(string word)
{
	TrieNode* currentNode = m_rootNode;

	for (char c : word)
	{
		if (currentNode->getLink(c) == nullptr)
			currentNode->addLink(c);

		currentNode = currentNode->getLink(c);
	}

	currentNode->setEndOfWord(true);
}

bool Trie::isWordExists(string word)
{
	if (m_rootNode == nullptr)
		return false;
	TrieNode* currentNode = m_rootNode;

	for (char c : word)
	{
		if (currentNode->getLink(c))
		{
			if (!currentNode->isEndOfWord())
				currentNode = currentNode->getLink(c);
		}
		else
			return false;
	}

	return currentNode->isEndOfWord();
}

bool Trie::isPrefixExists(string prefix)
{
	TrieNode* currentNode = m_rootNode;
	bool returnVal = false;

	for (char c : prefix)
	{
		if (currentNode->getLink(c))
		{
			currentNode = currentNode->getLink(c);
			returnVal = true;
		}
		else
			returnVal = false;
	}

	return returnVal;
}

bool Trie::deleteWord(string word)
{
	deleteWord(word, m_rootNode, 0);

	return true;
}

bool Trie::deleteWord(string word, TrieNode * node, int index)
{
	bool check = false;

	if (index < word.length())
		check = deleteWord(word, node->getLink(word[index]), index + 1);

	if (node->getLinkCount() == 0)
	{
		delete node;
		return true;
	}

	if (check)
	{
		node->removeLink(word[index]);
		
		if (node->getLinkCount() == 0 && !node->isEndOfWord())
		{
			if (node == m_rootNode)
				m_rootNode = nullptr;
			else
				delete node;
			
			return true;
		}
	}
	else
	{
		node->setEndOfWord(false);
		return false;
	}

	return false;
}

void TrieNode::destroyNode()
{
	if(m_CharLinks.size() == 0)
		delete[](this);
}	

void TrieNode::addLink(char c)
{
	m_CharLinks.insert(make_pair(c, new TrieNode()));
}

TrieNode* TrieNode::getLink(char c)
{
	TrieNode* returnNode = nullptr;

	if (m_CharLinks.size() > 0)
	{
		map<char, TrieNode*>::iterator itr = m_CharLinks.find(c);

		if (itr != m_CharLinks.end())
			returnNode = itr->second;
	}

	return returnNode;
}

void TrieNode::removeLink(char c)
{
	m_CharLinks.erase(c);
}

int TrieNode::getLinkCount()
{
	return m_CharLinks.size();
}

bool TrieNode::isEndOfWord()
{
	return m_endOfWord;
}

void TrieNode::setEndOfWord(bool value)
{
	m_endOfWord = value;
}
