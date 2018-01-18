#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BattleScrabble/Ship.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ShipTests)
	{
	public:

		TEST_METHOD(InitShip)
		{
			Ship testShip(ShipType::AircraftCarrier);
			Assert::AreEqual(testShip.getId(), 0);
			Assert::AreEqual(testShip.getSize(), 5);
		}
	};
}
