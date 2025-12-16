#include "../incl/FragTrap.hpp"
#include <iostream>

// Default Constructor
FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << CYAN << "FragTrap" << RESET << " Default Constructor called" << std::endl;
}

// Parameterized Constructor
FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	this->_HitPoint = 100;
	this->_EnergyPoint = 100;
	this->_AttackDamage = 30;
	std::cout << CYAN << "FragTrap" << RESET << " " << this->getName() << " Constructor called" << std::endl;
}

// Copy Constructor
FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
	std::cout << CYAN << "FragTrap" << RESET << " Copy Constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap( void ) {
	std::cout << CYAN << "FragTrap" << RESET << " " << this->getName() << " Destructor called" << std::endl;
}

// Assignment Operator
FragTrap &FragTrap::operator=( const FragTrap &other ) {
	ClapTrap::operator=(other);
	std::cout << CYAN << "FragTrap" << RESET << " Assignment Operator called" << std::endl;
	return *this;
}

// Attack function
void FragTrap::attack( const std::string& target ) {
	if (this->_HitPoint == 0 || this->_EnergyPoint == 0)
	{
		std::cout << RED << "FragTrap" << RESET << " " << this->getName()
		<< RED << " can't attack, not enough hit points or energy points left!"
		<< RESET << std::endl;
		return;
	}
	this->_EnergyPoint--;
	std::cout << CYAN << "FragTrap" << RESET << " " << this->getName()
	<< " attacks " << target
	<< ", causing " <<  this->_AttackDamage << " points of damage!"
	<< std::endl;
}

// High Fives Guys function
void FragTrap::highFivesGuys( void ) {
	std::cout << CYAN << "FragTrap" << RESET << " " << this->getName() << " requests a positive high five!" << std::endl;
}
