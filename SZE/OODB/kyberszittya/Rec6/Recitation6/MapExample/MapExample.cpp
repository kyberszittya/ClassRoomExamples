// MapExample.cpp : Defines the entry point for the console application.
//

#include <map>
#include <iostream>
#include <string>

class Street;

class City
{
private:
	std::string name;
	unsigned int population;
public:
	City(std::string name, unsigned int population): 
		name(name), population(population)
	{

	}

	

	friend std::ostream& operator<<(std::ostream& os, const City& city);
	friend Street;
};

class Street
{
private:
	City * city;
public:
	void getCity()
	{
		city->population;
	}
};

std::ostream& operator<<(std::ostream& os, const City& city)
{
	os << city.name << '\t' << city.population;
	return os;
}

int main()
{
	std::map<std::string, City*> city_map;
	city_map["Budapest"] = new City("Budapest", 1970000);
	city_map["Gyor"] = new City("Gyor", 156000);
	city_map["Pecs"] = new City("Pecs", 180000);
	city_map.insert(city_map.begin(),
		std::pair<std::string, City*>("Szekesfehervar", 
			new City("Szekesfehervar", 160000)));

	std::cout << *city_map["Budapest"] << std::endl;

	for (const auto& p : city_map)
	{
		std::cout << p.first << '\n';
		std::cout << *p.second << '\n';
	}

	for (const auto& p : city_map)
	{
		delete p.second;
	}
    return 0;
}

