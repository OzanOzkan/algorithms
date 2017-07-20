#pragma once
#include "MyComponent.h"

class MyLeaf :
	public MyComponent
{
public:
	MyLeaf();
	~MyLeaf();

	// MyComponent
	virtual void add(std::unique_ptr<MyComponent>) override final { assert(true); }
	virtual void remove(const int id) override final { assert(true); }
	virtual MyComponent* getComponent(int componentIndex) const override final { assert(true); return nullptr; }

	virtual std::string getName() const override final;
	virtual int getId() const override final;
	virtual void setName(std::string &&name) override final;
	virtual void setId(int id) override final;

	virtual void getComponentInfo() override final;

private:
	std::string m_name;
	int m_id;
};

