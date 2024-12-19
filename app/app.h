#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v5 
{
	// comment for workflow

	double operator "" _inch(unsigned long long x);
	double operator "" _eur(unsigned long long x);

	class tire {
	public:
		tire(double diameter);
		double diameter();
		
	private:
		double diameter_;
	};

	class vehicle {
	public:
		vehicle(int year);
		int year();
	private:
		int year_;
	};

	class product {
	public:
		product(double price);
		double price();
	private:
		double price_;
	};

	class car: public vehicle, public product {
	public:
		car(double year, double price, double wheel_diameter);
		double tire_diameter();
	private:
		tire tire_;
	};


}