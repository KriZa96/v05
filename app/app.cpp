#include "app.h"
#include <algorithm>

namespace vsite::oop::v5
{
	double operator "" _eur(unsigned long long x) {
		return x * 7.5345;
	}
	double operator "" _inch(unsigned long long x) {
		return x * 2.54;
	};

	tire::tire(double diameter): diameter_(diameter) {}

	vehicle::vehicle(int year) : year_(year) {}

	product::product(double price) : price_(price) {}

	car::car(double year, double price, double wheel_diameter)
		: tire(wheel_diameter), vehicle(year), product(price) {}

	double tire::diameter() {
		return diameter_;
	}

	int vehicle::year() {
		return year_;
	}

	double product::price() {
		return price_;
	}

	double car::tire_diameter() {
		return tire.diameter();
	}

}