/*
CMPE 320 - Assignment 5

Kal Radikov - 14kr9

Polymorphism

*/

#pragma once

#include "stdafx.h"
#include <iostream>
#include "ShapesGood.h"

//------------------ Filled ------------------//
Filled::Filled(string fc) : fillColor(fc) {}

Filled::~Filled(void) {}

//------------------ Labeled ------------------//
Labled::Labled(string tl) : textLabel(tl) {}

Labled::~Labled(void) {}

//------------------ Shape ------------------//
Shape::Shape(int length, int width, string borderColor)
	: length(length), width(width), borderColor(borderColor) {}

int Shape::getLength() const { return length; }

int Shape::getWidth() const { return width; }

Shape::~Shape(void) {}


//------------------ Square ------------------//
Square::Square(int length, int width, string borderColor) :
	Shape(length, width, borderColor) {}

void Square::draw()
{
	drawBorder();
}

void Square::drawBorder() {
	cout << "\nDrawing a " + borderColor + " square.";
}

//------------------ Filled Square ------------------//
FilledSquare::FilledSquare(int length, int width, string borderColor, string fillColor) :
	Square(length, width, borderColor), Filled(fillColor) {}
void FilledSquare::draw()
{
	drawBorder();
	fill();
}

void FilledSquare::fill() {
	cout << " With " + fillColor + " fill.";
}

FilledTextSquare::FilledTextSquare(int length, int width, string borderColor, string fillColor, string textLabel) :
	FilledSquare(length, width, borderColor, fillColor), Labled(textLabel) {}

void FilledTextSquare::draw()
{
	drawBorder();
	fill();
	drawText();
}

void FilledTextSquare::drawText() {
	cout << " Containing the text: \"" << textLabel << "\".";
}

//------------------ Circle ------------------//
void Circle::drawBorder() {
	cout << "\nDrawing a " + borderColor + " circle.";
}
Circle::Circle(int length, int width, string borderColor) : 
	Shape(length, width, borderColor) {}

void Circle::draw()
{
	drawBorder();
}

//------------------ Filled Circle ------------------//
void FilledCircle::fill() {
	cout << " With " + fillColor + " fill.";
}
FilledCircle::FilledCircle(int length, int width, string borderColor, string fillColor) :
	Circle(length, width, borderColor), Filled(fillColor) {}

void FilledCircle::draw()
{
	drawBorder();
	fill();
}


//------------------ Arc ------------------//
void Arc::drawBorder() {
	cout << "\nDrawing a " + borderColor + " arc.";
}

Arc::Arc(int length, int width, string borderColor) :
	Shape(length, width, borderColor) {}

void Arc::draw()
{
	drawBorder();
}