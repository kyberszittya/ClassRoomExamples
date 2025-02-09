// BookOperatorOverloading.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>

class Book
{
private:
	const std::string name;
	const std::string author;
	int length;
public:
	Book(const std::string name, const std::string author, int length) :
		name(name), author(author), length(length)
	{}

	std::string getName() const
	{
		return name;
	}

	std::string getAuthor() const
	{
		return author;
	}

	int getLength() const
	{
		return length;
	}
};

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.getName() << "," << book.getAuthor() << ',' << book.getLength();
	return os;
}

Book operator+(const Book& b0, const Book& b1)
{
	Book b2(b0.getName(), b0.getAuthor(), b0.getLength() + b1.getLength());
	return b2;
}

int main()
{
	Book book("Lord of the Rings","J.R.R. Tolkien", 1200);
	Book book1("Musashi", "Yoshikawa Eiji", 1000);
	Book book2("The Foundation", "Isaac Asimov", 1000);
	std::cout << book << '\n';
	std::cout << book1 << '\n';
	std::cout << book2 << '\n';
	std::cout << book1 + book2 << '\n';
	std::ofstream f0("books.txt");
	if (f0.is_open())
	{
		f0 << book << '\n';
		f0 << book1 << '\n';
		f0 << book2 << '\n';
	}
	return 0;
}

