#include "../incl/Animal.hpp"

/* Default Costructor */
Animal::Animal(void) : type("")
{
    std::cout << YELLOW << "Animal " << RESET << "Constructor called"
              << std::endl;
}

/* Paramertize Constructor */
Animal::Animal(std::string type) : type(type)
{
    std::cout << YELLOW << "Animal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/* Copy Costructor */
Animal::Animal(const Animal &other)
{
    this->type = other.type;
    std::cout << YELLOW << "Animal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/* Assigment Operator */
Animal &Animal::operator=(const Animal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

/* Destructor */
Animal::~Animal(void)
{
    std::cout << YELLOW << "Animal " << this->type << RESET
              << " Destructor called" << std::endl;
}

void Animal::SetType(const std::string type)
{
    this->type = type;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const 
{
    std::cout << YELLOW << "Animal Say What 🧠🧠 " << std::endl;
}
