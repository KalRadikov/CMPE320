#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleScrabble/HumanPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(PlayerTests)
	{
	public:

		TEST_METHOD(PlayerPlaceShips)
		{
			HumanPlayer testPlayer(10, 0);

			testPlayer.placeShip(AircraftCarrier, Point(0, 0), true);
			testPlayer.placeShip(BattleShip, Point(0, 1), true);
			testPlayer.placeShip(Cruiser, Point(0, 2), true);
			testPlayer.placeShip(Destroyer, Point(0, 3), true);
			testPlayer.placeShip(Submarine, Point(0, 4), true);
		}
	};
}
