#include "../incl/DiamondTrap.hpp"
#include <iostream>

/* Default Constructor */
DiamondTrap::DiamondTrap( void )
{
	std::cout << GRAY << "DiamondTrap "
	<<  RESET<< "Default constructed"
	<< std::endl;
}

/* Paramertize Costructor */
DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name"), // Initialize Grandparent with the Suffix Name
FragTrap(Name), ScavTrap(Name)
{
	this->_Name = Name; // Initialize the Shadow variable with the real Name
	std::cout << "this->" << this->_Name << std::endl;
	// WE CAN'T do this
	// this->_HitPoint = FragTrap::_HitPoint;
    // this->_EnergyPoint = ScavTrap::_EnergyPoint;
    // this->_AttackDamage = FragTrap::_AttackDamage;
	this->_HitPoint = 100;      // FragTrap requirement
    this->_EnergyPoint = 50;    // ScavTrap requirement
    this->_AttackDamage = 30;   // FragTrap requirement

	std::cout << GRAY << "DiamondTrap "
	<<  RESET<< "Parametrize constructed"
	<< std::endl;
	// std::cout << "HP: " << this->_HitPoint << std::endl;
	// std::cout << "EP: " << this->_EnergyPoint << std::endl;
	// std::cout << "AP: "<< this->_AttackDamage << std::endl;
}

/* Copy Costructor */
DiamondTrap::DiamondTrap(const DiamondTrap &other) : 
ClapTrap(other), FragTrap(other), ScavTrap(other) 
{
	std::cout << GRAY << "FragTrap" << RESET << " Copy Constructor called" << std::endl;
}

/* Assigment Operator */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
	FragTrap::operator=(other);
	ScavTrap::operator=(other);
	if (this != &other){
		this->_Name = other._Name;
	}
	std::cout << GRAY << "FragTrap" << RESET << " Assignment Operator called" << std::endl;
	return (*this);
}

/* Destructor */
DiamondTrap::~DiamondTrap( void )
{
	std::cout << GRAY << "DiamondTrap" << RESET << " " << this->_Name << " Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout  << GRAY << "My Diamond name is: " << this->_Name << std::endl;
    std::cout <<  BLUE << "My ClapTrap name is: " << ClapTrap::_Name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
