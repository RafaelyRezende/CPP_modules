#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
	private:
		std::string 	_name;
		int		_healthPoints;
		int		_energyPoints;
		int		_attackPoints;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		virtual ~ClapTrap();

		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		repair(unsigned int amount);

		std::string	getName() const;
		int		getHitPoints() const;

};

#endif
