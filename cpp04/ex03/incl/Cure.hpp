#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#define GREEN   "\033[32m"

class Cure : public AMateria
{
    private:
    
    public:
        Cure( void );
        Cure(const Cure &other);
        Cure &operator=(const Cure &other);
        ~Cure( void );

        AMateria *clone() const;
		void use(ICharacter& target);
        
};

#endif