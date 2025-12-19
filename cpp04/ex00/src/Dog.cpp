#include "../incl/Dog.hpp"
#include "../incl/Animal.hpp"

/* Default Costructor */
Dog::Dog( void ) : Animal(){
	SetType("Dog");
	std::cout <<  BLUE <<  this->type << RESET << " Constructor called" << std::endl; 
}

/* Copy Costructor */
Dog::Dog(const Dog &other) : Animal(other){
	std::cout <<  BLUE <<  this->type << RESET << " Constructor called" << std::endl; 
}

/* Assigment Operator */
Dog &Dog::operator=(const Dog &other){
	if(this != &other){
		Animal::operator=(other);
	}
	return (*this);
}

/* Destructor */
Dog::~Dog ( void ){
	std::cout <<  BLUE <<  "Dog " << RESET << "Destructor called" << std::endl;	
}

void Dog::makeSound( void ) const 
{
	std::cout << BLUE << "Dog Say BARK BARK🐶🐶" << std::endl;	
}

