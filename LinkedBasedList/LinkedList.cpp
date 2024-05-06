#include"LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList() { //default constructor
	headPtr = nullptr;
	itemCount = 0;
}

LinkedList::LinkedList(const LinkedList& aList) { //copy constructor
	itemCount = aList.itemCount;

	Node* origChainPtr = aList.headPtr; //points to nodes in original chain
	if (origChainPtr == nullptr)
		headPtr = nullptr; //i.e., the original list is empty
	else {
		//copy the first node
		headPtr = new Node();
		headPtr->setItem(origChainPtr->getItem());

		//copy remaining nodes
		Node* newChainPtr = headPtr; //points to last node in new chain
		while (origChainPtr != nullptr) {
			// Get next item from original chain 
			int nextItem = origChainPtr->getItem();

			// Create a new node containing the next item 
			Node* newNodePtr = new Node(nextItem);

			// Link new node to end of new chain 
			newChainPtr->setNext(newNodePtr);

			// Advance pointer to new last node 
			newChainPtr = newChainPtr->getNext(); 
			origChainPtr = origChainPtr->getNext();
		}//end of while
		newChainPtr->setNext(nullptr); //flag end of chain
	}
}  //end of copy constructor

LinkedList::~LinkedList() {//destructor
	
	clear();
}

bool LinkedList::isEmpty() const {
	return itemCount == 0;
}

int LinkedList::getLength() const {
	return itemCount;
}

bool LinkedList::insert(int newPosition, const int& newEntry) {
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
	if (ableToInsert)
	{
		// Create a new node containing the new entry 
		Node* newNodePtr = new Node(newEntry);

		// Attach new node to chain
		if (newPosition == 1)
		{
			// Insert new node at beginning of chain
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			// Find node that will be before new node
			Node* prevPtr = getNodeAt(newPosition - 1);

			// Insert new node after node to which prevPtr points
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}  // end if

		itemCount++;  // Increase count of entries
	}  // end if

	return ableToInsert;
}

bool LinkedList::remove(int position) {
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	if (ableToRemove)
	{
		Node* curPtr = nullptr;
		if (position == 1)
		{
			// Remove the first node in the chain
			curPtr = headPtr; // Save pointer to node
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that is before the one to delete
			Node* prevPtr = getNodeAt(position - 1);

			// Point to node to delete
			curPtr = prevPtr->getNext();

			// Disconnect indicated node from chain by connecting the
			// prior node with the one after
			prevPtr->setNext(curPtr->getNext());
		}  // end if

		   // Return node to system
		curPtr->setNext(nullptr);
		//cout << "Removed curPtr" << endl;
		delete curPtr;
		curPtr = nullptr;

		itemCount -= 1;  // Decrease count of entries
	}  // end if

	return ableToRemove;
}

void LinkedList::clear() {
	while (!isEmpty())
		remove(1);
}

int LinkedList::getEntry(int position) const {
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		cout << "getEntry() called with an empty list or ";
		cout << "invalid position.";
		return -1;
	}
}

void LinkedList::setEntry(int position, const int& newEntry) {
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		Node* nodePtr = getNodeAt(position);
		nodePtr->setItem(newEntry);
	}
	else
	{
		cout << "setEntry() called with an invalid position.";
	}
}

Node* LinkedList::getNodeAt(int position) const {
	if ((position >= 1) && (position <= itemCount)) {
		Node* curPtr = headPtr;
		for (int skip = 1; skip < position; skip++)
			curPtr = curPtr->getNext();

		return curPtr;
	}
}