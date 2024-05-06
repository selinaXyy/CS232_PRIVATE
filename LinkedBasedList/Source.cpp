#include<iostream>
#include<string>
#include"LinkedList.h"
using namespace std;

int main() {
	ListInterface* listPtr = new LinkedList();

	int choice;
	int userNum;
	int position;
	char tryAgain = 'Y';

	while (tryAgain == 'y' || tryAgain == 'Y') {
		system("cls"); //clear the screen

		cout << "List operations using an array list" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Remove" << endl;
		cout << "3. Clear" << endl;
		cout << "4. isEmpty" << endl;
		cout << "5. Get Length" << endl;
		cout << "6. Get an entry at a given position" << endl;
		cout << "7. Set an entry at a given position" << endl;
		cout << "8. Display list" << endl;

		cout << "Enter a choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Insert an integer at a specified position." << endl;
			cout << "What is the integer: ";
			cin >> userNum;
			cout << "In what position shall we place this entry:";
			cin >> position;

			if (listPtr->insert(position, userNum))
				cout << "Inserted " << listPtr->getEntry(position) << " at position " << position << endl;
			else
				cout << "Cannot insert " << userNum << " at position " << position << endl;
			break;
		case 2:
			cout << "Remove item in position: ";
			cin >> userNum;

			listPtr->remove(userNum);
			break;
		case 3:
			cout << "The list is cleared";
			listPtr->clear();
			break;
		case 4:
			if (listPtr->isEmpty())
				cout << "This list is empty";
			else
				cout << "This list is not empty";
			break;
		case 5:
			cout << "The items in the list is ";
			cout << listPtr->getLength();
			break;
		case 6:
			cout << "Get the entry at position: ";
			cin >> userNum;
			cout << listPtr->getEntry(userNum);
			break;
		case 7:
			cout << "Replace the number at position:";
			cin >> position;
			cout << "with the value: ";
			cin >> userNum;

			listPtr->setEntry(position, userNum);
			break;
		case 8:
			cout << "List contents: ";
			for (int i = 1; i <= listPtr->getLength(); i++) {
				cout << listPtr->getEntry(i) << " ";
			}
			break;

		default:
			break;
		}

		cout << endl << "Try again (Y/N): ";
		cin >> tryAgain;
	}
	listPtr->clear();
	delete listPtr;
	listPtr = nullptr;

	system("pause");
	return 0;
}