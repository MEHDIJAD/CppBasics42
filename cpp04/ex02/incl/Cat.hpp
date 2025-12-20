#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#define GREEN   "\033[32m"

class Cat : public Animal
{
	private:
		Brain *attr;
	public:
	/* Default Constructor */
		Cat( void );
	/* Copy Costructor */
		Cat(const Cat& other);
	/* Assigment Operator */
		Cat& operator=(const Cat& other);
	/* Destructor */
		~Cat( void );

	/* Overriding */
	void makeSound( void ) const ;
};

#endif
