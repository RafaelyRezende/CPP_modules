#include "Harl.h"

int	main() {
	Harl harl;

	std::cout << "--- Testing DEBUG ---" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "--- Testing INFO ---" << std::endl;
	harl.complain("INFO");
	
	std::cout << "--- Testing WARNING ---" << std::endl;
	harl.complain("WARNING");
	
	std::cout << "--- Testing WARN ---" << std::endl;
	harl.complain("WARN");

	std::cout << "--- Testing ERROR ---" << std::endl;
	harl.complain("ERROR");

	std::cout << "--- Testing ERR ---" << std::endl;
	harl.complain("ERR");
	
	std::cout << "--- Testing INVALID ---" << std::endl;
	harl.complain("something_else");
	
	return 0;
}
