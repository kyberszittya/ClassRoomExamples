// CubeVolume.cpp : Defines the entry point for the console application.
//

#include <iostream>

#include "Cube.h"

using namespace std;

int main()
{
	double a, b, c;
	cout << "A oldal: ";
	cin >> a;
	cout << "B oldal: ";
	cin >> b;
	cout << "C oldal: ";
	cin >> c;
	Cube cube({ a, b, c });
	if (cube.validCube())
	{
		cout << "A kocka térfogata: " << cube.volume() << '\n';
	}
	else
	{
		cerr << "Nem jó a kocka" << '\n';
	}

    return 0;
}

