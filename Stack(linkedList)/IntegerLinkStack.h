#ifndef _INTEGER_LINK_STACK
#define _INTEGER_LINK_STACK

#include "Node.h"
class IntegerLinkStack {
private:
	Node* topPtr;
public:
	IntegerLinkStack();
	IntegerLinkStack(const IntegerLinkStack& aStack); //copy constructor
	virtual ~IntegerLinkStack(); //destructor
	bool isEmpty() const;
	bool push(const int& newItem);
	bool pop();
	int peek() const;
	void display();
};

#endif