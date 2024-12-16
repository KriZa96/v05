#include "CppUnitTest.h"
#include "../app/app.h"

#include <type_traits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace vsite::oop::v5;

namespace all_tests
{
	TEST_CLASS(test_v05)
	{
	public:

		TEST_METHOD(inch_user_defined_literal)
		{
			auto d = 10_inch;
			Assert::AreEqual(25.4, d);
			Assert::IsTrue(std::is_same_v<double, decltype(d)>);
		}

		TEST_METHOD(tire_class)
		{
			tire left_front(20_inch);
			Assert::AreEqual(50.8, left_front.diameter());
		}

		TEST_METHOD(vehicle_class)
		{
			vehicle v(2020);
			Assert::AreEqual(2020, v.year());
		}

		TEST_METHOD(eur_user_defined_literal)
		{
			auto m = 100_eur;
			Assert::AreEqual(753.45, m);
			Assert::IsTrue(std::is_same_v<double, decltype(m)>);
		}

		TEST_METHOD(product_class)
		{
			product p(1500_eur);
			Assert::AreEqual(11'301.75, p.price());
		}
		
		TEST_METHOD(car_one)
		{
			car peugot(2022, 100'000_eur, 17_inch);
			Assert::AreEqual(2022, peugot.year());
			Assert::AreEqual(753'450., peugot.price());
			Assert::AreEqual(43.18, peugot.tire_diameter());
		}

		TEST_METHOD(car_two)
		{
			car honda(2015, 20'000_eur, 16_inch);
			Assert::AreEqual(2015, honda.year());
			Assert::AreEqual(150'690., honda.price());
			Assert::AreEqual(40.64, honda.tire_diameter());
		}

		TEST_METHOD(car_hierarchy)
		{
			Assert::IsFalse(std::is_default_constructible_v<tire>);
			Assert::IsFalse(std::is_default_constructible_v<vehicle>);
			Assert::IsFalse(std::is_default_constructible_v<product>);
			Assert::IsFalse(std::is_default_constructible_v<car>);
			Assert::IsTrue(std::is_base_of_v<vehicle, car>);
			Assert::IsTrue(std::is_base_of_v<product, car>);
			Assert::IsFalse(std::is_base_of_v<tire, car>);
		}
	};
}
