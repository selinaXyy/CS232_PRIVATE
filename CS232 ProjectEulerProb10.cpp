﻿// CS232 ProjectEulerProb10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

bool isPrime(int num);
const int MAXPRIMENUM = 2000000;

int main()
{
	long long int sumOfPrimes = 0;
	long long int potentialPrimeNum = 3;

	while (potentialPrimeNum < MAXPRIMENUM) {
		if (isPrime(potentialPrimeNum)) {
			sumOfPrimes = sumOfPrimes + potentialPrimeNum;
		}
		potentialPrimeNum += 2; //even numbers are never prime, so only check the odds
	}

	sumOfPrimes = sumOfPrimes + 2;
	cout << "The sum of those prime numbers less than " << MAXPRIMENUM << " is " << sumOfPrimes << endl;

	return 0;
}

bool isPrime(int num) {
	if (num % 2 == 0) {
		return false;
	}
	for (int i = 3; i <= sqrt(num); i += 2) { //if the number is not an even number, only check if it can be divided by an odd number
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
