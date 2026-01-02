#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#define GREEN   "\033[32m"

class WrongCat : public WrongAnimal
{
	private:

	public:
	/* Default Constructor */
		WrongCat( void );
	/* Copy Costructor */
		WrongCat(const WrongCat& other);
	/* Assigment Operator */
		WrongCat& operator=(const WrongCat& other);
	/* Destructor */
		~WrongCat( void );
	/* Overriding */
	void makeSound( void ) const ;
};

#endif
