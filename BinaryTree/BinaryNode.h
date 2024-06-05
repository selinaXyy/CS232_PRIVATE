#ifndef _BINARY_NODE
#define _BINARY_NODE

class BinaryNode {
private:
	int item;
	BinaryNode* leftChildPtr; //pointer to the left child
	BinaryNode* rightChildPtr; //pointer to the right child
public:
	BinaryNode();
	BinaryNode(const int& anItem);
	BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr);
	void setItem(const int& anItem);
	int getItem() const;
	bool isLeaf() const;

	BinaryNode* getLeftChildPtr() const;
	BinaryNode* getRightChildPtr() const;

	void setLeftChildPtr(BinaryNode* leftPtr);
	void setRightChildPtr(BinaryNode* rightPtr);
};

#endif // !_BINARY_NODE
