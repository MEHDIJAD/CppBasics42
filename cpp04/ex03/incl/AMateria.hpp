#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define MAGENTA "\033[35m"

class ICharacter; //* Forward declaration

class AMateria
{
	protected:
		std::string type;
	public:
		// AMateria( void );
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria( void );
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
