/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:31:38 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 15:31:47 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat &source)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	*this = source;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
	std::cout << "[Cat] Assignment operator called" << std::endl;
	if (this != &source)
		this->type = source.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow Meow" << std::endl;
}