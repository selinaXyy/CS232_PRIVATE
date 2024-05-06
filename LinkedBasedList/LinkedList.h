#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"

class LinkedList : public ListInterface {
private:
	Node* headPtr; //pointer to the 1st node in the chain. Contains the first entry in the list
	int itemCount;	//current count of list items

	// Locates a specified node in a linked list. 
	// @pre position is the number of the desired node; 
	//	position >= 1 and position <= itemCount. 
	// @post The node is found and a pointer to it is returned. 
	// @param position The number of the node to locate. 
	// @return A pointer to the node at the given position
	Node* getNodeAt(int position) const;
public:
	LinkedList();
	LinkedList(const LinkedList& aList);
	virtual ~LinkedList();

	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const int& newEntry);
	bool remove(int position);
	void clear();

	int getEntry(int position) const;
	void setEntry(int position, const int& newEntry);
};


#endif _LINKED_LIST
