#include "../incl/Animal.hpp"

/**
 * @brief Default constructor for Animal.
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
    this->type = other.type;
    std::cout << YELLOW << "Animal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Animal.
 * @param other The other Animal object to assign from.
 * @return A reference to the current Animal object.
 */
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other) {
        this->type = other.type;
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
std::string const &Animal::getType(void) const
{
    return (this->type);
}


//* We do not need this 
//* pure virtual, it doesn't need a default implementation anymore (though C++ allows it in special cases
// void Animal::makeSound(void) const 
// {
//     std::cout << YELLOW << "Animal Say What 🧠🧠 " << std::endl;
// }
