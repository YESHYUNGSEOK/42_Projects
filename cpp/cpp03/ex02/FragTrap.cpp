/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:16:32 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 14:55:06 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "default";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& source)
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "FragTrap " << name << " copy constructor called" << std::endl;

}

FragTrap& FragTrap::operator=(const FragTrap& source)
{
	this->name = source.name;
	this->attackDamage = source.attackDamage;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	std::cout << "FragTrap operator = " << name << " called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (!this->hitPoints || !this->energyPoints)
		std::cout << "FragTrap " << this->name << " cannot move..." << std::endl;
	else
	{
		std::cout	<< "FragTrap " << this->name << " attacks " << target
					<< ", causing " << this->attackDamage << " points of damage!"
					<< std::endl;
		this->energyPoints--;
	}
}

void FragTrap::highFivesGuys()
{
	if (!this->hitPoints)
		std::cout << "FragTrap " << this->name << " cannot move..." << std::endl;
	else
		std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}