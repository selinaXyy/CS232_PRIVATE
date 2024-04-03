/*
Recursive solution using implementing the following pseudocode

solveTowers(count, source, destination, spare)
	if (count is 1)
		Move a disk directly from source to destination
	else
		solveTowers(count - 1, source, spare, destination)
		solveTowers(1, source, destination, spare)
		solveTowers(count - 1, spare, destination, source)
*/

#include<iostream>
#include<string>
using namespace std;

const int ROWSIZE = 9;
const int COLSIZE = 3;
int poleArray[ROWSIZE][COLSIZE];
int diskValue = 0;
char userCharIntput = 'Y';

void moveTopDiskFromSourceToDestinationPole(int poleArrayPar[][COLSIZE], string sourcePar, string destPar);
void setupArray(int poleArrayPar[][COLSIZE]);
void displayArray(int poleArrayPar[][COLSIZE]);
void solveTowers(int count, string source, string destination, string spare);

int main() {
	//declarations
	int numOfDisks = 100;
	int counter;
	string poleA = "A";
	string poleB = "B";
	string poleC = "C";

	//get user input
	while (numOfDisks < 1 || numOfDisks > 9) {
		cout << "Number of disks on the first pole (1 to 9): ";
		cin >> numOfDisks;
	}

	//initialize the 2D array
	setupArray(poleArray);

	//establish the disks on the first pole
	for (counter = 0; counter < numOfDisks; counter++)
		poleArray[counter][0] = numOfDisks - counter;

	displayArray(poleArray); //display the initial poles with all the disks on poleA
	solveTowers(numOfDisks, poleA, poleC, poleB);
	displayArray(poleArray); //display the final position of the disks on poleC
	system("pause");
	return 0;
}

void solveTowers(int count, string source, string destination, string spare) {
	if (count == 1) {
		moveTopDiskFromSourceToDestinationPole(poleArray, source, destination);
		//does the user want to see disk movement step-by-step
		if (userCharIntput == 'Y' || userCharIntput == 'y') {
			cout << "Continue step-by-step (Y/N): ";
			cin >> userCharIntput;
			displayArray(poleArray);
		}
		else
			displayArray(poleArray);
	}
	else {
		solveTowers(count - 1, source, spare, destination);
		solveTowers(1, source, destination, spare);
		solveTowers(count - 1, spare, destination, source);
	}
}

void moveTopDiskFromSourceToDestinationPole(int poleArrayPar[][COLSIZE], string sourcePar, string destPar) {
	int rowSource = 0;
	int colSource = 0;
	int rowDestination = 0;
	int colDestination = 0;

	if (sourcePar == "A")
		colSource = 0;
	else if (sourcePar == "B")
		colSource = 1;
	else if (sourcePar == "C")
		colSource = 2;

	if (destPar == "A")
		colDestination = 0;
	else if (destPar == "B")
		colDestination = 1;
	else if (destPar == "C")
		colDestination = 2;

	//what is the top disk value that will be moved?
	for (int row = 0; row < ROWSIZE; row++) {
		if (poleArrayPar[row][colSource] > 0)
			rowSource = row; //establish the index that contains the top disk source value
	}
	diskValue = poleArrayPar[rowSource][colSource];

	//what row should the disk be placed in on the destination column?
	for (int row = ROWSIZE - 1; row >= 0; row--) {
		//scan from the top of the column down to the last available 0 value
		if (poleArrayPar[row][colDestination] == 0)
			rowDestination = row;
	}

	//remove the disk from the source col and place it on the destination col
	poleArrayPar[rowSource][colSource] = 0;
	poleArrayPar[rowDestination][colDestination] = diskValue;
}

void setupArray(int poleArrayPar[][COLSIZE]) {
	int row, col;

	for (row = 0; row < ROWSIZE; row++) {
		for (col = 0; col < COLSIZE; col++) {
			poleArrayPar[row][col] = 0;
		}
	}
}

void displayArray(int poleArrayPar[][COLSIZE]) {
	int row;
	int col;
	enum colID { COL0, COL1, COL2 };
	for (row = ROWSIZE - 1; row >= 0; row--) {
		for (col = 0; col < COLSIZE; col++) {
			if (!(poleArrayPar[row][COL0] == 0 && poleArrayPar[row][COL1] == 0 && poleArrayPar[row][COL2] == 0)) {
				if (poleArrayPar[row][col] == 0)
					cout << " " << " ";
				else
					cout << poleArrayPar[row][col] << " ";
			}
		}
		if (!(poleArrayPar[row][COL0] == 0 && poleArrayPar[row][COL1] == 0 && poleArrayPar[row][COL2] == 0)) {
			cout << endl;
		}
	}
	cout << "-----" << endl;
	cout << "A B C" << endl;
	cout << endl;
}