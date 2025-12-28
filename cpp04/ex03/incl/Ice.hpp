#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

#define BLUE    "\033[34m"

class Ice : public AMateria
{
    private:

    public:
        Ice( void );
        Ice(const Ice &other);
        Ice &operator=(const Ice &other);
        ~Ice( void );

        AMateria *clone() const;
		void use(ICharacter& target);
        
};

#endif