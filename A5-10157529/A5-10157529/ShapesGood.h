/*
CMPE 320 - Assignment 5

Kal Radikov - 14kr9

Polymorphism

*/

#pragma once

#include <string>
using namespace std;

class Shape {

public:
	Shape(int, int, string);
	int getLength() const;
	int getWidth() const;
	virtual void draw() = 0;
	virtual ~Shape();

protected:
	string borderColor;
	virtual void drawBorder() = 0;

private:
	int length, width;
};

class Square : public Shape {
public:
	Square(int, int, string);
	virtual void draw();

protected:
	virtual void drawBorder();
};

class Filled {
public:
	Filled(string);
	virtual ~Filled();

protected:
	string fillColor;
	virtual void fill() = 0;
};

class Labled {
public:
	Labled(string);
	virtual ~Labled();

protected:
	string textLabel;
	virtual void drawText() = 0;
};

class FilledSquare : public Square, Filled {
public:
	FilledSquare(int length, int width, string borderColor, string fillColor);
	virtual void draw();

protected:
	virtual void fill();
};

class FilledTextSquare : public FilledSquare, Labled {
public:
	FilledTextSquare(int length, int width, string borderColor, string fillColor, string textLabel);
	virtual void draw();

protected:
	virtual void drawText();
};

class Circle : public Shape {
public:
	Circle(int length, int width, string borderColor);
	virtual void draw();

protected:
	virtual void drawBorder();
};

class FilledCircle : public Circle, Filled {
public:
	FilledCircle(int length, int width, string borderColor, string fillColor);
	virtual void draw();

protected:
	virtual void fill();
};

class Arc : public Shape {
public:
	Arc(int length, int width, string borderColor);
	virtual void draw();
protected:
	virtual void drawBorder();
};
