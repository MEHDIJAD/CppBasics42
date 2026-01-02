#include "../incl/Cat.hpp"

/**
 * @brief Default constructor for Cat.
 */
Cat::Cat( void ) /*: Animal() is hidden but still happens! */ {

	this->type = "Cat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
}

/**
 * @brief Copy constructor for Cat.
 * @param other The other Cat object to copy.
 */
Cat::Cat(const Cat &other) : Animal(other){
	std::cout << GREEN << this->getType() << RESET << "Copy constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Cat.
 * @param other The other Cat object to assign from.
 * @return A reference to the current Cat object.
 */
Cat &Cat::operator=(const Cat &other){
	if(this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

/**
 * @brief Destructor for Cat.
 */
Cat::~Cat ( void ){
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
}

/**
 * @brief Makes the cat sound.
 */
void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
