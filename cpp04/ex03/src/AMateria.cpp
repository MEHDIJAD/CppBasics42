#include "../incl/AMateria.hpp"

//? do we need to add This
// AMateria::AMateria( void ) : type(""){

// }

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Constructor called" << std::endl;
}

std::string const &AMateria::getType() const {
    return (this->type);   
}

AMateria::AMateria(const AMateria &other){
    this->type = other.type;
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Copy Constructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    (void)other; // While assigning a Materia to another, copying the type doesn't make sense
    return (*this);
}

AMateria::~AMateria ( void ){
    std::cout << MAGENTA << "AMateria " << RESET << this->type
    << " Destructor called" << std::endl;   
}

void AMateria::use(ICharacter &target){
	(void)target;
}


