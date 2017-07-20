#include "stdafx.h"
#include "MyComposite.h"
#include <iostream>


MyComposite::MyComposite()
{
}


MyComposite::~MyComposite()
{
}

void MyComposite::add(std::unique_ptr<MyComponent> component)
{
	m_Components.push_back(std::move(component));
}

void MyComposite::remove(const int id)
{
	for (auto it = m_Components.begin(); it != m_Components.end(); ++it) {
		if ((*it).get()->getId() == id) {
			m_Components.erase(it);
			return;
		}
	}
}

MyComponent * MyComposite::getComponent(int componentIndex) const
{
	if (componentIndex < m_Components.size())
		return m_Components[componentIndex].get();
	else
		return nullptr;
}

void MyComposite::getComponentInfo()
{
	std::cout << getId() << " " << getName() << std::endl;

	for (std::unique_ptr<MyComponent> &component : m_Components)
	{
		component->getComponentInfo();
	}
}

std::string MyComposite::getName() const
{
	return m_name;
}

int MyComposite::getId() const
{
	return m_id;
}

void MyComposite::setName(std::string &&name)
{
	m_name = name;
}

void MyComposite::setId(int id)
{
	m_id = id;
}
