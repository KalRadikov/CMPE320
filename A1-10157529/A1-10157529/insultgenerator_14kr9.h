/*
Date: Oct 6th 2017
Author: Kal Radikov - 10157529
*/

//----------- Header file for Insult Generator -----------//

#pragma once

#include "stdafx.h"
#include <iostream>
#include <set>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>

using namespace std;

class InsultGenerator {
public:
	InsultGenerator();
	void initialize();
	string talkToMe();
	vector<string> generate(const int n);
	void generateAndSave(const string s, const int n);

private:
	int randomInt();
	vector<string> word1, word2, word3, all;
	set<string> insultSet;
};

class FileException {
public:
	FileException(const string& message);
	string what() const;
private:
	string message;
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
};