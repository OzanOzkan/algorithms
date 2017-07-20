#pragma once
#include "MyComponent.h"

class MyComposite :
	public MyComponent
{
public:
	MyComposite();
	~MyComposite();

	virtual void add(std::unique_ptr<MyComponent>) override final;
	virtual void remove(const int id) override final;
	virtual MyComponent* getComponent(int componentIndex) const override final;
	virtual void getComponentInfo() override final;


	virtual std::string getName() const override final;
	virtual int getId() const override final;
	virtual void setName(std::string &&name) override final;
	virtual void setId(int id) override final;

private:
	std::vector<std::unique_ptr<MyComponent>> m_Components;

	std::string m_name;
	int m_id;
};

