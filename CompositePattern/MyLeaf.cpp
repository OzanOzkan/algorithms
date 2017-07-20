#include "stdafx.h"
#include "MyLeaf.h"
#include <iostream>


MyLeaf::MyLeaf()
{
}


MyLeaf::~MyLeaf()
{
}

std::string MyLeaf::getName() const
{
	return m_name;
}

int MyLeaf::getId() const
{
	return m_id;
}

void MyLeaf::setName(std::string &&name)
{
	m_name = name;
}

void MyLeaf::setId(int id)
{
	m_id = id;
}

void MyLeaf::getComponentInfo() 
{
	std::cout << getId() << " " << getName() << std::endl;
}
