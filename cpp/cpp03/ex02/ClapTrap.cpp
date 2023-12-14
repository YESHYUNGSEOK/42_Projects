/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:04:42 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 13:55:00 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{	
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& source) 
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "ClapTrap " << name << " copy constructor called" << std::endl;

}

ClapTrap& ClapTrap::operator=(const ClapTrap& source) 
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "ClapTrap operator = " << name << " called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void) 
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "ClapTrap " << this->name << " cannot move..." << std::endl;
	else
	{
		std::cout	<< "ClapTrap " << this->name << " attacks " << target 
					<< ", causing " << this->attackDamage << " points of damage!"
					<< std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout	<< "ClapTrap " << this->name << " has taken " 
				<< amount << " damage..." << std::endl;
	if (!this->hitPoints)
	{
		std::cout	<< "ClapTrap " << this->name << " is dead" << std::endl; 
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "ClapTrap " << this->name << " cannot move..." << std::endl;
	else
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout	<< "ClapTrap " << this->name << " has been repaired of " 
					<< amount << " Hit points. It has now " << this->hitPoints 
					<< " Hit points" << std::endl;
	}
}