#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::FRACTIONAL_BITS = 8;

/* Default Constructor */
Fixed::Fixed( void ) : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Parametrize Constructor for INT */
Fixed::Fixed(const int decimal)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = decimal << Fixed::FRACTIONAL_BITS;

	
	// This is like decimal * 2^FRACTION_BITS
	// -> this->fixedPoint = decimal * pow(2, Fixed::FRACTIONAL_BITS);

	// OR this->fixedPoint = decimal * 256;

}

/* Parametrize Constructor for FLOAT */
Fixed::Fixed(const float real)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(real * (1 << Fixed::FRACTIONAL_BITS));
	// This is like round(real * 2^FRACTION_BITS OR * 252)
	// 1 << 8 EVAL to 256
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &other) /* : fixedPoint(other.getRawBits())  */ {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}


/* Assignment Operator */
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		fixedPoint = other.fixedPoint;
	}
	return (*this);
}

/* Destructor */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* Set func */
void Fixed::setRawBits(int const raw){
	this->fixedPoint = raw;
}

/* Get func */
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}


float Fixed::toFloat( void ) const
{
	/*! @brief  This is like doing: 
		floatPoint = fixedPoint / 2^8(256)
		and we cast it to float so we do not lose the fraction
	*/ 
	return ((float)this->fixedPoint / (1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt( void ) const
{
	/*! @brief we do need to / 2^8(256) we can just
		shift back to the original number
	*/
	return (this->fixedPoint >> Fixed::FRACTIONAL_BITS);

	// return (this->fixedPoint / pow(2, Fixed::FRACTIONAL_BITS));
		// return (this->fixedPoint / 256);
}

/* Comparison operators */
bool Fixed::operator>(const Fixed &other) const {
	return this->fixedPoint > other.fixedPoint;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->fixedPoint < other.fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->fixedPoint >= other.fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->fixedPoint <= other.fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->fixedPoint == other.fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->fixedPoint != other.fixedPoint;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->fixedPoint + other.fixedPoint);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->fixedPoint - other.fixedPoint);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	// Multiply the raw integer values, then shift right by FRACTIONAL_BITS
	// to get the result in the correct fixed-point format.
	// Use long long for intermediate product to prevent overflow
	result.setRawBits((static_cast<long long>(this->fixedPoint) * other.fixedPoint) >> FRACTIONAL_BITS);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	// To divide, we multiply the numerator by 2^FRACTIONAL_BITS
	// before dividing by the denominator to maintain precision.
	// Use long long for intermediate product to prevent overflow
	if (other.fixedPoint == 0) {
		std::cerr << "Error: Division by zero!" << std::endl;
		// Depending on requirements, could throw an exception or return a specific value
		// For now, returning a default constructed Fixed object.
		return Fixed();
	}
	result.setRawBits((static_cast<long long>(this->fixedPoint) << FRACTIONAL_BITS) / other.fixedPoint);
	return result;
}

// Increment/Decrement operators
Fixed &Fixed::operator++() {
	this->fixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this; // Save current state
	this->fixedPoint++; // Increment
	return temp;        // Return saved state
}

Fixed &Fixed::operator--() {
	this->fixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this; // Save current state
	this->fixedPoint--; // Decrement
	return temp;        // Return saved state
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}


std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	/*! @brief Here we overlod the inserrtion operator 
		And return the steam as it get in (cout)	
	*/
	os << fixed.toFloat();
	return (os);
}