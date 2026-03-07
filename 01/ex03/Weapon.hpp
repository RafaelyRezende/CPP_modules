#pragma once

# include <iostream>
# include <string>

class	Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(std::string t);
	~Weapon();

	const std::string&	getType() const;
	void				setType(std::string t);
	void				dispType();
};
