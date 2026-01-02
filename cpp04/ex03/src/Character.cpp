#include "../incl/Character.hpp"

/**
 * @brief Default constructor.
 */
Character::Character( void ) : Name("Unnamed")
{
	for (size_t i = 0; i < 4; i++){ /*! @note empty upon construction */
		this->inventory[i] = NULL;
	}
	std::cout << YELLOW << "Character Default Constructor called" << RESET << std::endl;
}

/**
 * @brief Constructs a Character object with a given name.
 * @param name The name of the character.
 */
Character::Character(std::string const &name) : Name(name)
{
	for (size_t i = 0; i < 4; i++){
		this->inventory[i] = NULL; /*! @note empty upon construction */
	}
	std::cout << YELLOW << "Character " << RESET << this->Name
	<< " Constructor called" << std::endl;
}

/**
 * @brief Copy constructor for Character.
 * @param other The other Character object to copy.
 */
Character::Character(const Character &other)
{
	this->Name = other.getName();
	
	for (size_t i = 0; i < 4; i++){
		if (other.inventory[i] != NULL){
			this->inventory[i] = other.inventory[i]->clone();
		}
		else{
			this->inventory[i] = NULL;
		}
	}
	std::cout << YELLOW << "Character " << RESET << this->Name
	<< " Deep Copy Constructor called" << std::endl;
}

/**
 * @brief Assignment operator for Character.
 * @param other The other Character object to assign from.
 * @return A reference to the current Character object.
 */
Character &Character::operator=(const Character &other)
{
	if (this != &other) {
		this->Name = other.getName();
		
		for (int i = 0; i < 4; i++) {
			if (this->inventory[i] != NULL) {
				delete this->inventory[i];
				this->inventory[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++) {
			if (other.inventory[i] != NULL) {
				this->inventory[i] = other.inventory[i]->clone();
			} else {
				this->inventory[i] = NULL;
			}
		}
	}
	return *this;
}

/**
 * @brief Destructor for Character.
 */
Character::~Character( void )
{
	/*! @note (from subject):
	Of course, the Materias must be deleted when a Character is destroyed.*/
	for (size_t i = 0; i < 4; i++){
		if (this->inventory[i] != NULL){
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
	std::cout << YELLOW << "Character " << RESET << this->Name
	<< " Destructor called" << std::endl;
}

/**
 * @brief Returns the name of the character.
 * @return A constant reference to the name of the character.
 */
std::string const &Character::getName() const{
	return (this->Name);
}

/**
 * @brief Equips a materia to the character.
 * @param m The materia to equip.
 */
void Character::equip(AMateria *m)
{
	if (!m){
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == m){
			std::cerr  << RED << "Error: This materia is already equipped!" << std::endl;
			return;
		}
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL){
			this->inventory[i] = m;
			std::cout << "Equipped " << m->getType()
			<< " in slot " << i << std::endl;
			return ;
		}
	}
	std::cerr << RED << "Inventory is full. Could not equip "
	<< m->getType() << std::endl;
	delete m;
	/*! @brief We need delete m in equip because if the inventory is full, 
	the AMateria* m (which was dynamically allocated with new) cannot be stored. 
	If it's not deleted, the pointer to that memory is lost, resulting in a memory leak.

	If equip rejects it and doesn't delete it, that object leaks immediately.

	If you changed it to "Caller Responsibility," 
	We would have to change the return type of equip from void to bool (to tell the caller it failed). 
	Since the subject mandates void equip(AMateria* m), we must delete it inside,
	*/
}

/**
 * @brief Unequips a materia from the character.
 * @param idx The index of the materia to unequip.
 */
void Character::unequip(int idx){
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
		/*! @note (From subject):
		The unequip() member function must NOT delete the Materia!
		*/
		this->inventory[idx] = NULL;
		std::cout << "Unequipped slot " << idx << std::endl;
	}
	
}

/**
 * @brief Uses a materia on a target character.
 * @param indx The index of the materia to use.
 * @param target The character to use the materia on.
 */
void Character::use(int indx, ICharacter &target)
{
	if (indx >= 0 && indx < 4 && this->inventory[indx] != NULL){
		this->inventory[indx]->use(target);
	}
}
