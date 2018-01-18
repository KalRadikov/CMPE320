#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleScrabble/BattleshipBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(BoardTileTests)
	{
	public:

		TEST_METHOD(BoardTileSetters)
		{
			BattleshipBoardTile tile;

			//Testing hit setter
			tile.setHit(true);
			Assert::IsTrue(tile.isHit(), L"Tile hit setter did not set flag");

			//Testing ping setter
			tile.setPinged(true);
			Assert::IsTrue(tile.isPinged(), L"Tile ping setter did not set flag");

			//Creating junk ship pointer and making sure it's set
			Ship* sp = reinterpret_cast<Ship *>(0x1234);
			tile.setShip(sp);
			Assert::IsTrue(tile.containsShip(), L"BoardTile placeShip did not set ship pointer");
			Assert::AreEqual(reinterpret_cast<int>(tile.getShip()), 0x1234,
			                 L"BoardTile placeShip did not set the correct pointer");
			Assert::IsFalse(tile.isHit(), L"BoardTile placeShip did not reset hit flag");
			Assert::IsFalse(tile.isPinged(), L"BoardTile placeShip did not reset pinged flag");
		}

		TEST_METHOD(BoardTileConstructor)
		{
			BattleshipBoardTile tile;

			//Making sure the tile is empty
			Assert::IsFalse(tile.containsShip(), L"Default BoardTile constructor did not start off empty");
			Assert::IsFalse(tile.isHit(), L"Default BoardTile constructor did not start off empty");
			Assert::IsFalse(tile.isPinged(), L"Default BoardTile constructor did not start off empty");
		}
	};
}
