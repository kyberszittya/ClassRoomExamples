// Aquarium.cpp : Defines the entry point for the console application.
//

#include <iostream>

class Fish
{
private:
protected:
	double mass;
public:
	Fish() : Fish(10.0) {}
	Fish(double mass) 
	{
		std::cout << "Létrejött a hal" << '\n';
	}

	~Fish()
	{
		std::cout << "Elpusztul" << '\n';
	}

	virtual void speak() const
	{
		std::cout << "Én hal vagyok" << '\n';
	}
};

class Shark : public Fish
{
public:
	Shark(): Fish(1000)
	{
		std::cout << "Cápa létrejött" << '\n';
	}

	~Shark()
	{
		std::cout << "Cápa elpusztul" << '\n';
	}

	virtual void speak() const
	{
		std::cout << "Én vagyok a cápa" << '\n';
	}
};

class Aquarium
{
private:
	Fish * fishes;
	int current_cnt_fishes;
	const int max_cnt_fishes;
public:

	Aquarium(int cnt_fishes) : fishes(new Fish[cnt_fishes]), 
		current_cnt_fishes(0), max_cnt_fishes(cnt_fishes)
	{

	}

	void insertFish(Fish& fish)
	{
		if (current_cnt_fishes <= max_cnt_fishes)
		{
			fishes[current_cnt_fishes] = fish;
			current_cnt_fishes++;
		}
		else
		{
			std::cerr << "Aquarium is too small\n";
		}
	}

	static void speakFish(const Fish& fish)
	{
		fish.speak();
	}

	void listFishes()
	{
		for (int i = 0; i < current_cnt_fishes; i++)
		{
			//speakFish(fishes[i]);
			fishes[i].speak();
		}
	
	}
};



int main()
{
	Fish f(10.0);
	Shark s;
	
	//Aquarium::speakFish(f);
	//Aquarium::speakFish(s);
	Aquarium aquarium(5);
	aquarium.insertFish(f);
	aquarium.insertFish(s);
	aquarium.listFishes();
	return 0;
}

