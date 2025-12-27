#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

#define YELLOW  "\033[33m"

class Character : public ICharacter
{
    private:
        std::string Name;
        AMateria *inventory[4];
    public:
        Character( void );
        Character(std::string  const &name);
        Character (const Character &other);
        Character &operator=(const Character &other);
        ~Character( void );

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        // void use(int idx, ICharacter& target); 
};

#endif