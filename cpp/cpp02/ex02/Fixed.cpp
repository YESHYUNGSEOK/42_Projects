/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:07:45 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/18 14:29:38 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &source)
{
    *this = source;
}

Fixed::Fixed(const int value)
{
    this->fixedPointValue = value << this->fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->fixedPointValue = roundf(value * (1 << this->fractionalBits));
}

Fixed::~Fixed(void)
{
}

int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
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
    this->fixedPointValue = val.getRawBits();
    return (*this);
}

bool Fixed::operator > (const Fixed &val) const
{
    return (this->getRawBits() > val.getRawBits());
}

bool Fixed::operator < (const Fixed &val) const
{
    return (this->fixedPointValue < val.getRawBits());
}

bool Fixed::operator >= (const Fixed &val) const
{
    return (this->fixedPointValue >= val.getRawBits());
}

bool Fixed::operator <= (const Fixed &val) const
{
    return (this->fixedPointValue <= val.getRawBits());
}

bool Fixed::operator == (const Fixed &val) const
{
    return (this->fixedPointValue == val.getRawBits());
}

bool Fixed::operator != (const Fixed &val) const
{
    return (!(*this == val));
}

Fixed Fixed::operator + (const Fixed &val)
{
    Fixed tmp(this->toFloat() + val.toFloat());
    return (tmp);
}

Fixed Fixed::operator - (const Fixed &val)
{
    Fixed tmp(this->toFloat() - val.toFloat());
    return (tmp);
}

Fixed Fixed::operator * (const Fixed &val)
{
    Fixed tmp(this->toFloat() * val.toFloat());
    return (tmp);
}

Fixed Fixed::operator / (const Fixed &val)
{
    Fixed tmp(this->toFloat() / val.toFloat());
    return (tmp);
}

Fixed & Fixed::operator++ (void)
{
    this->fixedPointValue++;
    return (*this);
}

const Fixed Fixed::operator++ (int)
{
    const Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

Fixed & Fixed::operator-- (void)
{
    this->fixedPointValue--;
    return (*this);
}

const Fixed Fixed::operator-- (int)
{
    const Fixed tmp(*this);
    --(*this);
    return (tmp);
}

Fixed & Fixed::min(Fixed &val1, Fixed &val2)
{
    return (val1 < val2 ? val1 : val2);
}

Fixed & Fixed::min (const Fixed &val1, const Fixed &val2)
{
    return (val1 < val2 ? (Fixed &)val1 : (Fixed &)val2);
}

Fixed & Fixed::max(Fixed &val1, Fixed &val2)
{
    return (val1 > val2 ? val1 : val2);
}

Fixed & Fixed::max (const Fixed &val1, const Fixed &val2)
{
    return (val1 > val2 ? (Fixed &)val1 : (Fixed &)val2);
}

std::ostream & operator << (std::ostream& out, const Fixed& val)
{
    out << val.toFloat();
    return (out);
}
