#include "../incl/MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
	for (size_t i = 0; i < 4; i++){
		this->learnInventory[i] = NULL; // (emplty)
	}
	
	std::cout << GRAY <<  "MateriaSource" << RESET
	<< " Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	std::cout << GRAY <<  "MateriaSource" << RESET
	<< " Copy Constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (other.learnInventory[i] != NULL){
			this->learnInventory[i] = other.learnInventory[i]->clone();
		}
		else{
			this->learnInventory[i] = NULL;
		}
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		// 2. CLEAN UP
		for (size_t i = 0; i < 4; i++)
		{
			if (this->learnInventory[i] != NULL){
				delete this->learnInventory[i];
				this->learnInventory[i] = NULL;
			}
		}
		
		// 3. DEEP COPY
		for (int i = 0; i < 4; i++) 
		{
			if (other.learnInventory[i] != NULL) {
				// Create a NEW copy (clone), don't just copy the pointer!
				this->learnInventory[i] = other.learnInventory[i]->clone();
			} 
			else {
				this->learnInventory[i] = NULL;      
			}
		}
	}
	return *this;
}

MateriaSource::~MateriaSource( void )
{
	std::cout << GRAY <<  "MateriaSource" << RESET
	<< " Destructor called" << std::endl;

	for (size_t i = 0; i < 4; i++) {
        if (this->learnInventory[i] != NULL) {
            delete this->learnInventory[i];
            this->learnInventory[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria *lsrc)
{
	if (lsrc == NULL){
		return;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (this->learnInventory[i] == NULL) {
			this->learnInventory[i] = lsrc;
			return;
		}
	}
	std::cout << "Did not find empty SLOT !" << std::endl;
	delete lsrc; 
	/*!  @brief learnMateria takes ownership. 
	if We reject the item, it might never get deleted (memory leak).
	So we Clean Here.
	*/
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->learnInventory[i] != NULL
			&& this->learnInventory[i]->getType() == type)
		{		
			return this->learnInventory[i]->clone();
		}
	}
	return 0;
}


