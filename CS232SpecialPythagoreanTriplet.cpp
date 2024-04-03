/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/
//answer = 31,875,000

#include<iostream>
using namespace std;

int MAXSUM = 10000;

int main() {
	double aVal;
	double bVal;
	double cVal;
	long long int tripletProduct;
	double squaredCVal;
	bool isTripletFound = false;

	aVal = 1;
	bVal = 2;
	cVal = 1;
	squaredCVal = 1;

	while (isTripletFound == false) {
		squaredCVal = pow(aVal, 2.0) + pow(bVal, 2.0);
		cVal = sqrt(squaredCVal);

		//cout << aVal << "^2 + " << bVal << "^2 = " << cVal << "^2" << endl;

		if ((aVal + bVal + cVal == MAXSUM) && (cVal == (int)sqrt(squaredCVal))) {
			isTripletFound = true;
			tripletProduct = aVal * bVal * cVal;
		}
		else if (aVal + bVal + cVal <= MAXSUM) {
			bVal++;
		}
		else if (aVal + bVal + cVal > MAXSUM) {
			aVal++;
			bVal = aVal + 1;
		}
		
	}

	//output
	cout << "a = " << aVal << endl;
	cout << "b = " << bVal << endl;
	cout << "c = " << cVal << endl << endl;
	cout << "The product of " << aVal << " * " << bVal << " * " << cVal << " = " << tripletProduct << endl;

	system("pause");
	return 0;
}