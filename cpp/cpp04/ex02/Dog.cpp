/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:40:28 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 18:31:46 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
	if (this->brain)
		delete this->brain;
}

Dog::Dog(const Dog &source)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	this->type = source.type;
	if (source.brain)
		this->brain = new Brain(*source.brain);
	else
		this->brain = NULL;
}

Dog	&Dog::operator=(const Dog &source)
{
	std::cout << "[Dog] Assignment operator called" << std::endl;
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

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof Woof" << std::endl;
}

Brain & Dog::getBrain(void) const
{
    return (*this->brain);
}
