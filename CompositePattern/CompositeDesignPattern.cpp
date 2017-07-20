// CompositeDesignPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyComposite.h"
#include "MyLeaf.h"
#include <iostream>
#include <memory>

int main()
{
	int a;

	std::unique_ptr<MyComponent> compositeA = std::make_unique<MyComposite>();
	compositeA->setId(1);
	compositeA->setName("compositeA");

	std::unique_ptr<MyComponent> compositeB = std::make_unique<MyComposite>();
	compositeB->setId(2);
	compositeB->setName("compositeB");

	std::unique_ptr<MyComponent> leafA = std::make_unique<MyLeaf>();
	leafA->setId(0);
	leafA->setName("leafA");
	compositeA->add(std::move(leafA));

	std::unique_ptr<MyComponent> leafB = std::make_unique<MyLeaf>();
	leafB->setId(1);
	leafB->setName("leafB");
	compositeA->add(std::move(leafB));

	std::unique_ptr<MyComponent> leafC = std::make_unique<MyLeaf>();
	leafC->setId(2);
	leafC->setName("leafC");
	compositeA->add(std::move(leafC));

	compositeB->add(std::move(compositeA));

	compositeB->getComponentInfo();

	std::cin >> a;

    return 0;
}

