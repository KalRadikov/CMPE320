/*
Name: Kal Radikov
Date: 2017-11-17
StuID: 10157529
NetID: 14kr9
*/

#pragma once

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <cmath>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>

typedef char* charArrayPtr;

using namespace std;

class BadJumbleException {
public:
	BadJumbleException(const string&);
	string what() const;
private:
	string message;
};

class JumblePuzzle {
public:

	// default constructor
	JumblePuzzle();

	// main constructor 
	JumblePuzzle(const string& hiddenWord, const string& difficulty);

	// copy constructor
	JumblePuzzle(const JumblePuzzle& orig);

	// destructor
	~JumblePuzzle();

	// comparator
	JumblePuzzle& operator=(const JumblePuzzle&);

	// return a 2d array of characters
	charArrayPtr* getJumble() const;

	//access row of first letter of the word
	int getRowPos() const;

	//access column of first letter of the word
	int getColPos() const; 

	// hidden word direction accessor
	char getDirection() const; 

	// puzzle size accessor
	int getSize() const;

private:
	charArrayPtr* buffer;
	int row;
	int col;
	char direction;
	int size;
};