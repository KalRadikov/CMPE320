#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleScrabble/BattleshipBoard.h"
#include "../BattleScrabble/Missile.h"
#include "../BattleScrabble/Ping.h"
#include "../BattleScrabble/Player.h"
#include "../BattleScrabble/HumanPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(BoardTests)
	{
	public:

		TEST_METHOD(BoardInit)
		{
			
			BattleshipBoard newBoard(10, nullptr);

			BattleshipBoardTile emptyTile;
			for (int j = 0; j < 10; j++)
			{
				for (int i = 0; i < 10; i++)
				{
					emptyTile = newBoard.getTile(i, j);

					//Making sure the first tile is empty (assume the rest are the same)
					Assert::IsFalse(emptyTile.containsShip(), L"Tiles did not start off empty");
					Assert::IsFalse(emptyTile.isHit(), L"Tiles did not start off empty");
					Assert::IsFalse(emptyTile.isPinged(), L"Tiles did not start off empty");
				}
			}
		}

		TEST_METHOD(BoardBounds)
		{
			//Making sure bounds checking works
			BattleshipBoard newBoard(10, nullptr);
			Point points[] = {Point(-1, -1) ,Point(0, -1) ,Point(-1, 0) ,Point(10, 10)};
			for each (Point p in points)
			{
				try
				{
					newBoard.getTile(p);
					Assert::Fail(L"Failed to recognize that tile was out of bounds");
				}
				catch (const TileOutOfBoundsException&)
				{
				}
			}
		}

		TEST_METHOD(BoardAddShip)
		{
			//Making sure ships are added correctly to the board
			BattleshipBoard newBoard(10, nullptr);

			Ship testShip(AircraftCarrier);
			testShip.setLocation(Point(0, 0), true);
			newBoard.addShip(&testShip);

			//Making sure the correct tiles were set
			for (int i = 0; i < 5; ++i)
			{
				BattleshipBoardTile shipTile = newBoard.getTile(i, 0);
				Assert::AreEqual(reinterpret_cast<int>(shipTile.getShip()), reinterpret_cast<int>(&testShip));
			}

			//Try placing a new ship over the exisiting ship
			Ship otherShip(BattleShip);
			otherShip.setLocation(Point(0, 0), false);
			try
			{
				newBoard.addShip(&otherShip);
				Assert::Fail(L"This should have thrown an error, ships cannot overlap");
			}
			catch (ShippAddException&)
			{
			}

			//Placing the ship in a valid location VERTICALLY and making sure it works
			otherShip.setLocation(Point(0, 1), false);
			newBoard.addShip(&otherShip);
			//Making sure the correct tiles were set
			for (int i = 0; i < 4; ++i)
			{
				BattleshipBoardTile shipTile = newBoard.getTile(0, i + 1);
				Assert::AreEqual(reinterpret_cast<int>(shipTile.getShip()), reinterpret_cast<int>(&otherShip));
			}
		}

		TEST_METHOD(BoardFireAtShip)
		{
			//Making sure ships are added correctly to the board
			Player *testPlayer = new HumanPlayer(10, 0);
			BattleshipBoard newBoard(10, testPlayer);

			Ship testShip(AircraftCarrier);
			testShip.setLocation(Point(0, 0), true);
			newBoard.addShip(&testShip);

			Missile testMissile;
			testPlayer->addAmmo(&testMissile);
			testPlayer->selectAmmo(0);

			Assert::IsTrue(newBoard.fireAtLocation(Point(0, 0)), L"Failed to correctly detect hit");
			Assert::IsTrue(newBoard.getTile(0, 0).isHit(), L"Failed to correctly mark tile as hit");
			Assert::IsTrue(testShip.getHealth() == 4, L"Failed to update ship health");
			Assert::IsTrue(testShip.getHitLocations()[0] == Point(0, 0), L"Failed to correctly mark hit location");

			Assert::IsFalse(newBoard.fireAtLocation(Point(0, 1)), L"Failed to correctly detect miss");
			Assert::IsFalse(newBoard.getTile(0, 1).isHit(), L"Incorrectly marked tile as hit");
			Assert::IsTrue(testShip.getHealth() == 4);

			Ping testPing;
			testPlayer->addAmmo(&testPing);
			testPlayer->selectAmmo(1);

			Assert::IsTrue(newBoard.fireAtLocation(Point(1, 0)), L"Failed to correctly detect hit");
			Assert::IsTrue(newBoard.getTile(1, 0).isPinged(), L"Failed to correctly mark tile as pinged");
			Assert::IsTrue(testShip.getHealth() == 4, L"Incorrectly updated ship health on ping");

			Assert::IsFalse(newBoard.fireAtLocation(Point(1, 1)), L"Failed to correctly detect miss");
			Assert::IsFalse(newBoard.getTile(1, 1).isPinged(), L"Incorrectly marked tile as pinged");
			Assert::IsTrue(testShip.getHealth() == 4);
		}
	};
}
