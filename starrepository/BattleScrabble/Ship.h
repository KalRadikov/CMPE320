#pragma once
#include "stdafx.h"
#include <vector>
#include "Point.h"

enum ShipType
{
	AircraftCarrier,
	BattleShip,
	Submarine,
	Cruiser,
	Destroyer
};

class Ship
{
private:
	// Size of the ship
	int size;

	// health of ship form size to 0
	int health;

	// ID of ship using the ShipType enum above
	ShipType id;

	// Pointer to constant ship size values
	const int* shipSizes = new int[5] {5, 4, 3, 3, 2};

	// Points taken by the ship
	std::vector<Point> occupiedTiles;

    bool placeHorizontally;

	// Points that have been hit on this ship
	std::vector<Point> hitTiles;

	// Status of ship 
	bool dead;


public:

	//Constructor and deconstructor
	explicit Ship(ShipType id);
	~Ship();

    void setPlaceHorizontally(bool value);

	int getId() const;

	// Instead of this as a constructor use a function
	// 
	// direction  true is right and false is down ; 
	/**
	 * \brief Populate the occupied tiles variable, i.e places the ship
	 * \param startLocation Point that indicates the start location of the ship
	 * \param placeHorizontally True if the ship should be placed horizontally, False to place vertically
	 */
    void setLocation(Point _startLocation, bool _placeHorizontally); // potentially change to boolean

	// Decrease health by one and check if ship is dead
	bool markHit(Point p);

	// Return the points taked by the ship
	std::vector<Point> getOccupiedTiles() const;

	// Return dead variable 
	bool isDead() const;

	// Return the size
	int getSize() const;

	// Return the remainig health
	int getHealth() const;


    bool isPlacedHorizontally() const;

    bool hasValidLocations(int boardSize) const;

	// Return the locations which have been hit
	std::vector<Point> getHitLocations() const;
};
