/*
Initial move:
Disk 1 is moved to peg 3 if n is odd, and to peg 2 if n is even.

Subsequent moves depend on the parity of the disk transferred in the
immediately preceding move:
If its parity is even, the destination peg in the next move will
remain the same, and the next disk will be transferred there from
the peg that was not involved in the immediately preceding move
(this disk will be placed on top of the previously transferred
even disk, and therefore must be odd)

If its parity is odd, the next transfer will be between pegs that
are both different from the immediately preceding destination peg,
and the direction of the move is such that a smaller disk is placed
on top of a larger one.
*/

#include<iostream>
#include<string>
using namespace std;

const int ROWSIZE = 9;
const int COLSIZE = 3;
int diskValue = 0;

void moveTopDiskFromSourceToDestinationPole(int poleArrayPar[][COLSIZE], string sourcePar, string destPar);
void establishTopDiskValues(int poleArrayPar[][COLSIZE], int &poleATopVal, int &poleBTopVal, int &poleCTopVal);
void setupArray(int poleArrayPar[][COLSIZE]);
void displayArray(int poleArrayPar[][COLSIZE]);

int main() {
	//declarations
	int numOfDisks = 100;
	int counter;
	int parityOfMovedDisk = 1;
	int poleATopDiskVal = 0;
	int poleBTopDiskVal = 0;
	int poleCTopDiskVal = 0;
	bool isThisAnInitialMove = true;
	char userCharIntput = 'Y';
	string poleA = "A";
	string poleB = "B";
	string poleC = "C";
	string poleSource = "";
	string poleDestination = "";
	int poleArray[ROWSIZE][COLSIZE];

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

	while (poleArray[numOfDisks - 1][2] != 1) {//i.e., until all disks have not moved to pole C
		if (isThisAnInitialMove == true) {
			if (numOfDisks % 2 == 0) { //even number of disks
				poleSource = "A";
				poleDestination = "B";
			}
			else { //odd number of disks
				poleSource = "A";
				poleDestination = "C";
			}
			moveTopDiskFromSourceToDestinationPole(poleArray, poleSource, poleDestination);
			isThisAnInitialMove = false;
		}
		else if (parityOfMovedDisk == 1) { //i.e., moved disk has odd parity
			if (poleDestination == "C") {
				if (poleATopDiskVal == 0) {
					poleDestination = "A";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleA);
				}
				else if (poleBTopDiskVal == 0) {
					poleDestination = "B";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleB);
				}
				else if (poleBTopDiskVal < poleATopDiskVal) {
					poleDestination = "A";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleA);
				}
				else if (poleATopDiskVal < poleBTopDiskVal) {
					poleDestination = "B";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleB);
				}
			}
			else if (poleDestination == "B") {
				if (poleATopDiskVal == 0) {
					poleDestination = "A";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleA);
				}
				else if (poleCTopDiskVal == 0) {
					poleDestination = "C";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleC);
				}
				else if (poleATopDiskVal < poleCTopDiskVal) {
					poleDestination = "C";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleC);
				}
				else if (poleCTopDiskVal < poleATopDiskVal) {
					poleDestination = "A";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleA);
				}
			}
			else if (poleDestination == "A") {
				if (poleBTopDiskVal == 0) {
					poleDestination = "B";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleB);
				}
				else if (poleCTopDiskVal == 0) {
					poleDestination = "C";
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleC);
				}
				else if (poleBTopDiskVal < poleCTopDiskVal) {
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleC);
					poleDestination = "C";
				}
				else if (poleCTopDiskVal < poleBTopDiskVal) {
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleB);
					poleDestination = "B";
				}
			}
		}
		else if (parityOfMovedDisk == 0) { //i.e., moved disk has even parity
			if (poleDestination == "C") {
				if (poleATopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleC);
				else if (poleBTopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleC);
				else if (poleATopDiskVal < poleBTopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleC);
				else if (poleBTopDiskVal < poleATopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleC);

				poleDestination = "C";
			}
			else if (poleDestination == "B") {
				if (poleATopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleB);
				else if (poleCTopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleB);
				else if (poleATopDiskVal < poleCTopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleA, poleB);
				else if (poleCTopDiskVal < poleATopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleB);

				poleDestination = "B";
			}
			else if (poleDestination == "A") {
				if (poleBTopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleA);
				else if (poleCTopDiskVal == 0)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleA);
				else if (poleBTopDiskVal < poleCTopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleB, poleA);
				else if (poleCTopDiskVal < poleBTopDiskVal)
					moveTopDiskFromSourceToDestinationPole(poleArray, poleC, poleA);

				poleDestination = "A";
			}
		}

		//set value of top disk values
		establishTopDiskValues(poleArray, poleATopDiskVal, poleBTopDiskVal, poleCTopDiskVal);

		//determine parity of moved disk
		if (diskValue % 2 == 0)
			parityOfMovedDisk = 0;
		else
			parityOfMovedDisk = 1;

		//does the user want to see disk movement step-by-step
		if (userCharIntput == 'Y' || userCharIntput == 'y') {
			cout << "Continue step-by-step (Y/N): ";
			cin >> userCharIntput;
			displayArray(poleArray);
		}
		else
			displayArray(poleArray);

	}

	system("pause");
	return 0;
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

void establishTopDiskValues(int poleArrayPar[][COLSIZE], int &poleATopVal, int &poleBTopVal, int &poleCTopVal) {
	int row, col;
	poleATopVal = 0;
	poleBTopVal = 0;
	poleCTopVal = 0;

	for (col = 0; col < COLSIZE; col++) {
		for (row = 0; row < ROWSIZE; row++) {
			if (col == 0) { //investigate poleA
				if (poleArrayPar[row][col] != 0)
					poleATopVal = poleArrayPar[row][col];
			}
			else if (col == 1) { //investigate poleB
				if (poleArrayPar[row][col] != 0)
					poleBTopVal = poleArrayPar[row][col];
			}
			else if (col == 2) { //investigate poleC
				if (poleArrayPar[row][col] != 0)
					poleCTopVal = poleArrayPar[row][col];
			}
		} //for (row = 0; row < ROWSIZE; row++)
	}// for (col = 0; col < COLSIZE; col++)
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