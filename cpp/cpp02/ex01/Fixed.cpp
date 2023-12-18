/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:22:16 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 11:22:17 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) : fixedPointValue(source.getRawBits())
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits() called" << std::endl;
    this->fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->fixedPointValue / (float)(1 << this->fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->fixedPointValue >> this->fractionalBits);
}

Fixed & Fixed::operator = (const Fixed &val)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &val)
        return (*this);
    this->fixedPointValue = val.getRawBits();
    return (*this);
}

std::ostream & operator << (std::ostream& out, const Fixed& val)
{
    out << val.toFloat();
    return (out);
}
