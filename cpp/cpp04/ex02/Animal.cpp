/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:33:22 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 14:55:25 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
	*this = source;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
	std::cout << "[Animal] Assignment operator called" << std::endl;
	if (this != &source)
		this->type = source.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "[Animal] Animal cannot make any sound..." << std::endl;
}