/*
Date: Oct 20th 2017
Author: Kal Radikov - 10157529
*/

//----------- Header file for Fraction Overloading -----------//

#pragma once

#include <exception>
#include <iostream>

using namespace std;

// Fraction class
class Fraction {
public:
	Fraction(); //no params constructor
	Fraction(int n, int d); // constructor for regular fractions
	Fraction(int n); // constructor for integer numbers
	Fraction& operator+=(const Fraction& frac); //+= operator overload
	Fraction& operator++(); //post-increment operator overload
	Fraction operator++(int proxy); //pre-increment operator overload
	int compare(const Fraction& right) const; //compare 2 fractions
	int denominator() const; //get method for numerator
	int numerator() const; //get method for denominator
private:
	void normalize(); //method to put fraction in lowest terms
	int GCD(int num, int denom); //find common denominator to normalize fraction
	int num; // holds numerator
	int denom; // holds denominator
};
// Non-Member arithmetic operator overloads
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& left, const Fraction& right);
Fraction operator-(const Fraction& frac);
Fraction operator*(const Fraction& left, const Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);

// Non-Member boolean operator overloads
bool operator>(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);

// Non-Member input/output overloads
ostream& operator<<(ostream& out, const Fraction& frac);
istream& operator>>(istream& in, Fraction& frac);

// Class for denominator as 0 Exception
class FractionException {
public:
	FractionException(const string& message);
	string& what();
private:
	string message;
};


