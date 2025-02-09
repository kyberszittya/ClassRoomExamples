// SphereList.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Shape
{
public:
	virtual double getVolume() = 0;
};

class Sphere : public Shape
{
private:
	const double radius;
public:
	Sphere(const double radius): radius(radius){}

	virtual double getVolume()
	{
		return radius * radius * radius;
	}
};

class Cube : public Shape
{
private:
	const double a;
public:
	Cube(const double a) : a(a) {}

	virtual double getVolume()
	{
		return a * a * a;
	}
};

void shapeProgram()
{
	std::vector<Shape*> shapes;
	shapes.reserve(4);
	shapes.push_back(new Sphere(10.0));
	shapes.push_back(new Sphere(6.0));
	shapes.push_back(new Sphere(2.0));
	shapes.push_back(new Cube(2.0));

	//for (std::vector<Shape*>::iterator it = shapes.begin(); 
	//	it != shapes.end(); 
	//	it++)
	for (const auto& v : shapes)
	{
		std::cout << v->getVolume() << '\n';
	}

	std::cout << "Volume of #2 shape: " << 
		shapes[2]->getVolume() << '\n';
	for (const auto& v : shapes)
	{
		if (dynamic_cast<Cube*>(v)!=nullptr)
		{
			std::cout << "It's a cube\n";
		}
		else if (dynamic_cast<Sphere*>(v) != nullptr)
		{
			std::cout << "It's a sphere\n";
		}
	}

	
	for (const auto& v : shapes)
	{
		delete v;
	}
	
}

int main()
{
	shapeProgram();
	_CrtDumpMemoryLeaks();
    return 0;
}

