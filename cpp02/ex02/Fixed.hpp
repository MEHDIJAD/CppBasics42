// #pragma once
#ifndef _FIXED_HPP_
#define _FIXED_HPP_

#include <ostream>
class Fixed
{
	private:
		int fixedPoint;
		static const int FRACTIONAL_BITS;
	public:
		/* Default Constructor */
		Fixed( void );

		/*! @brief Parametrize Constructor for INT
		converts @param decimal to the corresponding fixed-point value
		*/
		Fixed(const int decimal);

		/*! @brief Parametrize Constructor for FLOAT
		converts @param real to the corresponding fixed-point value
		*/
		Fixed(const float real);
		/* Copy Constructor */
		Fixed(const Fixed &other);
		/* Assignment Operator */
		Fixed &operator=(const Fixed &other);
		/* Destructor */
		~Fixed();

		int getRawBits( void ) const ;
		void setRawBits( int const raw );

		/*! @brief converts the fixed-point value to a floating-point value.*/
		float toFloat( void ) const;

		/*! @brief converts the fixed-point value to an integer value*/
		int toInt( void ) const;	

		/* Comparison operators */
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		// Increment/Decrement operators
		Fixed &operator++();   // Pre-increment
		Fixed operator++(int); // Post-increment
		Fixed &operator--();   // Pre-decrement
		Fixed operator--(int); // Post-decrement

		// Static member functions
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};
	
/* Overloading the inserrtion operator (<<)*/
std::ostream &operator<<(std::ostream &os, const Fixed &fixed);


#endif
