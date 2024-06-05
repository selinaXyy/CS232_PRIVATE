#ifndef _BINARY_NODE_TREE
#define _BINARY_NODE_TREE

#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

class BinaryNodeTree : public BinaryTreeInterface {
private:
	BinaryNode* rootPtr;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------

	int getHeightHelper(BinaryNode* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode* subTreePtr) const;

	// Recursively deletes all nodes from the tree.
	void destroyTree(BinaryNode* subTreePtr);

	// Recursively adds a new node to the tree in a left/right fashion to
	// keep the tree balanced.
	BinaryNode* balancedAdd(BinaryNode* subTreePtr,
		BinaryNode* newNodePtr);

	// Removes the target value from the tree by calling moveValuesUpTree
	// to overwrite value with value from child.
	BinaryNode* removeValue(BinaryNode* subTreePtr,
		const int target, bool& success);

	// Copies values up the tree to overwrite value in current node until
	// a leaf is reached; the leaf is then removed, since its value is
	// stored in the parent.
	BinaryNode* moveValuesUpTree(BinaryNode* subTreePtr);

	// Recursively searches for target value in the tree by using a
	// preorder traversal.
	BinaryNode* findNode(BinaryNode* treePtr,
		const int& target,
		bool& success) const;

	// Copies the tree rooted at treePtr and returns a pointer to
	// the copy.
	BinaryNode* copyTree(const BinaryNode* treePtr) const;

	// Recursive traversal helper methods:
	void preorder(void visit(int&), BinaryNode* treePtr) const;
	void inorder(void visit(int&), BinaryNode* treePtr) const;
	void postorder(void visit(int&), BinaryNode* treePtr) const;

public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	BinaryNodeTree();
	BinaryNodeTree(const int& rootItem);
	BinaryNodeTree(const int& rootItem, const BinaryNodeTree* leftTreePtr, const BinaryNodeTree* rightTreePtr);
	BinaryNodeTree(const BinaryNodeTree& tree);
	virtual ~BinaryNodeTree();

	//------------------------------------------------------------
	// Public BinaryTreeInterface Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	int getRootData() const;// throw(PrecondViolatedExcep);
	void setRootData(const int& newData);
	bool add(const int& newData); // Adds a node
	bool remove(const int& data); // Removes a node
	void clear();
	int getEntry(const int& anEntry) const;// throw(NotFoundException);
	bool contains(const int& anEntry) const;

	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void preorderTraverse(void visit(int&)) const;
	void inorderTraverse(void visit(int&)) const;
	void postorderTraverse(void visit(int&)) const;

	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	BinaryNode& operator=(const BinaryNodeTree& rightHandSide);
};
#endif // !_BINARY_NODE_TREE
