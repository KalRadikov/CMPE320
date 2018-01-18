#pragma once
#include "ScrabbleTile.h"
#include <vector>


class ScrabbleTileContainer {

private:
	std::vector<ScrabbleTile*> listOfTiles;

public:

	/**
	 * \brief Returns a random tile
	 * \return Pointer to random tile in the collection, nullptr if the collection is empty
	 */
	ScrabbleTile* getRandomTile() const;


	/**
	 * \brief Adds a tile to the collection
	 * \param tileToAdd Pointer to the tile to add (should be declared on the heap)
	 */
	void addTile(const ScrabbleTile* tileToAdd);


	/**
	 * \brief Checks if the collection is empty
	 * \return True if there are no tiles in the collection, False otherwise
	 */
	bool isEmpty() const;
};

