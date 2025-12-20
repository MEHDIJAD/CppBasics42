#include "../incl/Cat.hpp"

/* Default Costructor */
Cat::Cat( void ) : Animal() {
	this->attr = new Brain();
	SetType("Cat");
	std::cout <<  GREEN <<  this->type << RESET << " Constructor called" << std::endl; 
}

/* Copy Costructor */
Cat::Cat(const Cat &other) : Animal(other){
	this->attr = new Brain(*other.attr);
	std::cout <<  GREEN <<  this->type << RESET << " Deep Copy created✔️" << std::endl; 
}

/* Assigment Operator */
Cat &Cat::operator=(const Cat &other){
	if(this != &other){
		Animal::operator=(other);
		if (this->attr != NULL){
			delete this->attr;
		}
		this->attr = new Brain(*other.attr);
	}
	return (*this);
}

/* Destructor */
Cat::~Cat ( void ){
	delete this->attr;
	std::cout <<  GREEN <<  "Cat " << RESET << "Destructor called" << std::endl;	
}

void Cat::makeSound( void ) const {
	std::cout << GREEN << "Cat Say MEOW MEOW🐱🐱" << std::endl;
}
