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
    // for (size_t i = 0; i < 4; i++){
    //     if (this->inventory[i] != NULL){
    //         delete this->inventory[i];
    //         this->inventory[i] = NULL;
    //     }
    // }
    std::cout << YELLOW << "Character " << RESET << this->Name
    << " Destructor called" << std::endl;
}

std::string const &Character::getName() const{
    return (this->Name);
}
