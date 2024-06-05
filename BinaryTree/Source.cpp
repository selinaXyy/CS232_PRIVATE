#include<iostream>
#include"BinaryNodeTree.h"
using namespace std;

int main() {
	BinaryNodeTree* binaryTreePtr = new BinaryNodeTree();
	char tryAgain = 'Y';
	int choice;
	int item;

	while (tryAgain == 'Y' || tryAgain == 'y')
	{
		system("cls");
		cout << "Tree operations - Link Based" << endl;
		cout << "1. isEmpty" << endl;
		cout << "2. getHeight" << endl;
		cout << "3. getNumberOfNodes" << endl;
		cout << "4. getRootData" << endl;
		cout << "5. setRootData" << endl;
		cout << "6. add" << endl;
		cout << "7. remove" << endl;
		cout << "8. clear" << endl;
		cout << "9. getEntry" << endl;
		cout << "10. contains" << endl;
		cout << "11. copy tree" << endl;
		cout << "----------------------------" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: //isEmpty
			cout << "Tree Empty: " << bool(binaryTreePtr->isEmpty()) << endl;
			break;
		case 2: //getHeight
			cout << "Tree Height: " << binaryTreePtr->getHeight() << endl;
			break;
		case 3: //getNumberOfNodes
			cout << "Tree Nodes: " << binaryTreePtr->getNumberOfNodes() << endl;
			break;
		case 4: //getRootData
			cout << "Tree root node value: " << binaryTreePtr->getRootData() << endl;
			break;
		case 5: //setRootData
			cout << "Set root node value to: ";
			cin >> item;
			binaryTreePtr->setRootData(item);
			break;
		case 6: //add
			cout << "Add value: ";
			cin >> item;
			cout << "Able to add item: " << binaryTreePtr->add(item) << endl;
			break;
		case 7: //remove
			cout << "Remove value: ";
			cin >> item;
			cout << "Able to remove item: " << binaryTreePtr->remove(item) << endl;
			break;
		case 8: //clear
			cout << "Cleared Tree";
			binaryTreePtr->clear();
			break;
		case 9: //getEntry
			cout << "Check tree for entry: ";
			cin >> item;
			cout << "Is this entry in the tree? " << binaryTreePtr->getEntry(item) << endl;
			break;
		case 10: //contains
			cout << "Check if tree contains: ";
			cin >> item;
			cout << "Does this tree contain " << item << "? " << binaryTreePtr->contains(item) << endl;
			break;
		case 11: //copy tree
			
		default:
			break;
		}
		cout << endl << "Try again (y/n): ";
		cin >> tryAgain;
	}
	
	if (!binaryTreePtr->isEmpty())
		binaryTreePtr->clear();

	delete binaryTreePtr;
	binaryTreePtr = nullptr;

	return 0;
}