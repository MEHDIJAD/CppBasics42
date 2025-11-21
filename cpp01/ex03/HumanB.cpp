#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB( void ) {
    // We can do this because 
    //the pointer of Weapon can be NULL
}

HumanB::HumanB(std::string name){
    this->name = name;
    this->weaponPtr = NULL;
}

void HumanB::setWeapon(Weapon &Weapon){
    this->weaponPtr = &Weapon;
}

void HumanB::attack( void ){
    std::cout << this->name
    << " attacks with their "
    << this->weaponPtr->getType()
    << std::endl;
}

HumanB::~HumanB( void ){

}