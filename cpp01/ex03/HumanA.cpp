#include <iostream>
#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon): 
name(name), weapon(weapon) {

}

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
