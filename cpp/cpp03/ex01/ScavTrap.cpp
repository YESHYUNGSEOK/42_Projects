/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:16:32 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 14:54:45 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& source)
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "ScavTrap " << name << " copy constructor called" << std::endl;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& source)
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "ScavTrap operator = " << name << " called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "ScavTrap " << this->name << " cannot move..." << std::endl;
	else
	{
		std::cout	<< "ScavTrap " << this->name << " attacks " << target
					<< ", causing " << this->attackDamage << " points of damage!"
					<< std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate()
{
	if (!this->hitPoints)
		std::cout << "ScavTrap " << this->name << " cannot move..." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}