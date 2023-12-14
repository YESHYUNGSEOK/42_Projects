#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int fixedPointValue;
		static const int fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &source);
		Fixed& operator=(const Fixed &source);
		~Fixed(void);
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif