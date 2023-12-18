/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:40:28 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 14:55:56 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog &source)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	*this = source;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
	std::cout << "[Dog] Assignment operator called" << std::endl;
	if (this != &source)
		this->type = source.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof Woof" << std::endl;
}