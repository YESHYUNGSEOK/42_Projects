#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &source);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap &operator=(const FragTrap &source);
		void attack(const std::string &target);
		void highFivesGuys();
};

#endif