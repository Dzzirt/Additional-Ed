// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Car/Car.h"
using namespace std;
struct CarFixture
{
	CCar car;
};


struct Car_
{
	CCar car;


	template <typename Action>
	void ExpectTurnedOnCarStateAfterAction(Action && action, int expectedGear, int expectedSpeed)
	{
		BOOST_CHECK(action);
		BOOST_CHECK_EQUAL(car.GetGear(), expectedGear);
		BOOST_CHECK_EQUAL(car.GetSpeed(), expectedSpeed);
	}
	template <typename Action>
	void UnexpectTurnedOnCarStateAfterAction(Action && action, int unexpectedGear, int unexpectedSpeed)
	{
		BOOST_CHECK(action());
		BOOST_CHECK_EQUAL(car.GetGear(), expectedGear);
		BOOST_CHECK_EQUAL(car.GetSpeed(), expectedSpeed);
	}
	template <typename Action>
	void ExpectActionFailure(Action && action)
	{
		CCar clone(car);
		BOOST_CHECK(!action);
		BOOST_CHECK_EQUAL(car.IsTurnedOn(), clone.IsTurnedOn());
		BOOST_CHECK_EQUAL(car.GetGear(), clone.GetGear());
		BOOST_CHECK_EQUAL(car.GetSpeed(), clone.GetSpeed());
	}
};

BOOST_FIXTURE_TEST_SUITE(CarTest, Car_)
	BOOST_AUTO_TEST_CASE(when_turned_off_can_only_switch_to_neutral_gear)
	{
		BOOST_CHECK(!car.IsTurnedOn());
		BOOST_CHECK_THROW(car.SetGear(1), GearChangingWhenEngineTurnedOff);
		car.SetGear(0);
		BOOST_CHECK_NO_THROW(car.SetGear(0));

	}
	BOOST_AUTO_TEST_CASE(can_be_turned_on)
	{
		BOOST_CHECK_NO_THROW(car.TurnOnEngine());
	}
	BOOST_AUTO_TEST_CASE(speed_can_be_positive_only)
	{
		BOOST_CHECK_THROW(car.SetSpeed(-1), SettingNegativeSpeed);
	}
	struct at_backward_movement : Car_
	{
		at_backward_movement()
		{
			BOOST_REQUIRE_NO_THROW(car.TurnOnEngine());
			BOOST_REQUIRE_NO_THROW(car.IsTurnedOn());
			BOOST_REQUIRE_NO_THROW(car.SetGear(-1));
			BOOST_REQUIRE_EQUAL(car.GetGear(), -1);
		}
	};
	struct at_1st_gear : Car_
	{
		at_1st_gear()
		{
			BOOST_REQUIRE_NO_THROW(car.TurnOnEngine());
			BOOST_REQUIRE_NO_THROW(car.IsTurnedOn());
			BOOST_REQUIRE_NO_THROW(car.SetGear(1));

			BOOST_REQUIRE_EQUAL(car.GetGear(), 1);
		}
	};
	struct at_2st_gear : at_1st_gear
	{
		at_2st_gear()
		{
			BOOST_REQUIRE_NO_THROW(car.SetSpeed(20));
			BOOST_REQUIRE_NO_THROW(car.SetGear(2));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 2);
		}
	};
	struct at_3st_gear : at_2st_gear
	{
		at_3st_gear()
		{
			BOOST_REQUIRE_NO_THROW(car.SetSpeed(50));
			BOOST_REQUIRE_NO_THROW(car.SetGear(3));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 3);
		}
	};
	struct at_4st_gear : at_3st_gear
	{
		at_4st_gear()
		{
			BOOST_REQUIRE_NO_THROW(car.SetSpeed(60));
			BOOST_REQUIRE_NO_THROW(car.SetGear(4));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 4);
		}
	};
	struct at_5st_gear : at_4st_gear
	{
		at_5st_gear()
		{
			BOOST_REQUIRE_NO_THROW(car.SetSpeed(80));
			BOOST_REQUIRE_NO_THROW(car.SetGear(5));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 5);
		}
	};
	BOOST_AUTO_TEST_CASE(cannot_have_speed_out_of_gear_range)
	{
		at_backward_movement backwardMovement;
		BOOST_CHECK_THROW(backwardMovement.car.SetSpeed(21), SpeedIsOutOfGearRange);
		at_1st_gear first;
		BOOST_CHECK_THROW(first.car.SetSpeed(31), SpeedIsOutOfGearRange);
		at_2st_gear second;
		BOOST_CHECK_THROW(second.car.SetSpeed(19), SpeedIsOutOfGearRange);
		BOOST_CHECK_THROW(second.car.SetSpeed(51), SpeedIsOutOfGearRange);
		at_3st_gear third;
		BOOST_CHECK_THROW(third.car.SetSpeed(29), SpeedIsOutOfGearRange);
		BOOST_CHECK_THROW(third.car.SetSpeed(61), SpeedIsOutOfGearRange);
		at_4st_gear fourth;
		BOOST_CHECK_THROW(fourth.car.SetSpeed(39), SpeedIsOutOfGearRange);
		BOOST_CHECK_THROW(fourth.car.SetSpeed(91), SpeedIsOutOfGearRange);
		at_5st_gear fifth;
		BOOST_CHECK_THROW(fifth.car.SetSpeed(49), SpeedIsOutOfGearRange);
		BOOST_CHECK_THROW(fifth.car.SetSpeed(151), SpeedIsOutOfGearRange);
	}
	BOOST_AUTO_TEST_CASE(changing_gear_possible_if_current_speed_in_range_of_both_gear)
	{
		car.TurnOnEngine();
		BOOST_CHECK_NO_THROW(car.SetGear(1));
		at_1st_gear first;
		first.car.SetSpeed(10);
		BOOST_CHECK_THROW(first.car.SetGear(2), GearsSpeedNotCompatible);
		at_2st_gear second;
		second.car.SetSpeed(20);
		BOOST_CHECK_THROW(first.car.SetGear(3), GearsSpeedNotCompatible);
		at_3st_gear third;
		second.car.SetSpeed(30);
		BOOST_CHECK_THROW(first.car.SetGear(4), GearsSpeedNotCompatible);
		at_4st_gear fourth;
		second.car.SetSpeed(40);
		BOOST_CHECK_THROW(first.car.SetGear(5), GearsSpeedNotCompatible);
		BOOST_CHECK_NO_THROW(first.car.SetGear(0));
	}
	BOOST_AUTO_TEST_CASE(gear_can_be_changed_only_from_rear_to_5)
	{
		at_backward_movement backwardMovement;
		BOOST_CHECK_THROW(backwardMovement.car.SetGear(-2), GearIsOutOfRange);
		at_5st_gear fifth;
		BOOST_CHECK_THROW(fifth.car.SetGear(6), GearIsOutOfRange);
	}
	BOOST_AUTO_TEST_CASE(on_neutral_gear_speed_can_only_decrease)
	{
		at_1st_gear first;
		first.car.SetSpeed(20);
		first.car.SetGear(0);
		BOOST_CHECK_THROW(first.car.SetSpeed(21), IncreasingSpeedOnNeutral);
		BOOST_CHECK_NO_THROW(first.car.SetSpeed(19));

	}
	BOOST_AUTO_TEST_CASE(can_change_gear_if_direction_allowed_it)
	{
		at_1st_gear first;
		BOOST_CHECK_NO_THROW(first.car.SetGear(-1));
		BOOST_CHECK_NO_THROW(first.car.SetGear(1));
		first.car.SetSpeed(20);
		BOOST_CHECK_THROW(first.car.SetGear(-1), GearsDirectionsNotCompatible);
		first.car.SetGear(0);
		BOOST_CHECK_THROW(first.car.SetGear(-1), GearsDirectionsNotCompatible);
		at_backward_movement backwardMovement;
		backwardMovement.car.SetSpeed(20);
		BOOST_CHECK_THROW(backwardMovement.car.SetGear(1), GearsDirectionsNotCompatible);
		backwardMovement.car.SetGear(0);
		BOOST_CHECK_THROW(backwardMovement.car.SetGear(1), GearsDirectionsNotCompatible);
	}
	BOOST_AUTO_TEST_CASE(cant_turn_on_engine_if_already_turned_on)
	{
		car.TurnOnEngine();
		BOOST_CHECK_THROW(car.TurnOnEngine(), TurningEngineOnAgain);
	}
	BOOST_AUTO_TEST_CASE(can_be_turned_off_if_speed_is_0_and_gear_is_0)
	{
		car.TurnOnEngine();
		car.SetGear(1);
		BOOST_CHECK_THROW(car.TurnOffEngine(), CannotTurnOffEngine);
		car.SetSpeed(1);
		BOOST_CHECK_THROW(car.TurnOffEngine(), CannotTurnOffEngine);
		car.SetGear(0);
		BOOST_CHECK_THROW(car.TurnOffEngine(), CannotTurnOffEngine);
		car.SetSpeed(0);
		BOOST_CHECK_NO_THROW(car.TurnOffEngine());

	}
BOOST_AUTO_TEST_SUITE_END()