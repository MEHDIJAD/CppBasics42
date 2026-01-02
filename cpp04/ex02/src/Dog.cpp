#include "../incl/Dog.hpp"
#include "../incl/Animal.hpp"

/**
 * @brief Default constructor for Dog.
 */
Dog::Dog( void ) : attr(NULL) {
	this->type = "Dog";
	std::cout <<  BLUE <<  this->type << RESET << " Constructor called" << std::endl; 
	this->attr = new (Brain); /* Allocates memory */
}

/**
 * @brief Copy constructor for Dog.
 * @param other The other Dog object to copy.
 */
Dog::Dog(const Dog &other) : Animal(other){

	std::cout <<  BLUE <<  this->type << RESET << " Copy Costructor called ⮞ Deep Copy created✔️" << std::endl; 
	// this->attr = other.attr; //! The WRONG Way (just copy the address)
	this->attr = new Brain(*other.attr);
	// 1. "new Brain" creates a new separate memory block
    // 2. "(*other.attr)" passes the VALUES inside the other dog's brain
    //    to the Brain copy constructor you wrote earlier.
}

/**
 * @brief Assignment operator for Dog.
 * @param other The other Dog object to assign from.
 * @return A reference to the current Dog object.
 */
Dog &Dog::operator=(const Dog &other){
	std::cout <<  BLUE <<  this->type << RESET << " Assigment Operator called ⮞ Deep Copy created✔️" << std::endl; 
	if(this != &other){
		Animal::operator=(other);
		delete this->attr;
		if(other.attr)
			this->attr = new Brain(*other.attr); /* Deep Copy */
		else
			this->attr = NULL;
	}
	return (*this);
}

/**
 * @brief Destructor for Dog.
 */
Dog::~Dog ( void ){
	std::cout <<  BLUE <<  "Dog " << RESET << "Destructor called" << std::endl;	
	delete  this->attr; /* Clean UP */
}

/**
 * @brief Makes the dog sound.
 */
void Dog::makeSound( void ) const 
{
	std::cout << BLUE << "Dog Say BARK BARK🐶🐶" << std::endl;	
}

void Dog::setIdea(int i, std::string idea) {
    this->attr->setIdea(i, idea); // Assumes you added setIdea to Brain
}

std::string Dog::getIdea(int i) const {
    return this->attr->getIdea(i); // Assumes you added getIdea to Brain
}
