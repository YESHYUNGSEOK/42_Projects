#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &source);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &source);
		void attack(const std::string &target);
		void guardGate();
};

#endif