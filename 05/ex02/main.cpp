#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	/* --- Valid form, successful signature --- */
	std::cout << "=== Successful signature ===" << std::endl;
	{
		Bureaucrat alice("Alice", 20);
		Form tax("Tax return", 50, 100);
		std::cout << tax << std::endl;
		alice.signForm(tax);
		std::cout << tax << std::endl;
	}

	/* --- Bureaucrat grade too low to sign --- */
	std::cout << "\n=== Failed signature (grade too low) ===" << std::endl;
	{
		Bureaucrat bob("Bob", 100);
		Form nda("NDA", 30, 10);
		std::cout << nda << std::endl;
		bob.signForm(nda);
		std::cout << nda << std::endl;
	}

	/* --- Invalid form grades at construction --- */
	std::cout << "\n=== Form with grade too high ===" << std::endl;
	try
	{
		Form bad("Broken", 0, 10);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Form with grade too low ===" << std::endl;
	try
	{
		Form bad("Broken", 10, 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	/* --- Boundary case: grade exactly equal to requirement --- */
	std::cout << "\n=== Exact grade match ===" << std::endl;
	{
		Bureaucrat carol("Carol", 42);
		Form permit("Permit 42", 42, 42);
		carol.signForm(permit);
		std::cout << permit << std::endl;
	}

	return 0;
}
