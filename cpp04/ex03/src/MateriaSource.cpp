#include "../incl/MateriaSource.hpp"

/**
 * @brief Default constructor for MateriaSource.
 */
MateriaSource::MateriaSource( void )
{
	for (size_t i = 0; i < 4; i++){
		this->learnInventory[i] = NULL; // (emplty)
	}
	std::cout << GRAY <<  "MateriaSource" << RESET
	<< " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for MateriaSource.
 * @param other The other MateriaSource object to copy.
 */
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

/**
 * @brief Assignment operator for MateriaSource.
 * @param other The other MateriaSource object to assign from.
 * @return A reference to the current MateriaSource object.
 */
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
				// Create a NEW copy (clone)
				this->learnInventory[i] = other.learnInventory[i]->clone();
			} 
			else {
				this->learnInventory[i] = NULL;      
			}
		}
	}
	return *this;
}

/**
 * @brief Destructor for MateriaSource.
 */
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

/**
 * @brief Learns a materia.
 * @param lsrc The materia to learn.
 */
void MateriaSource::learnMateria(AMateria *m)
{
	if (!m){
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (this->learnInventory[i] == m) {
			std::cerr  << RED << "Error: MateriaSource already knows this specific template!" << std::endl;
			return;
		}
	}

	for (size_t i = 0; i < 4; i++)
	{
		if (this->learnInventory[i] == NULL) {
			this->learnInventory[i] = m;
			return;
		}
	}
	std::cerr << "Source Full: Deleting input" << std::endl;
	delete m; 
	/*!  @brief learnMateria takes ownership. 
	if We reject the item, it might never get deleted (memory leak).
	So we Clean Here.
	*/
}

/**
 * @brief Creates a materia.
 * @param type The type of the materia to create.
 * @return A pointer to the created materia.
 */
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
