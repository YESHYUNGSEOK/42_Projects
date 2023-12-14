/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:07:34 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/12/14 12:07:35 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int fractionalBits = 8;
    public:
        Fixed(void);
        Fixed(const Fixed &source);
        Fixed(const int value);
        Fixed(const float value);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        Fixed & operator = (const Fixed &val);
        
        bool operator > (const Fixed &val) const;
        bool operator < (const Fixed &val) const;
        bool operator >= (const Fixed &val) const;
        bool operator <= (const Fixed &val) const;
        bool operator == (const Fixed &val) const;
        bool operator != (const Fixed &val) const;

        Fixed operator + (const Fixed &val);
        Fixed operator - (const Fixed &val);
        Fixed operator * (const Fixed &val);
        Fixed operator / (const Fixed &val);

        Fixed & operator ++ (void);
        const Fixed operator ++ (int);
        Fixed & operator -- (void);
        const Fixed operator -- (int);

        static Fixed & min(Fixed &val1, Fixed &val2);
        static Fixed & min (const Fixed &val1, const Fixed &val2);
        static Fixed & max(Fixed &val1, Fixed &val2);
        static Fixed & max (const Fixed &val1, const Fixed &val2);
};

std::ostream & operator << (std::ostream& out, const Fixed& val);

#endif
