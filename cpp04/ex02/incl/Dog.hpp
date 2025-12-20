#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define BLUE    "\033[34m"

class Dog : public Animal
{
	private:
		/*! @brief
		When Dog is created, the pointer @param attr is empty.
		We must call new Brain() to actually create the Brain object in memory and tell the pointer where it is.
		Variable is Type name -> Automatic memory.
		Variable is Type* name -> arrow$ Manual memory (You must use new).
		*/
		Brain *attr;

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
