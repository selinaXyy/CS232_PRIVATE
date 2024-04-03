#include <iostream>
#include <string>

using namespace std;

struct weirdShapeNode {
	string item;
	weirdShapeNode* link;
};

int main() {
	int userNum = 0;
	int totalParts = 4;
	int partCnt = 1;
	string partOutput = "";
	int spaceInside;

	while (userNum < 8 || userNum > 15) {
		cout << "Please enter a number between 8-15, and I will draw a weird shape for you: ";
		cin >> userNum;
		cout << endl;
	}

	weirdShapeNode* head = new weirdShapeNode;
	weirdShapeNode* currentNode = head;
	currentNode->link = nullptr;

	for (partCnt; partCnt <= totalParts; partCnt++) {
		//part 1
		if (partCnt == 1) {
			for (int i = 0; i < userNum; i++) {
				partOutput += "*";
			}
			partOutput += "\n";

			currentNode->item = partOutput;
			currentNode->link = new weirdShapeNode;
			currentNode = currentNode->link;
		}
		//part 2
		else if (partCnt == 2) {
			partOutput = "";
			int rectRows = (userNum / 2) - 1;
			spaceInside = userNum - 2;

			for (int i = 0; i < rectRows; i++) {
				partOutput += "*";
				for (int j = 0; j < spaceInside; j++) {
					partOutput += " ";
				}
				partOutput += "*\n";
			}

			currentNode->item = partOutput;
			currentNode->link = new weirdShapeNode;
			currentNode = currentNode->link;
		}
		//part 3
		else if (partCnt == 3) {
			partOutput = "";
			int trapezoidRows = ((userNum - 1) / 2);
			spaceInside = userNum - 3;

			for (int i = 0; i < trapezoidRows; i++) {
				partOutput += "*";
				for (int j = 0; j < spaceInside; j++) {
					partOutput += " ";
				}
				partOutput += "*\n";
				spaceInside--;
			}

			currentNode->item = partOutput;
			currentNode->link = new weirdShapeNode;
			currentNode = currentNode->link;
		}
		//part 4
		else {
			partOutput = "";
			int bottomRowStars = (userNum / 2);
			for (int i = 0; i < bottomRowStars; i++) {
				partOutput += "*";
			}
			partOutput += "\n";

			currentNode->item = partOutput;
			currentNode->link = nullptr;
		}
	}

	currentNode = head;
	while (currentNode != nullptr) {
		cout << currentNode->item;
		currentNode = currentNode->link;
	}

	currentNode = head;
	while (currentNode != nullptr) {
		weirdShapeNode* nodeToDelete = currentNode;
		currentNode = currentNode->link;
		delete nodeToDelete;
		nodeToDelete = nullptr;
	}

	head = nullptr;

	return 0;
}