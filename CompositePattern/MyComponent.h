#pragma once
#include <string>
#include <memory>
#include <assert.h>
#include <vector>

class MyComponent
{
public:
	// Pure virtuals with =0 or {} ?

	// For Composite implementation
	virtual void add(std::unique_ptr<MyComponent>) = 0;
	virtual void remove(const int id) = 0;
	virtual MyComponent* getComponent(int componentIndex) const = 0;
	virtual void getComponentInfo() = 0;

	// For leaf implementation
	virtual std::string getName() const = 0;
	virtual int getId() const = 0;
	virtual void setName(std::string &&name) = 0;
	virtual void setId(int id) = 0;
};

