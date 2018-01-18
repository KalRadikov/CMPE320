#pragma once

#include <vector>
#include "Ship.h"
#include "BattleshipBoard.h"
#include "Ammo.h"
#include "ScrabbleTileContainer.h"
#include "ScrabbleBoard.h"
#include  "Game.h"
#include "stdafx.h"


class BattleshipBoard;
class Ammo;
class ScrabbleTileContainer;
class ScrabbleBoard;
class Game;

class Player
{
private:
	std::vector<Ammo *> ammoOptions;
	BattleshipBoard* battleshipBoard;
	ScrabbleBoard* scrabbleBoard;
	Ammo* currentlySelectedAmmo;
	ScrabbleTileContainer* scrabbleBin;
	Game* game;
    int AmmoCount;

public:

    Player(const int boardSize, const int playerDifficulty, Game* _game); //Constructor
	virtual ~Player(); //Destructor

	// Changes which ammo is currently selected for the player
	// index: the index of the ammo in the inventory to equip
	void selectAmmo(const int index);

	// Adds the specified ammo to the player's inventory of ammo
	// ammoToAdd: pointer to the ammo instance to add to the player
	void addAmmo(Ammo* ammoToAdd);

	// Virtual function to be overriden by child classes
	// Triggers the player to make their move to advance the game
	virtual void makeMove() = 0;

	//Function to indicate the player has completed their move
	// Tells the parent game object to progress the game
    void endMove();

    void setEnemy(Player* e);
	//Checks if there are anymore ships that are not sunk
	// Returns True if there is at least 1 ship with health >1, false otherwise
	bool hasLiveShips() const;

	std::vector<Ship *> getShips();
    Ammo* getSelectedAmmo() const;

    int getAmmoCount();

    BattleshipBoard* getBattleshipBoard() const;


	/**
	 * \brief Places/moves the ship with the speicifed ID to the new location
	 * \param shipID  integer id of the ship to be moved (0-4)
	 * \param location the Point at which the ship should be placed
	 * \param placeHorizontally boolean to indicate if the ship should be placed horizontally (true) or vertically (false)
	 * \return  True if the ship was placed successfully
	 *			False if an error occured (invalid location, ship was already assigned a location etc.)
	 */
//	bool placeShip(ShipType shipID, Point location, bool placeHorizontally);
};
