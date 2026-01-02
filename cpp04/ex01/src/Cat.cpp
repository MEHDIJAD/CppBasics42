#include "../incl/Cat.hpp"

/**
 * @brief Default constructor for Cat.
 */
Cat::Cat( void ) : attr(NULL) {
	this->type = "Cat";
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
	this->attr = new Brain();
}

/**
 * @brief Copy constructor for Cat.
 * @param other The other Cat object to copy.
 */
Cat::Cat(const Cat &other) : Animal(other){
	std::cout <<  GREEN <<  this->type << RESET << " Deep Copy created✔️" << std::endl; 
	this->attr = new Brain(*other.attr);
}

/**
 * @brief Assignment operator for Cat.
 * @param other The other Cat object to assign from.
 * @return A reference to the current Cat object.
 */
Cat &Cat::operator=(const Cat &other){
	if(this != &other){
		Animal::operator=(other);
		delete this->attr;
		if(other.attr)
			this->attr = new Brain(*other.attr);
		else
			this->attr = NULL;
	}
	return (*this);
}

/**
 * @brief Destructor for Cat.
 */
Cat::~Cat ( void ){
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
	delete this->attr;
}

/**
 * @brief Makes the cat sound.
 */
void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
