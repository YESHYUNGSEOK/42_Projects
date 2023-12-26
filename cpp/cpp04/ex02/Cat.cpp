/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:40:28 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/26 10:21:00 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::~Cat()
{
	if (this->brain)
		delete this->brain;
	std::cout << "[Cat] Destructor called" << std::endl;
}

Cat::Cat(const Cat &source)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	this->type = source.type;
	if (source.brain)
		this->brain = new Brain(*source.brain);
	else
		this->brain = NULL;
}

Cat	&Cat::operator=(const Cat &source)
{
	std::cout << "[Cat] Assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	this->type = source.type;
	if (this->brain)
		delete this->brain;
	if (source.brain)
		this->brain = new Brain(*source.brain);
	else
		this->brain = NULL;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow Meow" << std::endl;
}

Brain & Cat::getBrain(void) const
{
    return (*this->brain);
}