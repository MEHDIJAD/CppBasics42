#include "../incl/Cure.hpp"
#include "../incl/ICharacter.hpp"

Cure::Cure( void ) : AMateria("cure"){
    std::cout << GREEN << this->type << RESET
    << " Constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other){
    std::cout << GREEN << this->type << RESET
    << " Copy Constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other){
    if (this != &other){
        AMateria::operator=(other);
    }
    return *this;
}

Cure::~Cure( void ){
    std::cout << GREEN << this->type << RESET
    << " Destructor called" << std::endl;
}

AMateria *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals "
	<< RESET << target.getName() << GREEN << "’s wounds *"
	<< std::endl;
}
