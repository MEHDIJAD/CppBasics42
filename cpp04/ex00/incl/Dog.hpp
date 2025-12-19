#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

#define BLUE    "\033[34m"

class Dog : public Animal
{
	private:
		

	public:
	/* Default Coostructor */
		Dog( void );
	/* Copy Costructor */
		Dog(const Dog& other);
	/* Assigment Operator */
		Dog& operator=(const Dog& other);
	/* Destructor */
		~Dog();
	/* Overriding */
	void makeSound( void ) const ;
};

#endif
