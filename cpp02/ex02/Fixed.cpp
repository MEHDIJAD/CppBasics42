#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::FRACTIONAL_BITS = 8;

/* Default Constructor */
Fixed::Fixed(void) : _fixValue(0) {
  // std::cout << "Default constructor called" << std::endl;
}

/* Parametrize Constructor for INT */
Fixed::Fixed(const int decimal) {
  // std::cout << "Int constructor called" << std::endl;
  this->_fixValue = decimal << Fixed::FRACTIONAL_BITS;

  // This is like decimal * 2^FRACTION_BITS
  // -> this->fixedPoint = decimal * pow(2, Fixed::FRACTIONAL_BITS);

  // OR this->fixedPoint = decimal * 256;
}

/* Parametrize Constructor for FLOAT */
Fixed::Fixed(const float real) {
  // std::cout << "Float constructor called" << std::endl;
  this->_fixValue = roundf(real * (1 << Fixed::FRACTIONAL_BITS));
  // This is like round(real * 2^FRACTION_BITS OR * 252)
  // 1 << 8 EVAL to 256
}

/* Copy Constructor */
Fixed::Fixed(const Fixed &other) /* : fixedPoint(other.getRawBits())  */
{
  // std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

/* Assignment Operator */
Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    _fixValue = other.getRawBits();
  }
  return (*this);
}

/* Destructor */
Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

/* Set func */
void Fixed::setRawBits(int const raw) { this->_fixValue = raw; }

/* Get func */
int Fixed::getRawBits(void) const { return (this->_fixValue); }

float Fixed::toFloat(void) const {
  /*! @brief  This is like doing:
          floatPoint = fixedPoint / 2^8(256)
          and we cast it to float so we do not lose the fraction
  */
  return ((float)this->_fixValue / (1 << Fixed::FRACTIONAL_BITS));
}

int Fixed::toInt(void) const
{
    /*! @brief we do need to / 2^8(256) we can just
            shift back to the original number
    */
    return (this->_fixValue / (1 << Fixed::FRACTIONAL_BITS));
    // OR return (this->fixedPoint / pow(2, Fixed::FRACTIONAL_BITS));
    // OR return (this->fixedPoint / 256);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  /*! @brief Here we overlod the inserrtion operator
          And return the steam as it get in (cout)
  */
  os << fixed.toFloat();
  return (os);
}

/* Comparison operators */
bool Fixed::operator>(const Fixed &other) const {
  return this->_fixValue > other._fixValue;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->_fixValue < other._fixValue;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->_fixValue >= other._fixValue;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->_fixValue <= other._fixValue;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->_fixValue == other._fixValue;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->_fixValue != other._fixValue;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
  Fixed result;
  result.setRawBits(this->_fixValue + other._fixValue);
  return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
  Fixed result;
  result.setRawBits(this->_fixValue - other._fixValue);
  return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
  Fixed result;
  /* 	1. We Cast to long long to prevent overflow
      2. Multiply
      3. Shift the result RIGHT (>>) by FRACTIONAL_BITS to fix the scaling
          2^8 x 2^8 = 2^16 (WRONG) so we shift back to the right (/2^8)
          4. Assign to result
      */
  result.setRawBits(
      (static_cast<long long>(this->_fixValue) * other._fixValue) >>
      Fixed::FRACTIONAL_BITS);
  return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
  Fixed result;
  if (other._fixValue == 0) {
    std::cerr << "Error: Division by zero!" << std::endl;
    return Fixed();
  }
  result.setRawBits(
      (static_cast<long long>(this->_fixValue) << FRACTIONAL_BITS) /
      other._fixValue);
  return result;
}

Fixed &Fixed::operator++(void) /* Pre-increment */
{
  this->_fixValue++;
  return (*this);
}

Fixed Fixed::operator++(int) /* Post-increment */
{
  Fixed copy = *this;
  this->_fixValue++;
  return (copy);
}

Fixed &Fixed::operator--(void) /* Pre-decrement */
{
  this->_fixValue--;
  return (*this);
}

Fixed Fixed::operator--(int) /* Post-decrement */
{
  Fixed copy = *this;
  this->_fixValue--;
  return (copy);
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  // This calls your comparison operator (operator<)!
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
