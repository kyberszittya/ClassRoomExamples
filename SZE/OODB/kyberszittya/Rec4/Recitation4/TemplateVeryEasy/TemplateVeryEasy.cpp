// TemplateVeryEasy.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

class Book
{
private:
	std::string name;
public:
	Book() {};
	Book(std::string name) : name(name) {}
	Book(const Book& other) : name(other.name) {}
	Book& operator=(const Book& book)
	{
		this->name = book.name;
		return *this;
	}

	std::string getName() const
	{
		return name;
	}
};

class Article
{
private:
	std::string name;
public:
	Article() {}
	Article(std::string name) : name(name) {}

	std::string getName() const
	{
		return name;
	}
};

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.getName();
	return os;
}

std::ostream& operator<<(std::ostream& os, const Article& article)
{
	os << article.getName();
	return os;
}

constexpr unsigned int SIZE = 10;

template<class T> class Array
{
private:
	int cnt_elements;
	T* books;
public:
	Array(): cnt_elements(0), books(new T[SIZE]) {}

	~Array()
	{
		delete[] books;
	}

	void addElement(T& book)
	{
		if (cnt_elements < SIZE)
		{
			books[cnt_elements] = book;
			cnt_elements++;
		}
		else
		{
			std::cerr << "Array is full\n";
		}
	}

	void listElements()
	{
		
		for (int i = 0; i < cnt_elements; i++)
		{
			std::cout << books[i] << '\n';
		}
		std::cout << "Elements: " << cnt_elements << '\n';
	}
};

void main_func()
{
	Array<Book> arr;
	Book b("Lord of the Rings");
	Book b1("Harry Potter");
	Book b2("Aranyember");
	arr.addElement(b);
	arr.addElement(b1);
	arr.addElement(b2);
	arr.listElements();
	Array<Article> arr2;
	Article a1("Uj cikk");
	arr2.addElement(a1);
	arr2.listElements();
}

int main()
{
	main_func();
	_CrtDumpMemoryLeaks();
    return 0;
}

