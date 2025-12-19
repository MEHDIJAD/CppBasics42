#include "../incl/Cat.hpp"

/* Default Costructor */
Cat::Cat( void ) : Animal() {

	SetType("Cat");
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
}

/* Copy Costructor */
Cat::Cat(const Cat &other) : Animal(other){

}

/* Assigment Operator */
Cat &Cat::operator=(const Cat &other){
	if(this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

/* Destructor */
Cat::~Cat ( void ){
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
}

void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
