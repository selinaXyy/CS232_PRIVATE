#include<cassert>
#include<iostream>
#include"IntegerLinkStack.h"
using namespace std;

IntegerLinkStack::IntegerLinkStack(){
	topPtr = nullptr;
}
IntegerLinkStack::IntegerLinkStack(const IntegerLinkStack& aStack) {
	//point to nodes in the original chain
	Node* origChainPtr = aStack.topPtr;

	if (origChainPtr == nullptr)
		topPtr = nullptr; //original bag is empty
	else {
		//copy first node
		topPtr = new Node();
		topPtr->setItem(origChainPtr->getItem());

		//point to first node in the new chain
		Node* newChainPtr = topPtr;

		//copy remaining nodes
		while (origChainPtr != nullptr) {
			//advance original-chain pointer
			origChainPtr = origChainPtr->getNext();

			//get next item from original chain
			int nextItem = origChainPtr->getItem();

			//create a new node containing the next item
			Node* newNodePtr = new Node(nextItem);

			//link new node to end of new chain
			newChainPtr->setNext(newNodePtr);

			//advance pointer to new last node
			newChainPtr = newChainPtr->getNext();
		} // end while
		newChainPtr->setNext(nullptr); //indicate end of chain
	}
}
IntegerLinkStack::~IntegerLinkStack() { //destructor
	//pop until stack is empty
	while (!isEmpty())
		pop();
}
bool IntegerLinkStack::isEmpty() const {
	return topPtr == nullptr;
}
bool IntegerLinkStack::push(const int& newItem) {
	Node* newNodePtr = new Node(newItem, topPtr);
	topPtr = newNodePtr;
	newNodePtr = nullptr;

	return true;
}
bool IntegerLinkStack::pop() {
	bool result = false;
	if (!isEmpty()) {
		//stack is not empty; delete top
		Node* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();

		//return deleted node to system
		nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		result = true;
	}

	return result;
}
int IntegerLinkStack::peek() const {
	assert(!isEmpty()); //enfore precondition

	return topPtr->getItem(); //stack is not empty, return top
}

void IntegerLinkStack::display() {
	Node* curPtr = topPtr;

	if (curPtr == nullptr)
		cout << "No elements to display." << endl;

	while (curPtr != nullptr) {
		cout << curPtr->getItem() << " ";
		curPtr = curPtr->getNext();
	}
	cout << endl;
}