#include<iostream>
#include "IntegerLinkStack.h"
using namespace std;

int main() {
	IntegerLinkStack* stackPtr = new IntegerLinkStack();

	char tryAgain = 'Y';
	int choice;
	int item;

	while (tryAgain == 'Y' || tryAgain == 'y') {
		system("cls"); //clear the screen

		cout << "Stack operations using arrays" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "____________" << endl;
		cout << "Enter your choice: ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Integer item to be pushed: ";
			cin >> item;
			stackPtr->push(item);
			break;
		case 2:
			cout << "Integer item popped: " << stackPtr->pop();
			break;
		case 3:
			cout << "Peek value is: " << stackPtr->peek();
			break;
		case 4:
			cout << "Contents of the stack" << endl;
			stackPtr->display();
			break;
		default:
			break;
		}

		cout << endl << "Try again (y/n)? ";
		cin >> tryAgain;
	}

	delete stackPtr;
	stackPtr = nullptr;
	system("pause");
	return 0;
}