// SphereCalculation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

class Sphere
{
private:
	double radius;
public:
	Sphere(): Sphere(1.0)
	{}

	Sphere(double radius): radius(radius)
	{
		std::cout << "CTOR itt\n";
	}

	Sphere(const Sphere& other)
	{
		std::cout << "copy sphere itt\n";
		radius = other.radius;
	}

	~Sphere()
	{
		std::cout << "DTOR itt\n";
	}
};

class SphereContainer
{
private:
	Sphere *spheres;
public:
	SphereContainer(int cnt)
	{
		spheres = new Sphere[cnt];
		std::cout << "SphereContainer CTOR\n";
	}

	~SphereContainer()
	{
		delete[] spheres;
		std::cout << "Spherecontainer DTOR\n";
	}
};

void fv()
{
	Sphere* sp;
	sp = new Sphere(10.0);
	delete sp;
	Sphere sp0(5.0);
	Sphere sp1(sp0);
	Sphere sp2 = sp1;
	SphereContainer spherecontainer(10);
	// Dinamikus sphere container
	SphereContainer* spherecontainer2 = new SphereContainer(10);
	delete spherecontainer2;

}

int main()
{
	fv();
#ifdef _WIN32
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif // _WIN32
    return 0;
}

