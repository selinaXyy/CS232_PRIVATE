#include<iostream>
using namespace std;

const int ARRSIZE = 8;
const int FIRSTROWINDEX = 0;
const int FIRSTCOLINDEX = 0;

int chessBoard[ARRSIZE][ARRSIZE] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 } };
char queenPositions[ARRSIZE][ARRSIZE] = {
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' },
	{ '0', '0', '0', '0', '0', '0', '0', '0' } };

void increment(int rowPar, int colPar);
void decrement(int rowPar, int colPar);
void incrementRow(int rowPar, int colPar);
void incrementCol(int rowPar, int colPar);
void incrementDiagNWtoSE(int rowPar, int colPar);
void incrementDiagSWtoNE(int rowPar, int colPar);
void decrementRow(int rowPar, int colPar);
void decrementCol(int rowPar, int colPar);
void decrementDiagNWtoSE(int rowPar, int colPar);
void decrementDiagSWtoNE(int rowPar, int colPar);
bool placedQueenOnLastColumn(int rowPar, int colPar,bool weAreBacktracking);

int main() {
	//DECLARATIONS
	bool weAreBacktracking = false; //start off forward tracking
	
	if (placedQueenOnLastColumn(FIRSTROWINDEX, FIRSTCOLINDEX, weAreBacktracking)) {
	//if (placedQueenOnLastColumn(FIRSTROWINDEX, FIRSTCOLINDEX, weAreBacktracking)) {
		//output board placement of queens
		for (int row = 0; row < ARRSIZE; row++) {
			for (int col = 0; col < ARRSIZE; col++) {
				if (queenPositions[row][col] == 'Q')
					cout << "Q";
				else
					cout << "-";
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}

bool placedQueenOnLastColumn(int rowPar, int colPar, bool weAreBacktracking) {
	
	if (colPar == ARRSIZE - 1 && queenPositions[rowPar][colPar] == 'Q') { //base case, we're at the last col
		return true; //i.e., a queen can be placed in this square
	}
	else if (rowPar >= ARRSIZE) {
		//this column can't accomodate a queen, therefore start
		//backtracking to the last row of the previous column
		weAreBacktracking = true;
		return placedQueenOnLastColumn(ARRSIZE - 1, --colPar, weAreBacktracking);
	}
	else if (weAreBacktracking == true) { //back tracking
		if (queenPositions[rowPar][colPar] == 'Q') {//we found the queen while backtracking
			decrement(rowPar, colPar); //remove influence of the queen at this position
			weAreBacktracking = false; //start moving forward to look for possible empty squares
			return placedQueenOnLastColumn(++rowPar, colPar, weAreBacktracking);
		}
		else {//we have not found the queen while backtracking
			return placedQueenOnLastColumn(--rowPar, colPar, weAreBacktracking);
		}
	}//else if (weAreBacktracking == true)
	else if (weAreBacktracking == false) { //forward tracking
		if (chessBoard[rowPar][colPar] == 0) {//a queen can be placed in this column
			queenPositions[rowPar][colPar] = 'Q'; //place a queen on this square
			increment(rowPar, colPar);
			
			//go to the beginning of the next column 
			return placedQueenOnLastColumn(FIRSTROWINDEX, ++colPar, weAreBacktracking);
		}
		else {
			//a queen CAN'T be placed on this square, try the next square on this column
			return placedQueenOnLastColumn(++rowPar, colPar, weAreBacktracking);
		}
	}//else if (weAreBacktracking == false) { //forward tracking
	else
		return false;
}

void increment(int rowPar, int colPar) {
	int num;

	num = chessBoard[rowPar][colPar];
	num++;
	chessBoard[rowPar][colPar] = num;

	incrementRow(rowPar, colPar);
	incrementCol(rowPar, colPar);
	incrementDiagNWtoSE(rowPar, colPar);
	incrementDiagSWtoNE(rowPar, colPar);
}

void decrement(int rowPar, int colPar) {
	chessBoard[rowPar][colPar]--;

	decrementRow(rowPar, colPar);
	decrementCol(rowPar, colPar);
	decrementDiagNWtoSE(rowPar, colPar);
	decrementDiagSWtoNE(rowPar, colPar);
}

void decrementRow(int rowPar, int colPar) {
	for (int col = 0; col <= 7; col++) {
		if (col != colPar)
			chessBoard[rowPar][col]--;
	}//for (int col = 0; col <= 7; col++)
	queenPositions[rowPar][colPar] = '0'; //remove Q and replace with 0 since queen is removed
}

void decrementCol(int rowPar, int colPar) {
	for (int row = 0; row <= 7; row++) {
		if (row != rowPar)
			chessBoard[row][colPar]--;
	}
	queenPositions[rowPar][colPar] = '0'; //remove Q and replace with 0 since queen is removed
}

void decrementDiagNWtoSE(int rowPar, int colPar) {
	int num;
	int row = rowPar;
	int col = colPar;

	//find the upper left hand location (i.e., the NW square)
	while (row > 0 && col > 0) {
		row--;
		col--;
	}
	//increment the cells in the diagonal
	while (row < ARRSIZE && col < ARRSIZE) {
		num = chessBoard[row][col];
		if (row != rowPar && col != colPar) {
			num--;
			chessBoard[row][col] = num;
		}
			
		row++;
		col++;
	}
	queenPositions[rowPar][colPar] = '0'; //remove Q and replace with 0 since queen is removed
}

void decrementDiagSWtoNE(int rowPar, int colPar) {
	int num;
	int row = rowPar;
	int col = colPar;

	while (row < (ARRSIZE - 1) && col > 0) {
		row++;
		col--;
	}
	//increment the cells in the diagonal
	while (row >= 0 && col < ARRSIZE) {
		num = chessBoard[row][col];
		if (row != rowPar && col != colPar) {
			num--;
			chessBoard[row][col] = num;
		}
			
		row--;
		col++;
	}
	queenPositions[rowPar][colPar] = '0'; //remove Q and replace with 0 since queen is removed
}

void incrementDiagNWtoSE(int rowPar, int colPar) {
	int row = rowPar;
	int col = colPar;

	while (row > 0 && col > 0) {
		row--;
		col--;
	}
	//increment the squares in the diagonal accept this current square
	while (row < ARRSIZE && col < ARRSIZE) {
		if (row != rowPar && col != colPar)
			chessBoard[row][col]++;

		row++;
		col++;
	}
}

void incrementDiagSWtoNE(int rowPar, int colPar) {
	int row = rowPar;
	int col = colPar;

	while (row < (ARRSIZE - 1) && col > 0) {
		row++;
		col--;
	}
	//increment the cells in the diagonal
	while (row >= 0 && col < ARRSIZE) {
		if (row != rowPar && col != colPar)
			chessBoard[row][col]++;
			
		row--;
		col++;
	}
}

void incrementCol(int rowPar, int colPar) {
	for (int row = 0; row <= 7; row++) {
		if (row != rowPar)
			chessBoard[row][colPar]++;
	}
}

void incrementRow(int rowPar, int colPar) {
	for (int col = 0; col <= 7; col++) {
		if (col != colPar)
			chessBoard[rowPar][col]++;
	}
}