#include <iostream>
#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon): name(name), weapon(weapon) {

}

/* We Can't DO THIS: construct without inialize/creat in inistialize list for refence variable */
// HumanA::HumanA(std::string name, Weapon& weapon){

// 	this->name = name;
// 	this->weapon = weapon;
// }



HumanA::~HumanA( void ){
    /* Empty */
}

void HumanA::attack(void)
{
    /* <name> attacks with their <weapon type> */

    std::cout << this->name 
    << " attacks with their "
    << this->weapon.getType() 
    << std::endl;
}
