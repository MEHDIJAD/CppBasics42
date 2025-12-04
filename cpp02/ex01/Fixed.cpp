#include "Fixed.hpp"
#include <iostream>

const int Fixed::FRACTIONAL_BITS = 8;

Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int decimal)
{

}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = other.fixedPoint;
}


// Fixed &Fixed::operator=(const Fixed &other)
// {
// 	if (this != &other)
// 	{
// 		*this = other;
// 	}
// 	std::cout << "Copy assignment operator called" << std::endl;
// 	return (*this);
// }

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

int Fixed::getRawBits(void){
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}
