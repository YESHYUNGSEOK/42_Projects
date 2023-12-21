/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:09:28 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 10:18:29 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : name("default"), count(0)
{
	std::cout << "[Character] Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(std::string const & name) : name(name), count(0)
{
	std::cout << "[Character] Constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character & source)
{
	std::cout << "[Character] Copy constructor called." << std::endl;
	*this = source;
}

Character::~Character()
{
	std::cout << "[Character] Destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

Character & Character::operator = (const Character & source)
{
	std::cout << "[Character] Assignation operator called." << std::endl;
	if (this != &source)
	{
		this->name = source.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = source.inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (this->count == 4 || !m)
		return ;
		
	for (int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			this->count++;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return ;
	this->inventory[idx] = NULL;
	this->count--;
	if (this->count < 0)
		this->count = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || !this->inventory[idx])
		return ;
	this->inventory[idx]->use(target);
}
