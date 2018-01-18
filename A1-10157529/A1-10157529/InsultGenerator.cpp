/*
Date: Oct 6th 2017
Author: Kal Radikov - 10157529
*/

//----------- Implementation file for Insult Generator -----------//

#include "stdafx.h"
#include "insultgenerator_14kr9.h"

using namespace std;

InsultGenerator::InsultGenerator() {}

//-------------------- Import CSV file into 3 column vector array ---------------------//

void InsultGenerator::initialize() {

	string line;
	stringstream ss;

	ifstream fileIn("InsultsSource.txt");
	if (fileIn.fail()) {
		throw FileException("This is an illegal file");
	}
	//keep reading file until end of file is detected to prevent crashing
	while (!fileIn.eof()) {
		getline(fileIn, line);
		ss.clear();
		ss.str(" ");
		ss << line;
		while (ss >> line) {
			all.push_back(line);
		}
		for (int i = 0; i < all.size(); i += 3) {
			word1.push_back(all[i]);
			word2.push_back(all[i + 1]);
			word3.push_back(all[i + 2]);
		}
	}
	fileIn.close();
}

//-------------------- Generate Random Integer Function ---------------------//

int InsultGenerator::randomInt() {

	int num = rand() % 49; //we know the source file length is 50 lines 
	return num;
}
//-------------------- Choose random combination of insults ---------------------//

string InsultGenerator::talkToMe() {

	string insult;
	insult = "Thou " 
		+ word1[randomInt()] + " " 
		+ word2[randomInt()] + " " 
		+ word3[randomInt()] + "!";
	return insult;

}
// -------------------- Generate n insults and return vector of insults ----------------------//

vector<string> InsultGenerator::generate(int n) {

	//check if number is within legal range
	if (n < 1 || n > 10000) {
		throw NumInsultsOutOfBounds("Illegal number of insults!");
		return vector<string>();
	}

	//use set for storing only unique values and more efficient storage
	set<string> insultSet;
	while (n > insultSet.size()) {
		string temp = talkToMe();
		insultSet.insert(temp);
	}

	//using vector iterator constructor to copy entire set
	vector<string> insults(insultSet.begin(), insultSet.end());
	return insults;
}

//-------------------- Generate n insults, return vector of insults, and save to file ---------------------//

void InsultGenerator::generateAndSave(string filename, int n) {
	ofstream fileOut(filename);

	//reuse generate function with same parameter
	vector<string> insults = generate(n);

	//copy output to file
	if (insults.size() > 0)
		for (int i = 0; i < n; i++)
			fileOut << insults[i] << endl;
}

//-------------------- Custom Exceptions ---------------------//

FileException::FileException(const string& m) : message(m) {}

string FileException::what() const {
	return message;
}

//NumInsultsOutOfBounds class to throw error if provided number of insults is out of bounds
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}

string NumInsultsOutOfBounds::what() const {
	return message;
}