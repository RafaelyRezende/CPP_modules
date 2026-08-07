#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	/* --- Valid construction and operator<< --- */
	std::cout << "=== Valid bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 150);
		Bureaucrat carol("Carol", 42);
		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << carol << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	/* --- Construction with grade too high --- */
	std::cout << "\n=== Grade too high at construction ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 0);
		std::cout << boss << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	/* --- Construction with grade too low --- */
	std::cout << "\n=== Grade too low at construction ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 151);
		std::cout << intern << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	/* --- Increment / decrement inside range --- */
	std::cout << "\n=== Increment / decrement ===" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 3);
		std::cout << dave << std::endl;
		dave.incrementGrade();   // 3 -> 2 (promotion)
		std::cout << "After increment: " << dave << std::endl;
		dave.decrementGrade();   // 2 -> 3 (demotion)
		std::cout << "After decrement: " << dave << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	/* --- Increment past the top --- */
	std::cout << "\n=== Increment past grade 1 ===" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 1);
		std::cout << eve << std::endl;
		eve.incrementGrade();
		std::cout << eve << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	/* --- Decrement past the bottom --- */
	std::cout << "\n=== Decrement past grade 150 ===" << std::endl;
	try
	{
		Bureaucrat frank("Frank", 150);
		std::cout << frank << std::endl;
		frank.decrementGrade();
		std::cout << frank << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return 0;
}
