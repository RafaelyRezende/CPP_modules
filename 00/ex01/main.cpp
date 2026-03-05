#include "PhoneBook.hpp"
#include <csignal>
#include <unistd.h>

volatile sig_atomic_t	appOn = 1;

void	handle_sig(int signum)
{
	(void)signum;
	appOn = 0;
}

int	main()
{
	std::string			line;
	struct sigaction	sa;
	PhoneBook			pb;

	sa.sa_handler = &handle_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		std::cerr << "Error setting up signal handler" << std::endl;
		return (1);
	}
	while (appOn)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, line))
		{
			if (std::cin.eof())
			{
				std::cout << "\nexit" << std::endl;
				break;
			}
			std::cin.clear();
			std::cout << std::endl;
			continue;
		}
		if (line == "ADD")
			pb.addContact();
		else if (line == "SEARCH")
			pb.searchContact();
		else if (line == "EXIT")
			break;
	}
	return (0);
}
