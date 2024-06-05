#include "BinaryNode.h"

BinaryNode::BinaryNode() {
	item = 0;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

BinaryNode::BinaryNode(const int& anItem) {
	item = anItem;
	leftChildPtr = nullptr;
	rightChildPtr = nullptr;
}

BinaryNode::BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr) {
	item = anItem;
	leftChildPtr = leftPtr;
	rightChildPtr = rightPtr;
}

void BinaryNode::setItem(const int& anItem) {
	item = anItem;
}

int BinaryNode::getItem() const {
	return item;
}

bool BinaryNode::isLeaf() const {
	return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

BinaryNode* BinaryNode::getLeftChildPtr() const {
	return leftChildPtr;
}

BinaryNode* BinaryNode::getRightChildPtr() const {
	return rightChildPtr;
}

void BinaryNode::setLeftChildPtr(BinaryNode* leftPtr) {
	leftChildPtr = leftPtr;
}

void BinaryNode::setRightChildPtr(BinaryNode* rightPtr) {
	rightChildPtr = rightPtr;
}