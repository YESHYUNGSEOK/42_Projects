/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:22:13 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 09:23:25 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "[Ice] Default constructor called." << std::endl;
}

Ice::Ice(const Ice & source)
{
	std::cout << "[Ice] Copy constructor called." << std::endl;
	*this = source;
}

Ice::~Ice()
{
	std::cout << "[Ice] Destructor called." << std::endl;
}

Ice & Ice::operator = (const Ice & source)
{
	std::cout << "[Ice] Assignation operator called." << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "[Ice] * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}