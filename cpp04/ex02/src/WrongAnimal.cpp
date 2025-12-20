#include "../incl/WrongAnimal.hpp"

/* Default Costructor */
WrongAnimal::WrongAnimal(void)
{
    std::cout << YELLOW << "WrongAnimal " << RESET << "Constructor called"
              << std::endl;
}

/* Paramertize Constructor */
WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/* Copy Costructor */
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
              << " Constructor called" << std::endl;
}

/* Assigment Operator */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

/* Destructor */
WrongAnimal::~WrongAnimal(void)
{
    std::cout << YELLOW << "WrongAnimal " << this->type << RESET
              << " Destructor called" << std::endl;
}

void WrongAnimal::SetType(const std::string type)
{
    this->type = type;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound( void ) const {
    std::cout << RED << "WrongAnimal Say WRONG SOUND ❌" << std::endl;
}