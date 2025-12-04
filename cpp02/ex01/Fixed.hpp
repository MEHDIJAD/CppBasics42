// #pragma once
#ifndef _FIXED_HPP_
#define _FIXED_HPP_

class Fixed
{
	private:
		int fixedPoint;
		static const int FRACTIONAL_BITS;
	public:
		/* Default Constructor */
		Fixed( void );
		/* Copy Constructor */
		Fixed(const Fixed &other);
		/* Assignment Operator */
		Fixed &operator=(const Fixed &other);
		/* Destructor */
		~Fixed();

		int getRawBits( void );
		void setRawBits( int const raw );
};


#endif