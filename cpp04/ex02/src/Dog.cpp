#include "../incl/Dog.hpp"
#include "../incl/Animal.hpp"

/* Default Costructor */
Dog::Dog( void ) : Animal(){
	SetType("Dog");
	std::cout <<  BLUE <<  this->type << RESET << " Constructor called" << std::endl; 
	this->attr = new (Brain); /* Allocates memory */
}

/* Copy Costructor */
Dog::Dog(const Dog &other) : Animal(other){

	std::cout <<  BLUE <<  this->type << RESET << " Copy Costructor called ⮞ Deep Copy created✔️" << std::endl; 
	// this->attr = other.attr; //! The WRONG Way (just copy the address)
	this->attr = new Brain(*other.attr);
	// 1. "new Brain" creates a new separate memory block
    // 2. "(*other.attr)" passes the VALUES inside the other dog's brain
    //    to the Brain copy constructor you wrote earlier.
}

/* Assigment Operator */
Dog &Dog::operator=(const Dog &other){
	std::cout <<  BLUE <<  this->type << RESET << " Assigment Operator called ⮞ Deep Copy created✔️" << std::endl; 
	if(this != &other){
		Animal::operator=(other);
		if (this->attr != NULL){
			// Clean up the OLD brain (Crucial!)
			delete this->attr;
		}
		// Create a NEW brain (Deep Copy)
		// This calls the Brain Copy Constructor
		this->attr = new Brain(*other.attr);
	}
	return (*this);
}

/* Destructor */
Dog::~Dog ( void ){
	std::cout <<  BLUE <<  "Dog " << RESET << "Destructor called" << std::endl;	
	delete  this->attr; /* Clean UP */
}

void Dog::makeSound( void ) const 
{
	std::cout << BLUE << "Dog Say BARK BARK🐶🐶" << std::endl;	
}

