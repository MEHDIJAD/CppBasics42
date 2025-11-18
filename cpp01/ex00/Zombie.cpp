#include "Zombie.hpp"

/* Constructor */
Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Costructor a Zombie: " << this->name << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Destructor */
Zombie::~Zombie(void)
{
    std::cout  << "Destructor a Zombie: " << this->name << std::endl;
}