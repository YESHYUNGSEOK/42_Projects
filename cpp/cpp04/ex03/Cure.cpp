/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:24:10 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 09:24:53 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	std::cout << "[Cure] Default constructor called." << std::endl;
}

Cure::Cure(const Cure & source)
{
	std::cout << "[Cure] Copy constructor called." << std::endl;
	*this = source;
}

Cure::~Cure()
{
	std::cout << "[Cure] Destructor called." << std::endl;
}

Cure & Cure::operator = (const Cure & source)
{
	std::cout << "[Cure] Assignation operator called." << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "[Cure] * heals " << target.getName() << "'s wounds *" << std::endl;
}
