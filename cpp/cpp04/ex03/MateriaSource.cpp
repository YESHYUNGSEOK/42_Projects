/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:13:40 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 10:24:54 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource() : count(0)
{
	std::cout << "[MateriaSource] Default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & source)
{
	std::cout << "[MateriaSource] Copy constructor called." << std::endl;
	*this = source;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] Destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
}

MateriaSource & MateriaSource::operator = (const MateriaSource & source)
{
	std::cout << "[MateriaSource] Assignation operator called." << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = source.inventory[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->count < 4)
	{
		this->inventory[this->count] = m;
		this->count++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
	}
	return (NULL);
}
