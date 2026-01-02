#include "../incl/Animal.hpp"

/**
 * @brief Default constructor for Animal.
 * @note (from subject):
 * the Animal class can be left empty or set to the value of your choice.
 */
Animal::Animal(void) : type("")
{
	std::cout << YELLOW << "Animal " << RESET << "Constructor called"
	<< std::endl;
}

/**
 * @brief Constructs an Animal object with a given type.
 * @param type The type of the animal.
 */
Animal::Animal(std::string &type) : type(type)
{
	std::cout << YELLOW << "Animal " << this->type << RESET
	<< " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Animal.
 * @param other The other Animal object to copy.
 */
Animal::Animal(const Animal &other)
{
	this->type = other.getType();
	std::cout << YELLOW << "Animal " << this->type << RESET
	<< " Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Animal.
 * @param other The other Animal object to assign from.
 * @return A reference to the current Animal object.
 */
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other){
		this->type = other.getType();
	}
	return (*this);
}

/**
 * @brief Destructor for Animal.
 */
Animal::~Animal(void)
{
	std::cout << YELLOW << "Animal " << this->type << RESET
	<< " Destructor called" << std::endl;
}

/**
 * @brief Returns the type of the animal.
 * @return The type of the animal.
 */
std::string const &Animal::getType(void) const {
	return (this->type);
}


// void Animal::setType(std::string type){
// 	this->type = type;
// }


/**
 * @brief Makes the animal sound.
 */
void Animal::makeSound(void) const 
{
	std::cout << YELLOW << "Animal Say What 🧠🧠 " << std::endl;
}
