#include "../incl/DiamondTrap.hpp"
#include <iostream>

/* Default Constructor */
DiamondTrap::DiamondTrap( void )
{
	std::cout << "DiamondTrap Default constructed" << std::endl;
}

/* Paramertize Costructor */
DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), // Initialize Grandparent with the Suffix Name
FragTrap(Name), ScavTrap(Name)
{
	this->_Name = Name; // Initialize the Shadow variable with the real Name

	this->_HitPoint = FragTrap::_HitPoint;
    this->_EnergyPoint = ScavTrap::_EnergyPoint;
    this->_AttackDamage = FragTrap::_AttackDamage;
	std::cout << "DiamondTrap constructed" << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My Diamond name is: " << this->_Name << std::endl;
    std::cout << "My ClapTrap name is: " << ClapTrap::_Name << std::endl;
}
