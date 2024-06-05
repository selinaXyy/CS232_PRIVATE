#include "BinaryNodeTree.h" 
#include "BinaryNode.h" 
#include <iostream>
#include <algorithm> //std::max
using namespace std;
//////////////////////////////////////////////////////////////
//      Protected Utility Methods Section
//////////////////////////////////////////////////////////////

int BinaryNodeTree::getHeightHelper(BinaryNode* subTreePtr) const
{
	
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + max(getHeightHelper(subTreePtr->getLeftChildPtr()),
			getHeightHelper(subTreePtr->getRightChildPtr()));
}  // end getHeightHelper

int BinaryNodeTree::getNumberOfNodesHelper(BinaryNode* subTreePtr) const
{
	if (subTreePtr == nullptr)
		return 0;
	else
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())
		+ getNumberOfNodesHelper(subTreePtr->getRightChildPtr());
}  // end getNumberOfNodesHelper

BinaryNode* BinaryNodeTree::balancedAdd(BinaryNode* subTreePtr,
	BinaryNode* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	else
	{
		BinaryNode* leftPtr = subTreePtr->getLeftChildPtr();
		BinaryNode* rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr->setLeftChildPtr(leftPtr);
		}  // end if

		return subTreePtr;
	}  // end if
}  // end balancedAdd

BinaryNode* BinaryNodeTree::moveValuesUpTree(BinaryNode* subTreePtr)
{
	BinaryNode* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode* rightPtr = subTreePtr->getRightChildPtr();
	int leftHeight = getHeightHelper(leftPtr);
	int rightHeight = getHeightHelper(rightPtr);
	if (leftHeight > rightHeight)
	{
		subTreePtr->setItem(leftPtr->getItem());
		leftPtr = moveValuesUpTree(leftPtr);
		subTreePtr->setLeftChildPtr(leftPtr);
		return subTreePtr;
	}
	else
	{
		if (rightPtr != nullptr)
		{
			subTreePtr->setItem(rightPtr->getItem());
			rightPtr = moveValuesUpTree(rightPtr);
			subTreePtr->setRightChildPtr(rightPtr);
			return subTreePtr;
		}
		else
		{
			//this was a leaf!
			// value not important
			delete subTreePtr;
			return nullptr;
		}  // end if
	}  // end if   
}  // end moveValuesUpTree

/** Depth-first search of tree for item.
 @param subTreePtr  tree to search.
 @param target  target item to find.
 @param success  communicate to client we found it.
 @returns  A pointer to node containing the item. */

BinaryNode* BinaryNodeTree::removeValue(BinaryNode* subTreePtr,
	const int target,
	bool& success)
{
	if (subTreePtr == nullptr) // not found here
		return nullptr;

	if (subTreePtr->getItem() == target) // found it
	{
		subTreePtr = moveValuesUpTree(subTreePtr);
		success = true;
		return subTreePtr;
	}
	else
	{
		BinaryNode* targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setLeftChildPtr(targetNodePtr);
		if (!success) // no need to search right subTree
		{
			targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
			subTreePtr->setRightChildPtr(targetNodePtr);
		}  // end if

		return subTreePtr;
	}  // end if
}  // end removeValue

BinaryNode* BinaryNodeTree::findNode(BinaryNode* treePtr,
	const int& target,
	bool& success) const
{
	if (treePtr == nullptr) // not found here
		return nullptr;

	if (treePtr->getItem() == target) // found it
	{
		success = true;
		return treePtr;
	}
	else
	{
		BinaryNode* targetNodePtr = findNode(treePtr->getLeftChildPtr(), target, success);
		if (!success) // no need to search right subTree
		{
			targetNodePtr = findNode(treePtr->getRightChildPtr(), target, success);
		}  // end if

		return targetNodePtr;
	}  // end if 
}  // end findNode

BinaryNode* BinaryNodeTree::copyTree(const BinaryNode* treePtr) const
{
	BinaryNode* newTreePtr = nullptr;
	// Copy tree nodes during a preorder traversal
	if (treePtr != nullptr)
	{
		// Copy node
		newTreePtr = new BinaryNode(treePtr->getItem(), nullptr, nullptr);
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}  // end if

	return newTreePtr;
}  // end copyTree

void BinaryNodeTree::destroyTree(BinaryNode* subTreePtr)
{
	if (subTreePtr != nullptr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}  // end if
}  // end destroyTree

//////////////////////////////////////////////////////////////
//      Protected Tree Traversal Sub-Section
//////////////////////////////////////////////////////////////

void BinaryNodeTree::preorder(void visit(int&), BinaryNode* treePtr) const
{
	if (treePtr != nullptr)
	{
		int theItem = treePtr->getItem();
		visit(theItem);
		preorder(visit, treePtr->getLeftChildPtr());
		preorder(visit, treePtr->getRightChildPtr());
	}  // end if
}  // end preorder

void BinaryNodeTree::inorder(void visit(int&), BinaryNode* treePtr) const
{
	if (treePtr != nullptr)
	{
		inorder(visit, treePtr->getLeftChildPtr());
		int theItem = treePtr->getItem();
		visit(theItem);
		inorder(visit, treePtr->getRightChildPtr());
	}  // end if
}  // end inorder

void BinaryNodeTree::postorder(void visit(int&), BinaryNode* treePtr) const
{
	if (treePtr != nullptr)
	{
		postorder(visit, treePtr->getLeftChildPtr());
		postorder(visit, treePtr->getRightChildPtr());
		int theItem = treePtr->getItem();
		visit(theItem);
	} // end if
}  // end postorder

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////
//      Constructor and Destructor Section
//////////////////////////////////////////////////////////////

BinaryNodeTree::BinaryNodeTree()
{
	rootPtr = nullptr;
}  

BinaryNodeTree::BinaryNodeTree(const int& rootItem)
{
	rootPtr = new BinaryNode(rootItem, nullptr, nullptr);
}  

BinaryNodeTree::BinaryNodeTree(const int& rootItem,
	const BinaryNodeTree* leftTreePtr,
	const BinaryNodeTree* rightTreePtr)
{
	rootPtr = new BinaryNode(rootItem, copyTree(leftTreePtr->rootPtr),
		copyTree(rightTreePtr->rootPtr));
}  // end constructor


BinaryNodeTree::BinaryNodeTree(const BinaryNodeTree& tree)
{
	rootPtr = copyTree(tree.rootPtr);
}  // end copy constructor


BinaryNodeTree::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}  // end destructor

//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section
//////////////////////////////////////////////////////////////

bool BinaryNodeTree::isEmpty() const
{
	return rootPtr == nullptr;
}  // end isEmpty


int BinaryNodeTree::getHeight() const
{
	return getHeightHelper(rootPtr);
}  // end getHeight


int BinaryNodeTree::getNumberOfNodes() const
{
	return getNumberOfNodesHelper(rootPtr);
}  // end getNumberOfNodes

void BinaryNodeTree::clear()
{
	destroyTree(rootPtr);
	rootPtr = nullptr;
}  // end clear


//int BinaryNodeTree::getRootData() const throw(PrecondViolatedExcep)
int BinaryNodeTree::getRootData() const
{
	if (!isEmpty())
		//throw PrecondViolatedExcep("getRootData() called with empty tree.");
	{
		return rootPtr->getItem();
	}
}  // end getRootData

void BinaryNodeTree::setRootData(const int& newItem)
{
	if (isEmpty())
		rootPtr = new BinaryNode(newItem, nullptr, nullptr);
	else
		rootPtr->setItem(newItem);
}  // end setRootData

bool BinaryNodeTree::add(const int& newData)
{
	BinaryNode* newNodePtr = new BinaryNode(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}  // end add

bool BinaryNodeTree::remove(const int& target)
{
	bool isSuccessful = false;
	rootPtr = removeValue(rootPtr, target, isSuccessful);
	return isSuccessful;
}  // end remove

int BinaryNodeTree::getEntry(const int& anEntry) const // throw(NotFoundException)
{
	bool isSuccessful = false;
	BinaryNode* binaryNodePtr = findNode(rootPtr, anEntry, isSuccessful);

	if (isSuccessful)
		return binaryNodePtr->getItem();
	else
		cout << "Entry not found in tree" << endl;
		//throw NotFoundException("Entry not found in tree!");
}  // end getEntry

bool BinaryNodeTree::contains(const int& anEntry) const
{
	bool isSuccessful = false;
	findNode(rootPtr, anEntry, isSuccessful);
	return isSuccessful;
}  // end contains

//////////////////////////////////////////////////////////////
//      Public Traversals Section
//////////////////////////////////////////////////////////////

void BinaryNodeTree::preorderTraverse(void visit(int&)) const
{
	preorder(visit, rootPtr);
}  // end preorderTraverse

void BinaryNodeTree::inorderTraverse(void visit(int&)) const
{
	inorder(visit, rootPtr);
}  // end inorderTraverse

void BinaryNodeTree::postorderTraverse(void visit(int&)) const
{
	postorder(visit, rootPtr);
}  // end postorderTraverse

//////////////////////////////////////////////////////////////
//      Overloaded Operator 
//////////////////////////////////////////////////////////////

//BinaryNodeTree& BinaryNodeTree::operator=(const BinaryNodeTree& rightHandSide)
BinaryNode& BinaryNodeTree::operator=(const BinaryNodeTree& rightHandSide)
{
	if (!isEmpty()) {
		clear();
	}

	//this = copyTree(&rightHandSide);
	rootPtr = copyTree(rightHandSide.rootPtr);
	return *rootPtr;
}  // end operator=


