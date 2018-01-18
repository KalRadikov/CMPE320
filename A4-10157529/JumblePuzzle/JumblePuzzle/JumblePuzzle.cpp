/*
Name: Kal Radikov
Date: 2017-11-17
StuID: 10157529
NetID: 14kr9
*/

#include "stdafx.h"
#include "JumblePuzzle.h"

using namespace std;

// Default constructor without arguments. Creates a null Jumble Puzzle
JumblePuzzle::JumblePuzzle() {
	buffer = NULL;
	size = 0;
	row = 0;
	col = 0;
	direction = 0;
}

JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& difficulty) {

	//check difficulty and throw exception if improper difficulty is entered
	if (((difficulty) != "easy") && ((difficulty) != "medium") && ((difficulty) != "hard"))
	{
		throw BadJumbleException("Invalid difficulty. Type 'easy', 'medium', or 'hard' in all lowercase.");
	}

	int wordLength = hiddenWord.length();
	char directions[] = "nsew";

	//for (int i = 0; i < wordLength; i++) {
	//	char c = hiddenWord[i];
	//	if (islower(c) == false) {
	//		throw BadJumbleException("Invalid. String can only contain lowercase letters.");
	//	}
	//}

	//check word length and throw exception if improper length
	if (wordLength < 3 || wordLength > 10) {
		throw BadJumbleException("Word is too short. Should be between 3 and 10 letters long.");
	}

	//set difficulty of game
	if (difficulty == "easy") {
		size = 2 * wordLength;
	}
	else if (difficulty == "medium") {
		size = 3 * wordLength;
	}
	else if (difficulty == "hard") {
		size = 4 * wordLength;
	}

	//Allocate buffer
	buffer = new charArrayPtr[size + 1];
	for (int i = 0; i < size; i++) {
		buffer[i] = new char[size];
	}

	//Fill buffer with random lowercase letters from a to z
	srand(time(NULL));
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			buffer[a][b] = 'a' + rand() % 26;
		}
	}

	//Randomly select direction based on time
	srand(time(NULL));
	direction = directions[rand() % 4];

	//Assign starting location based on direction to avoid going out of index
	if (direction == 'n') {
		col = rand() % (size);
		row = rand() % (size - wordLength) + wordLength;
	}
	else if (direction == 's') {
		col = rand() % (size);
		row = rand() % (size - wordLength);
	}
	else if (direction == 'e') {
		col = rand() % (size - wordLength);
		row = rand() % (size);
	}
	else if (direction == 'w') {
		col = rand() % (size - wordLength) + wordLength;
		row = rand() % (size);
	}

	//Add hidden word to buffer at appropriate location
	int i = 0;
	while (i != wordLength) {
		if (direction == 'n') {
			buffer[row - i][col] = hiddenWord[i];
		}
		else if (direction == 's') {
			buffer[row + i][col] = hiddenWord[i];
		}
		else if (direction == 'e') {
			buffer[row][col + i] = hiddenWord[i];
		}
		else if (direction == 'w') {
			buffer[row][col - i] = hiddenWord[i];
		}
		i++;
	}
}


// copy constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle& orig) {
	size = orig.getSize();

	// allocating new char buffer
	buffer = new charArrayPtr[size + 1];
	for (int i = 0; i < size; i++) {
		buffer[i] = new char[size];
	}

	// copy characters to char buffer
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			buffer[i][j] = orig.buffer[i][j];
		}
	}
}

// Overloading assignment operator
JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& right) {
	//check if assignment is not the same
	if (this != &right) {
		right.~JumblePuzzle();
		size = right.size;
		buffer = new charArrayPtr[size + 1];

		// allocating new char buffer
		for (int i = 0; i < size; i++) {
			buffer[i] = new char[size];
		}
		// copy characters to char buffer
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				buffer[i][j] = right.buffer[i][j];
			}
		}
	}
	return *this;
}

// ------------------------ Destructor Implementation --------------------------//

JumblePuzzle::~JumblePuzzle() {
	for (int i = 0; i < size; ++i) {
		delete[] buffer[i];
	}
	delete[] buffer;
}

// ------------------------ Exception Implementation --------------------------//

BadJumbleException::BadJumbleException(const string& m) : message(m) {}

string BadJumbleException::what() const { return message; }

// ------------------------ Accessor Implementation --------------------------//

int JumblePuzzle::getSize() const {
	return size;
}

int JumblePuzzle::getRowPos() const {
	return row;
}

int JumblePuzzle::getColPos() const {
	return col;
}

char JumblePuzzle::getDirection() const {
	return direction;
}

charArrayPtr* JumblePuzzle::getJumble() const {
	return buffer;
}