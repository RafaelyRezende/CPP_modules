#include "Harl.h"

Harl::Harl() {}
Harl::~Harl() {}

void	Harl::debug(void) {
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years.\n" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	typedef void	(Harl::*HarlLog)(void);

	HarlLog		funs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	lvl[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < MAX_LOG; i++) {
		if (lvl[i] == level) {
			(this->*funs[i])();
			return ;
		}
	}
	std::cout << "[Unknown level]: " << level << std::endl;
}
