#include "PhoneBook.hpp"
#include <csignal>
#include <unistd.h>

volatile sig_atomic_t	appOn = 1;

void	handle_sig(int signum)
{
	if (signum == SIGINT)
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
		return (1);

	do {
		std::cout << "Enter command: ";
		std::getline(std::cin, line);
		
		if (line == "ADD")
			pb.addContact();
		else if (line == "SEARCH")
			pb.searchContact();
	}	while (!std::cin.eof() && line != "EXIT");
}
