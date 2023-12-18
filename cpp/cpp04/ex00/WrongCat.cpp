/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:30:36 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 15:30:38 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &source)
{
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = source;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	std::cout << "[WrongCat] Assignment operator called" << std::endl;
	if (this != &source)
		this->type = source.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Meow Meow" << std::endl;
}