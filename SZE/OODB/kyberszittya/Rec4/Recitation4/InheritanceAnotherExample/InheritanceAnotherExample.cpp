// InheritanceAnotherExample.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

class Vehicle
{
private:
	double mass;
	
protected:
	double speed;

	void accelerate(double a)
	{
		speed += a;
	}
public:
	Vehicle(double mass, double speed) : mass(mass), speed(speed)
	{

	}

	double getSpeed() const
	{
		return speed;
	}
};

class Automobile: public Vehicle
{
private:
	const std::string rendszam;
	const std::string brand;
protected:
public:
	Automobile(double mass, double speed, const std::string rendszam, const std::string brand) :
		Vehicle(mass, speed), rendszam(rendszam), brand(brand) {}

	void throttle()
	{
		accelerate(0.43);
	}

	std::string getRendszam() const
	{
		return rendszam;
	}

	std::string getBrand() const
	{
		return brand;
	}
};

class Airplane : public Vehicle
{
private:
	double length;
protected:
public:
	Airplane(double mass, double length) : Vehicle(mass, 0.0), length(length) {}

	void fly()
	{
		accelerate(9);
	}
};


int main()
{
	Airplane airplane(100000, 270);
	Automobile automobile(1000, 0.0, "576", "Suzuki");
	airplane.fly();
	std::cout << airplane.getSpeed() << std::endl;
	automobile.throttle();
	std::cout << automobile.getRendszam() << ' ' << automobile.getRendszam() << ' ' << automobile.getSpeed() << std::endl;
    return 0;
}

