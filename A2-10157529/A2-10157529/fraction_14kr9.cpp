/*
Date: Oct 20th 2017
Author: Kal Radikov - 10157529
*/

//----------- Source file for Fraction Overloading -----------//

#include "stdafx.h"
#include <iostream>
#include "fraction_14kr9.h"

using namespace std;

Fraction::Fraction() : num(0), denom(1) {} //no parameter constructor creates 0 fraction
Fraction::Fraction(int n) : num(n), denom(1) {} // integer parameter constructor creates fraction with 1 as denominator
Fraction::Fraction(int n, int d) : num(n), denom(d) { //regular constructor with denomerator and numerator
	//check if illegal parameters
	if (denom == 0) {
		throw FractionException("Denominator cannot be 0!");
	}
	//reduce to simplest terms on creation and normalize sign
	normalize();
}
//get method for numerator
int Fraction::numerator() const { return num; }
//get method for denominator
int Fraction::denominator() const { return denom; }

//method to put fraction in lowest terms
void Fraction::normalize() {

	int sign = 1;
	//check if numerator is negative and adjust sign and cancel neagtive in numerator
	if (num < 0) {
		sign = -1;
		num = -num;
	}
	//check if denominator is negative and adjust sign and cancel neagtive in denominator
	if (denom < 0) {
		sign = -sign;
		denom = -denom;
	}

	//calculate gcd
	int gcd = GCD(num, denom);

	//adjust calculated sign of fraction and normalize
	num = sign * (num / gcd);
	denom = denom / gcd;
}

// standard GCD algorithm
int Fraction::GCD(int n, int m) {
	if (m <= n && n % m == 0)
		return m;
	else if (n < m)
		return GCD(m, n);
	else
		return GCD(m, n % m);
}

//compare method that subtracts 2 fractions and returns an int value
int Fraction::compare(const Fraction& right) const {
	int result = this->num * right.denominator() -
		this->denom * right.numerator();
	return result;
}

// += overload, add original fractionto new fraction and normalize
Fraction& Fraction::operator+=(const Fraction& frac) {
	num = num *frac.denominator() + denom * frac.numerator();
	denom = denom * frac.denominator();
	normalize();
	return *this;

}
// post++ overload, add denominator to original fraction
Fraction& Fraction::operator++() {
	num += denom;
	return *this;
}
// pre++ overload, add denominator to original fraction
Fraction Fraction::operator++(int proxy) {
	Fraction fract(num, denom);
	num += denom;
	return fract;
}
// + overload, sends + arithmetic to fraction constructor which normalizes it inherently
Fraction operator+(const Fraction& left, const Fraction& right) {
	Fraction result(left.numerator() * right.denominator() +
					left.denominator() * right.numerator(),
					left.denominator() * right.denominator());
	return result;
}
// - overload, sends - arithmetic to fraction constructor which normalizes it inherently
Fraction operator-(const Fraction& left, const Fraction& right) {
	Fraction result(left.numerator() * right.denominator() -
					left.denominator() * right.numerator(),
					left.denominator() * right.denominator());
	return result;
}
// - overload, sends negation arithmetic to fraction constructor which normalizes it inherently
Fraction operator-(const Fraction& frac) {
	Fraction result(-frac.numerator(), frac.denominator());
	return result;
}

// * overload, sends * arithmetic to fraction constructor which normalizes it inherently
Fraction operator*(const Fraction& left, const Fraction& right) {
	Fraction result(left.numerator() * right.numerator(),
					left.denominator() * right.denominator());
	return result;
}

// / overload, sends / arithmetic to fraction constructor which normalizes it inherently
Fraction operator/(const Fraction& left, const Fraction& right) {
	Fraction result(left.numerator() * right.denominator(),
					left.denominator() * right.numerator());
	return result;
}

// > overload, calls compare function of left and right inputs, checks the result
bool operator>(const Fraction& left, const Fraction& right) {
	
	return left.compare(right) > 0;
}
// < overload, calls compare function of left and right inputs, checks the result
bool operator<(const Fraction& left, const Fraction& right) {

	return left.compare(right) < 0;
}
// >= overload, calls compare function of left and right inputs, checks the result
bool operator>=(const Fraction& left, const Fraction& right) {

	return left.compare(right) >= 0;
}
// <= overload, calls compare function of left and right inputs, checks the result
bool operator<=(const Fraction& left, const Fraction& right) {

	return left.compare(right) <= 0;
}
// == overload, calls compare function of left and right inputs, checks the result
bool operator==(const Fraction& left, const Fraction& right) {

	return left.compare(right) == 0;
}
// != overload, calls compare function of left and right inputs, checks the result
bool operator!=(const Fraction& left, const Fraction& right) {

	return left.compare(right) != 0;
}
// << overload, appends the numerator to a "/" and appends denominator, returns result
ostream& operator<<(ostream& out, const Fraction& frac) {
	out << frac.numerator() << "/" << frac.denominator();
	return out;
}
// >> overload, reads input, and forms a fraction
istream& operator>>(istream& in, Fraction& frac) {
	int num_in, denom_in;
	in >> num_in;
	//check if input is a fraction (has denominator), if yes, construct regular fraction
	if (in.peek() != 10) {
		char nextChar;
		in >> nextChar;
		if (nextChar == '/')
			in >> denom_in;
		else
			denom_in = 1;
		frac = Fraction(num_in, denom_in);
	}
	// else if the value in is an integer, send to integer constructor
	else
		frac = Fraction(num_in);
	return in;
}

// Fraction exception implementation
FractionException::FractionException(const string& m) :
	message(m) {}

string& FractionException::what() {
	return message;
}