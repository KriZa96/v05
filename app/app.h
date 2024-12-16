#pragma once
#include <string>
#include <memory>

namespace vsite::oop::v5 
{
	double operator "" _inch(unsigned long long x);
	double operator "" _eur(unsigned long long x);

	class tire {
	public:
		tire(double diameter);
		~tire() = default;
		double diameter();
		
	private:
		double diameter_;
	};

	class vehicle {
	public:
		vehicle(int year);
		~vehicle() = default;
		int year();
	private:
		int year_;
	};

	class product {
	public:
		product(double price);
		~product() = default;
		double price();
	private:
		double price_;
	};

	class car: public vehicle, public product {
	public:
		car(double year, double price, double wheel_diameter);
		~car() {
			delete _tire;
		}
		double tire_diameter();
	private:
		tire* _tire;
	};


}