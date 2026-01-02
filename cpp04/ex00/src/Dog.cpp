#include "../incl/Dog.hpp"
#include "../incl/Animal.hpp"

/**
 * @brief Default constructor for Dog.
 */
Dog::Dog( void ) {
	this->type = "Dog";
	std::cout <<  BLUE <<  this->type << RESET << " Constructor called" << std::endl; 
}

/**
 * @brief Copy constructor for Dog.
 * @param other The other Dog object to copy.
 */
Dog::Dog(const Dog &other) : Animal(other){
	std::cout <<  BLUE <<  this->type << RESET << " Copy Constructor called" << std::endl; 
}

/**
 * @brief Assignment operator for Dog.
 * @param other The other Dog object to assign from.
 * @return A reference to the current Dog object.
 */
Dog &Dog::operator=(const Dog &other){
	if(this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

/**
 * @brief Destructor for Dog.
 */
Dog::~Dog ( void ){
	std::cout <<  BLUE <<  "Dog " << RESET << "Destructor called" << std::endl;	
}

/**
 * @brief Makes the dog sound.
 */
void Dog::makeSound( void ) const 
{
	std::cout << BLUE << "Dog Say BARK BARK🐶🐶" << std::endl;	
}
