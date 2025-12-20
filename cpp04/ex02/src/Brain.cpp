#include "../incl/Brain.hpp"

Brain::Brain( void ){
	std::cout << GRAY << "Brain Constructor called" << RESET << std::endl;
}

Brain::Brain( const Brain &other)
{
	for (size_t i = 0; i < 100; i++){
		this->ideas[i] = other.ideas[i];
	}
	std::cout << GRAY << "Brain Copy Constructor called" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if(this != &other)
	{
		for (size_t i = 0; i < 100; i++){
		this->ideas[i] = other.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain( void ){
	std::cout << GRAY << "Brain Destructor called" << RESET << std::endl;
}
