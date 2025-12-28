#include "../incl/Character.hpp"

Character::Character(std::string const &name) : Name(name)
{
    for (size_t i = 0; i < 4; i++){
        this->inventory[i] = NULL; // (empty)
    }
    std::cout << YELLOW << "Character " << RESET << this->Name
    << " Constructor called" << std::endl;
}


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
    std::cout << YELLOW << "Character" << RESET << this->Name
    << " Deep Copy Constructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other) {
        
        // 2. CLEAN UP: Delete currently stored clones (Just like the destructor!)
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }

        // 3. DEEP COPY: Create new clones from the other object
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i] != NULL) {
                // Create a NEW copy (clone), don't just copy the pointer!
                this->inventory[i] = other.inventory[i]->clone();
            } else {
                this->inventory[i] = NULL;
            }
        }
    }
    return *this;
}

Character::~Character( void )
{
    for (size_t i = 0; i < 4; i++){
        if (this->inventory[i] != NULL){
            delete this->inventory[i];
            this->inventory[i] = NULL;
        }
    }
    std::cout << YELLOW << "Character " << RESET << this->Name
    << " Destructor called" << std::endl;
}

std::string const &Character::getName() const{
    return (this->Name);
}

void Character::equip(AMateria *m)
{
	if (m == NULL){
		return;
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
	std::cout << "Inventory is full. Could not equip "
	<< m->getType() << std::endl;	
}

void Character::unequip(int idx){
	if (idx >= 0 && idx < 4 && this->inventory[idx] != NULL) {
        // Just remove it from the inventory. 
        // DO NOT DELETE IT HERE.
        this->inventory[idx] = NULL; 
        std::cout << "Unequipped slot " << idx << std::endl;
    }
	
}

void Character::use(int indx, ICharacter &target)
{
	if (indx >= 0 && indx < 4 && this->inventory[indx] != NULL){
		this->inventory[indx]->use(target);
	}
}
