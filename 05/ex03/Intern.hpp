#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

/* The Intern has no name, no grade, no state at all.
   Its only ability is makeForm(): a factory that builds
   the right concrete AForm from a name string. */
class Intern
{
public:
	/* Orthodox Canonical Form */
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	/* Returns a heap-allocated AForm* (caller must delete it),
	   or NULL if the form name is unknown. */
	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	/* One small creator per concrete form: used by the lookup table
	   in makeForm() instead of an if/else-if chain. */
	AForm*	createShrubbery(const std::string& target) const;
	AForm*	createRobotomy(const std::string& target) const;
	AForm*	createPardon(const std::string& target) const;
};

#endif
