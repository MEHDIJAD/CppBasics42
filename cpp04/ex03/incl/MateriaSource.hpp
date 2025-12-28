#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP


#include "IMateriaSource.hpp"

#define GRAY  "\033[90m"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *learnInventory[4];
	public:
		MateriaSource( void );
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);	
		~MateriaSource();
		
		void learnMateria(AMateria *lsrc);
		AMateria* createMateria(std::string const & type);
};

#endif