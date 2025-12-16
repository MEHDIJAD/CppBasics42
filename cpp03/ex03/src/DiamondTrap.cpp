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

	// WE CAN'T do this
	// this->_HitPoint = FragTrap::_HitPoint;
    // this->_EnergyPoint = ScavTrap::_EnergyPoint;
    // this->_AttackDamage = FragTrap::_AttackDamage;
	this->_HitPoint = 100;      // FragTrap requirement
    this->_EnergyPoint = 50;    // ScavTrap requirement
    this->_AttackDamage = 30;   // FragTrap requirement

	std::cout << "HP: " << this->_HitPoint << std::endl;
	std::cout << "EP: " << this->_EnergyPoint << std::endl;
	std::cout << "AP: "<< this->_AttackDamage << std::endl;
	std::cout << "DiamondTrap constructed" << std::endl;
}

/* Destructor */
DiamondTrap::~DiamondTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "My Diamond name is: " << this->_Name << std::endl;
    std::cout << "My ClapTrap name is: " << ClapTrap::_Name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
