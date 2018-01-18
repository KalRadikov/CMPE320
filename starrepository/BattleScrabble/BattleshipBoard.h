#pragma once
#include "Player.h"
#include"Ship.h"
#include "Point.h"
#include <stdexcept>
#include "stdafx.h"

// Structure used to store the status of each tile on the BattleShip Board:
// If a ship is in the tile then 'ship' will have a pointer to it, nullptr otherwise
// The hit boolean indicates if this tile has a ship that has already been hit
// The pinged boolean inidicates if this tile has a ship that has been pinged
class BattleshipBoardTile
{
public:
	BattleshipBoardTile();
    BattleshipBoardTile(Ship* shipPtr, const bool hitBool, const bool pingBool, const bool missedBool);

	//Accessors for tile
	bool containsShip() const;
	Ship* getShip() const;
	bool isHit() const;
	bool isPinged() const;
    bool isMissed() const;

	//Setting for ship pointer
	//Also resets hit and pinged flags to false
	void setShip(Ship* s);

	//Setters for hit and pinged flag
	void setHit(const bool h);
	void setPinged(const bool p);
    void setMissed(const bool m);

private:
	Ship* ship;
	bool hit;
	bool pinged;
    bool missed;
};

class Player;
class Ammo; 

class BattleshipBoard
{
private:
	//2D array of BoardTile, declared on the heap
	BattleshipBoardTile** arrayOfTiles;
	int size;
	std::vector<Ship *> ships;
	//Checks if Point p is within the bounds of the board
	bool pointWithinBounds(Point p) const;
    Player* boardOwner;
    Player* boardEnemy;

public:
	// Fires ammo at the specified location
	// Point fireLocation: The coodinates (x,y) on the board to fire at
	// Ammo& ammo: The type of ammo being fired
	// Returns bool: True if the hit was successful, false otherwise
    bool fireAtLocation(const Point& fireLocation);
    bool fireAtLocation(const Point& fireLocation, Ammo* ammoType);
    void setEnemy(Player* e);
	// Adds the ship to the board
	// Ship* ship: pointer to the ship to be added to the board
	// Throws ShipAddException if the ship cannot be added (goes out of bound or intersects with another ship)
	void addShip(Ship* ship);

    void removeShip(Ship* ship);

	// Gets the Board tile at the point
	// Throws TileOutOfBoundsException if the tile is not within the bounds of the board
	BattleshipBoardTile& getTile(Point p) const;

	int getSize() const;

	std::vector<Ship*> getShips() const;

	// Gets the Board tile at location (x,y)
	// Throws TileOutOfBoundsException if the tile is not within the bounds of the board
	BattleshipBoardTile& getTile(int x, int y) const;

    explicit BattleshipBoard(int boardSize, Player* owner); //Constructor
	BattleshipBoard(BattleshipBoard& copy); //Copy Constructor
	BattleshipBoard& operator=(BattleshipBoard& right);
	~BattleshipBoard(); //Deconstructor
};

//Custom exception class for when a ship cannot be added to the board
class ShippAddException : public std::runtime_error
{
public:
	//Constructor that calls the runtime_error constructor with a helpful error message
	ShippAddException(Point p) :
		std::runtime_error("This ship cannot be placed at " + p.toString())
	{
	};
};

//Custom exception class for when a the requested tile is not within the board bounds
class TileOutOfBoundsException : public std::runtime_error
{
public:
	//Constructor that calls the runtime_error constructor with a helpful error message
	TileOutOfBoundsException(Point p) :
		std::runtime_error("Tile out of bounds! Cannot access tile at " + p.toString())
	{
	}
	;
};
