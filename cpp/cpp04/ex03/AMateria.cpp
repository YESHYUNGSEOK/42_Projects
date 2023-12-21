/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:13:12 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/20 09:18:12 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "[AMateria] Default constructor called." << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "[AMateria] Constructor called." << std::endl;
}

AMateria::AMateria(const AMateria & source)
{
	std::cout << "[AMateria] Copy constructor called." << std::endl;
	*this = source;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] Destructor called." << std::endl;
}

AMateria & AMateria::operator = (const AMateria & source)
{
	std::cout << "[AMateria] Assignation operator called." << std::endl;
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] * use Materia on " << target.getName() << " *" << std::endl;
}
