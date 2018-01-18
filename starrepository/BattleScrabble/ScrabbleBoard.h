#pragma once
#include "Ammo.h"
#include "ScrabbleTile.h"
#include "ScrabbleTileContainer.h"
#include "Point.h"

#include <string>

class Ammo;

class ScrabbleBoard {

private:
	//2D array of scrabble tiles form the board, if there is no tile at a certain location then set value to nullptr
	ScrabbleTile** boardTiles;

	//Pointer to the bag that contains all the letters for the game
	ScrabbleTileContainer* bag;

	//2D array of ammo, if the tile does not have a powerup in it then set the value to nullptr
	Ammo** powerUpTiles;

public:
	//Constructor
	ScrabbleBoard(const int boardSize);

	
	/**
	 * \brief Checks if the specified word is a valid english word
	 * \param word string to search for in the dictionary
	 * \return True if the word is valid, false otherwise
	 */
	bool checkDictionary(const std::string word) const;


	/**
	 * \brief Gets the powerup associated with a specific tile
	 * \param location The location of the tile
	 * \return Pointer to the Ammo type if there is one, nullptr otherwise
	 */
	Ammo* getPowerUp(const Point location);
};

