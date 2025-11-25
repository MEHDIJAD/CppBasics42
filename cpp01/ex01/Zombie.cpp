#include "Zombie.hpp"


/* Default Constructor */
Zombie::Zombie(void){
	std::cout << "Costruct a Zombie" << std::endl;
}
/* Paramitrize Constructor */
Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Costruct a Zombie: " << this->name << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
}

/* Destructor */
Zombie::~Zombie(void)
{
    std::cout  << "Destruct a Zombie: " << this->name << std::endl;
}
