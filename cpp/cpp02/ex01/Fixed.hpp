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
};

std::ostream & operator << (std::ostream& out, const Fixed& val);

#endif
