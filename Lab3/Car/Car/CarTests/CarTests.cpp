// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Car/Car.h"

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
		BOOST_CHECK(action());
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
		BOOST_CHECK(!action());
		BOOST_CHECK_EQUAL(car.EngineIsOn(), clone.EngineIsOn());
		BOOST_CHECK_EQUAL(car.GetGear(), clone.GetGear());
		BOOST_CHECK_EQUAL(car.GetSpeed(), clone.GetSpeed());
	}
};

BOOST_FIXTURE_TEST_SUITE(CarTest, Car_)
	BOOST_AUTO_TEST_CASE(when_turned_off_can_only_switch_to_neutral_gear)
	{
		ExpectTurnedOnCarStateAfterAction(car.SetGear(0), 0, 0);
		ExpectActionFailure(car.SetSpeed(10));
		ExpectActionFailure(car.SetGear(1));
		ExpectActionFailure(car.SetGear(-1));
	}
	BOOST_AUTO_TEST_CASE(can_be_turned_on_where_default_state_is_zero_speed_and_zero_gear)
	{
		ExpectTurnedOnCarStateAfterAction(car.TurnOnEngine(), 0, 0);
		
	}
	struct at_1st_gear : Car_
	{
		at_1st_gear()
		{
			BOOST_REQUIRE(car.TurnOnEngine());
			BOOST_REQUIRE(car.isTurnedOn());
			BOOST_REQUIRE(car.SetGear(1));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 1);
		}
	};
	struct at_2st_gear : at_1st_gear
	{
		at_2st_gear()
		{
			BOOST_REQUIRE(car.SetSpeed(20));
			BOOST_REQUIRE(car.SetGear(2));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 2);
		}
	};
	struct at_3st_gear : at_2st_gear
	{
		at_3st_gear()
		{
			BOOST_REQUIRE(car.TurnOnEngine());
			BOOST_REQUIRE(car.isTurnedOn());
			BOOST_REQUIRE(car.SetGear(3));
			BOOST_REQUIRE_EQUAL(car.GetGear(), 3);
		}
	};

BOOST_AUTO_TEST_SUITE_END()
/*
BOOST_FIXTURE_TEST_SUITE(CarTest, CarFixture)
	BOOST_AUTO_TEST_CASE(Is_turned_off_by_default)
	{
		BOOST_CHECK(!car.isTurnedOn());
	}

	BOOST_AUTO_TEST_CASE(Can_only_shift_gear_to_neutral_when_turned_off)
	{
		BOOST_CHECK(!car.SetGear(-1));
		BOOST_CHECK(!car.SetGear(1));
		BOOST_CHECK(car.SetGear(0));
	}
	BOOST_AUTO_TEST_CASE(Can_be_turned_on)
	{
		BOOST_CHECK(car.TurnOnEngine());
	}
	BOOST_AUTO_TEST_CASE(Gear_is_neutral_and_speed_is_zero_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetGear, 0);
		BOOST_CHECK_EQUAL(car.GetSpeed, 0);
	}
	BOOST_AUTO_TEST_CASE(Сar_can_only_decelerate_when_gear_is_neutral)
	{
		unsigned speed = car.GetSpeed();
		BOOST_CHECK(!car.SetSpeed(speed + 1));
		BOOST_CHECK(car.SetSpeed(0));
	}
	void CheckGearRange(CCar & testCar, int gear, unsigned minSpeed, unsigned maxSpeed)
	{
		testCar.SetGear(gear);
		BOOST_CHECK(testCar.SetSpeed(minSpeed));
		BOOST_CHECK(testCar.SetSpeed(maxSpeed));
		BOOST_CHECK(!testCar.SetSpeed(maxSpeed + 1));
		BOOST_CHECK(!testCar.SetSpeed(minSpeed - 1));
	}
	BOOST_AUTO_TEST_CASE(Speed_can_only_be_changed_in_range_of_current_gear)
	{
		CCar car1;
		CheckGearRange(car1, -1, 0, 20);
		car1.SetGear(0);
		car1.SetSpeed(0);
		CheckGearRange(car1, 1, 0, 30);
		CheckGearRange(car1, 2, 20, 50);
		CheckGearRange(car1, 3, 30, 60);
		CheckGearRange(car1, 4, 40, 90);
		CheckGearRange(car1, 5, 50, 150);
		BOOST_CHECK(!car1.SetGear(6));
	}
	BOOST_AUTO_TEST_CASE(Gear_can_be_shifted_if_current_direction_allowed_it)
	{
		car.SetGear(1);
		car.SetSpeed(1);
		BOOST_CHECK(!car.SetGear(-1));
		car.SetSpeed(0);
		BOOST_CHECK(car.SetGear(-1));
		car.SetSpeed(2);
		BOOST_CHECK(!car.SetGear(1));
		car.SetSpeed(0);
		BOOST_CHECK(car.SetGear(1));

		car.SetSpeed(10);
		car.SetGear(0);
		BOOST_CHECK(!car.SetGear(-1));
		BOOST_CHECK(car.SetGear(1));

		car.SetSpeed(0);
		car.SetGear(-1);
		car.SetSpeed(10);
		car.SetGear(0);
		BOOST_CHECK(!car.SetGear(1));
		BOOST_CHECK(car.SetGear(-1));

	}
	BOOST_AUTO_TEST_CASE(And_current_speed_in_range_of_speed_of_new_gear)
	{
		/ *
		Передача	Диапазон скоростей
		Задний ход	0 – 20
		Нейтраль	Без ограничений
		Первая	0 – 30
		Вторая	20 – 50
		Третья	30 – 60
		Четвертая	40 – 90
		Пятая	50 – 150
		* /
		car.SetGear(-1);
		BOOST_CHECK(car.SetSpeed(0));
		BOOST_CHECK(car.SetSpeed(20));
		BOOST_CHECK(!car.SetSpeed(21));
		BOOST_CHECK(!car.SetGear(-2));
		car.SetGear(0);
		car.SetSpeed(0);
		car.SetGear(1);
		BOOST_CHECK(car.SetSpeed(0));
		BOOST_CHECK(car.SetSpeed(30));
		BOOST_CHECK(!car.SetSpeed(31));
		car.SetGear(2);
		BOOST_CHECK(car.SetSpeed(20));
		BOOST_CHECK(car.SetSpeed(50));
		BOOST_CHECK(!car.SetSpeed(51));
		BOOST_CHECK(!car.SetSpeed(19));
		car.SetGear(3);
		BOOST_CHECK(car.SetSpeed(30));
		BOOST_CHECK(car.SetSpeed(60));
		BOOST_CHECK(!car.SetSpeed(29));
		BOOST_CHECK(!car.SetSpeed(61));
		car.SetGear(4);
		BOOST_CHECK(car.SetSpeed(40));
		BOOST_CHECK(car.SetSpeed(90));
		BOOST_CHECK(!car.SetSpeed(39));
		BOOST_CHECK(!car.SetSpeed(91));
		car.SetGear(5);
		BOOST_CHECK(car.SetSpeed(50));
		BOOST_CHECK(car.SetSpeed(150));
		BOOST_CHECK(!car.SetSpeed(49));
		BOOST_CHECK(!car.SetSpeed(151));
		BOOST_CHECK(!car.SetGear(6));

	}
	/ *BOOST_AUTO_TEST_CASE(Engine_can_only_be_turned_off_at_zero_speed_and_neutral_gear)
	{
		CCar car;
		car.TurnOnEngine();
		car.SetGear(1);
		car.SetSpeed(0);
		BOOST_CHECK_EQUAL(car.TurnOffEngine, false);
		car.SetGear(0);
		BOOST_CHECK_EQUAL(car.TurnOffEngine, true);
	}* /
	BOOST_AUTO_TEST_CASE(While_engine_is_turned_on_can_shift_gear_if_current_speed_is_at_a_range_of_speed_of_newer_gear_and_its_allowed_for_current_direction)
	{
		car.SetGear(1);
	}
BOOST_AUTO_TEST_SUITE_END()*/